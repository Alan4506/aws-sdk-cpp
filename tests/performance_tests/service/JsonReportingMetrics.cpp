#include "JsonReportingMetrics.h"
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/DateTime.h>
#include <fstream>

JsonReportingMetrics::JsonReportingMetrics() {}

JsonReportingMetrics::~JsonReportingMetrics() {
    DumpJson();
}

JsonReportingMetricsFactory::~JsonReportingMetricsFactory() {}

// And the factory method
Aws::UniquePtr<Aws::Monitoring::MonitoringInterface> JsonReportingMetricsFactory::CreateMonitoringInstance() const {
    return Aws::MakeUnique<JsonReportingMetrics>("JsonReportingMetrics");
}

void JsonReportingMetrics::AddMetric(const Aws::String& serviceName, const Aws::String& requestName,
                                     const Aws::Monitoring::CoreMetricsCollection& metricsFromCore, bool success) const {
    std::lock_guard<std::mutex> lock(m_mutex);

    double durationMs = 0.0;
    Aws::String latencyKey = Aws::Monitoring::GetHttpClientMetricNameByType(Aws::Monitoring::HttpClientMetricsType::RequestLatency);

    auto it = metricsFromCore.httpClientMetrics.find(latencyKey);
    if (it != metricsFromCore.httpClientMetrics.end()) {
        durationMs = static_cast<double>(it->second);
    }

    RequestMetric metric;
    metric.name = Aws::Utils::StringUtils::ToLower(serviceName.c_str()) +
                  Aws::String(".") +
                  Aws::Utils::StringUtils::ToLower(requestName.c_str());
    metric.description = Aws::String("Time to complete ") + metric.name + Aws::String(" operation");
    metric.unit = "Milliseconds";
    metric.date = Aws::Utils::DateTime::CurrentTimeMillis() / 1000;
    metric.measurements.push_back(durationMs);

    metric.dimensions.push_back(std::make_pair(Aws::String("Service"), serviceName));
    metric.dimensions.push_back(std::make_pair(Aws::String("Operation"), requestName));
    metric.publishToCloudWatch = true;

    m_metrics.push_back(metric);
}

void JsonReportingMetrics::AggregateMetrics() const {
    // Create finalized metrics from the aggregated data
    for (const auto& pair : m_aggregatedMetrics) {
        RequestMetric metric;
        metric.name = pair.first;
        metric.description = Aws::String("Time to complete ") + pair.first + Aws::String(" operation");
        metric.unit = "Milliseconds";
        metric.date = Aws::Utils::DateTime::CurrentTimeMillis() / 1000;
        metric.measurements = pair.second;
        metric.publishToCloudWatch = true;

        // Add dimensions (e.g., AWS service name)
        size_t dotPos = pair.first.find('.');
        if (dotPos != Aws::String::npos) {
            Aws::String service = pair.first.substr(0, dotPos);
            metric.dimensions.push_back(std::make_pair(Aws::String("Service"), service));
        }

        m_metrics.push_back(metric);
    }
}

// Interface Overrides
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
}

void JsonReportingMetrics::OnRequestRetry(const Aws::String&, const Aws::String&, const std::shared_ptr<const Aws::Http::HttpRequest>&,
                                          void*) const {
}

void JsonReportingMetrics::DumpJson() const {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_metrics.empty()) {
        return;
    }

    Aws::Utils::Json::JsonValue root;

    // Add required top-level fields
    root.WithString("productId", "AWS SDK for C++");
    root.WithString("sdkVersion", "1.0.0");
    root.WithString("commitId", "unknown");   // Consider getting this from CI/CD env variable

    Aws::Utils::Array<Aws::Utils::Json::JsonValue> results(m_metrics.size());

    for (size_t i = 0; i < m_metrics.size(); ++i) {
        Aws::Utils::Json::JsonValue metric;
        metric.WithString("name", m_metrics[i].name);
        metric.WithString("description", m_metrics[i].description);
        metric.WithString("unit", m_metrics[i].unit);
        metric.WithInt64("date", m_metrics[i].date);

        // Add dimensions if present
        if (!m_metrics[i].dimensions.empty()) {
            Aws::Utils::Array<Aws::Utils::Json::JsonValue> dimensionsArray(m_metrics[i].dimensions.size());
            for (size_t j = 0; j < m_metrics[i].dimensions.size(); ++j) {
                Aws::Utils::Json::JsonValue dimension;
                dimension.WithString("name", m_metrics[i].dimensions[j].first);
                dimension.WithString("value", m_metrics[i].dimensions[j].second);
                dimensionsArray[j] = std::move(dimension);
            }
            metric.WithArray("dimensions", std::move(dimensionsArray));
        }

        // Create a JSON array for measurements
        Aws::Utils::Array<Aws::Utils::Json::JsonValue> measurementsArray(m_metrics[i].measurements.size());
        for (size_t j = 0; j < m_metrics[i].measurements.size(); ++j) {
            Aws::Utils::Json::JsonValue measurementValue;
            measurementValue.AsDouble(m_metrics[i].measurements[j]);
            measurementsArray[j] = std::move(measurementValue);
        }
        metric.WithArray("measurements", std::move(measurementsArray));

        results[i] = std::move(metric);
    }
    root.WithArray("results", std::move(results));

    // Write to stdout so the performance test runner can capture it
    std::cout << root.View().WriteReadable() << std::endl;

    // Save to file
    std::ofstream outFile("perf-results.json");
    if (outFile.is_open()) {
        outFile << root.View().WriteReadable();
    }
}