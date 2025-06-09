#include "JsonReportingMetrics.h"

// The .cpp file now only needs to include its own header and any implementation-specific headers.
#include <aws/core/utils/json/JsonSerializer.h>

#include <fstream>

// Destructor
JsonReportingMetrics::~JsonReportingMetrics() { DumpJson(); }

// Factory method implementation
Aws::UniquePtr<Aws::Monitoring::MonitoringInterface> JsonReportingMetricsFactory::CreateMonitoringInstance() const {
  return Aws::MakeUnique<JsonReportingMetrics>("JsonReportingMetrics");
}

// Helper function
void JsonReportingMetrics::AddMetric(const Aws::String& serviceName, const Aws::String& requestName,
                                     const Aws::Monitoring::CoreMetricsCollection& metricsFromCore, bool success) const {
  std::lock_guard<std::mutex> lock(m_mutex);

  // ======================= BEGIN DEBUGGING CODE =======================
  // This will print all available metrics to your console window.
  std::cout << "\n--- Metrics received for " << serviceName << "." << requestName << " ---" << std::endl;
  if (metricsFromCore.httpClientMetrics.empty()) {
    std::cout << "  >>>> HttpClientMetrics map is EMPTY <<<<" << std::endl;
  } else {
    std::cout << "  Available HttpClientMetrics:" << std::endl;
    for (const auto& pair : metricsFromCore.httpClientMetrics) {
      std::cout << "    - Key: \"" << pair.first << "\", Value: " << pair.second << std::endl;
    }
  }
  std::cout << "---------------------------------------------------------" << std::endl;
  // ======================== END DEBUGGING CODE ========================

  double durationMs = 0.0;
  Aws::String latencyKey = Aws::Monitoring::GetHttpClientMetricNameByType(Aws::Monitoring::HttpClientMetricsType::RequestLatency);

  // 2. 然后用这个 key 去 map 中查找
  auto it = metricsFromCore.httpClientMetrics.find(latencyKey);
  if (it != metricsFromCore.httpClientMetrics.end()) {
    durationMs = static_cast<double>(it->second);
  }

  m_metrics.push_back({serviceName + "." + requestName, durationMs, success});
}

// --- Interface Overrides ---

void* JsonReportingMetrics::OnRequestStarted(const Aws::String&, const Aws::String&,
                                             const std::shared_ptr<const Aws::Http::HttpRequest>&) const {
  return nullptr;
}

void JsonReportingMetrics::OnRequestSucceeded(const Aws::String& serviceName, const Aws::String& requestName,
                                              const std::shared_ptr<const Aws::Http::HttpRequest>&,
                                              const Aws::Client::HttpResponseOutcome& outcome,
                                              const Aws::Monitoring::CoreMetricsCollection& metricsFromCore, void*) const {
  AddMetric(serviceName, requestName, metricsFromCore, outcome.IsSuccess());
}

void JsonReportingMetrics::OnRequestFailed(const Aws::String& serviceName, const Aws::String& requestName,
                                           const std::shared_ptr<const Aws::Http::HttpRequest>&,
                                           const Aws::Client::HttpResponseOutcome& outcome,
                                           const Aws::Monitoring::CoreMetricsCollection& metricsFromCore, void*) const {
  AddMetric(serviceName, requestName, metricsFromCore, outcome.IsSuccess());
}

void JsonReportingMetrics::OnFinish(const Aws::String&, const Aws::String&, const std::shared_ptr<const Aws::Http::HttpRequest>&,
                                    void*) const {
  // No-op
}

void JsonReportingMetrics::OnRequestRetry(const Aws::String&, const Aws::String&, const std::shared_ptr<const Aws::Http::HttpRequest>&,
                                          void*) const {
  // No-op
}

void JsonReportingMetrics::DumpJson() const {
  std::lock_guard<std::mutex> lock(m_mutex);

  if (m_metrics.empty()) {
    return;
  }

  Aws::Utils::Json::JsonValue root;
  Aws::Utils::Array<Aws::Utils::Json::JsonValue> results(m_metrics.size());

  for (size_t i = 0; i < m_metrics.size(); ++i) {
    Aws::Utils::Json::JsonValue metric;
    metric.WithString("name", m_metrics[i].name);
    metric.WithDouble("durationMs", m_metrics[i].durationMs);
    metric.WithBool("success", m_metrics[i].success);
    results[i] = std::move(metric);
  }
  root.WithArray("perf-results", std::move(results));

  std::ofstream outFile("perf-results.json");
  if (outFile.is_open()) {
    outFile << root.View().WriteReadable();
  }
}