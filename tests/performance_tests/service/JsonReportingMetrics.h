#pragma once

#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include <aws/core/utils/memory/AWSMemory.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSMap.h>

#include <aws/core/monitoring/MonitoringFactory.h>
#include <aws/core/monitoring/MonitoringInterface.h>

#include <aws/core/client/AWSClient.h>
#include <aws/core/http/HttpRequest.h>
#include <aws/core/monitoring/CoreMetrics.h>

struct RequestMetric {
    Aws::String name;
    Aws::String description;
    Aws::String unit;
    int64_t date;
    Aws::Vector<double> measurements;
    Aws::Vector<std::pair<Aws::String, Aws::String>> dimensions;
    bool publishToCloudWatch;
};

class JsonReportingMetrics : public Aws::Monitoring::MonitoringInterface {
public:
    JsonReportingMetrics();
    ~JsonReportingMetrics() override;

    void* OnRequestStarted(const Aws::String& serviceName, const Aws::String& requestName,
                           const std::shared_ptr<const Aws::Http::HttpRequest>& request) const override;

    void OnRequestSucceeded(const Aws::String& serviceName, const Aws::String& requestName,
                            const std::shared_ptr<const Aws::Http::HttpRequest>& request, const Aws::Client::HttpResponseOutcome& outcome,
                            const Aws::Monitoring::CoreMetricsCollection& metricsFromCore, void* context) const override;

    void OnRequestFailed(const Aws::String& serviceName, const Aws::String& requestName,
                         const std::shared_ptr<const Aws::Http::HttpRequest>& request, const Aws::Client::HttpResponseOutcome& outcome,
                         const Aws::Monitoring::CoreMetricsCollection& metricsFromCore, void* context) const override;

    void OnRequestRetry(const Aws::String& serviceName, const Aws::String& requestName,
                        const std::shared_ptr<const Aws::Http::HttpRequest>& request, void* context) const override;

    void OnFinish(const Aws::String& serviceName, const Aws::String& requestName,
                  const std::shared_ptr<const Aws::Http::HttpRequest>& request, void* context) const override;

private:
    void AddMetric(const Aws::String& serviceName, const Aws::String& requestName,
                   const Aws::Monitoring::CoreMetricsCollection& metricsFromCore, bool success) const;
    void DumpJson() const;

    void AggregateMetrics() const;

    mutable std::mutex m_mutex;
    mutable Aws::Vector<RequestMetric> m_metrics;
    mutable Aws::Map<Aws::String, Aws::Vector<double>> m_aggregatedMetrics;
};

class JsonReportingMetricsFactory : public Aws::Monitoring::MonitoringFactory {
public:
    JsonReportingMetricsFactory() {}
    ~JsonReportingMetricsFactory() override;
    Aws::UniquePtr<Aws::Monitoring::MonitoringInterface> CreateMonitoringInstance() const override;
};