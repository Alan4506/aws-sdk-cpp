#pragma once

// C++ Standard Library
#include <memory>
#include <mutex>
#include <string>
#include <vector>

/*
 * ===================================================================
 * DEFINITIVE AWS INCLUDE BLOCK
 * This combines all necessary headers in a logical order to resolve all dependencies.
 * ===================================================================
 */

// Core types that everything else depends on.
#include <aws/core/utils/memory/AWSMemory.h>      // Defines Aws::UniquePtr, Aws::MakeUnique
#include <aws/core/utils/memory/stl/AWSString.h>  // Defines Aws::String

// Base classes that we inherit from. Their full definition is required.
#include <aws/core/monitoring/MonitoringFactory.h>
#include <aws/core/monitoring/MonitoringInterface.h>

// Headers for all types used as parameters in the overridden functions.
#include <aws/core/client/AWSClient.h>        // Defines Aws::Client::HttpResponseOutcome and its dependencies
#include <aws/core/http/HttpRequest.h>        // Defines Aws::Http::HttpRequest
#include <aws/core/monitoring/CoreMetrics.h>  // Defines CoreMetricsCollection

/** A single AWS SDK request-level metric. */
struct RequestMetric {
  std::string name;
  double durationMs;
  bool success;
};

/** Captures metrics for every request made through the SDK. */
class JsonReportingMetrics : public Aws::Monitoring::MonitoringInterface, public std::enable_shared_from_this<JsonReportingMetrics> {
 public:
  JsonReportingMetrics() = default;
  ~JsonReportingMetrics() override;

  // --- Overrides ---
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

  mutable std::mutex m_mutex;
  mutable std::vector<RequestMetric> m_metrics;
};

/** Factory to be supplied via ClientConfiguration.monitoringOptions. */
class JsonReportingMetricsFactory : public Aws::Monitoring::MonitoringFactory {
 public:
  Aws::UniquePtr<Aws::Monitoring::MonitoringInterface> CreateMonitoringInstance() const override;
};