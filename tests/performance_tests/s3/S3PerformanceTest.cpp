/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/Aws.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UUID.h>
#include <aws/core/utils/memory/AWSMemory.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/BucketInfo.h>
#include <aws/s3/model/CreateBucketRequest.h>
#include <aws/s3/model/DataRedundancy.h>
#include <aws/s3/model/DeleteBucketRequest.h>
#include <aws/s3/model/DeleteObjectRequest.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <aws/s3/model/PutObjectRequest.h>

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "JsonReportingMetrics.h"

// Defines the configuration for a single S3 performance test case.
struct TestConfig {
  Aws::String sizeLabel;
  size_t sizeBytes;
  Aws::String bucketTypeLabel;
};

// Executes a single end-to-end S3 performance test scenario, including resource creation and cleanup.
// @param s3 An initialized S3Client instance.
// @param config The configuration for the test run, including object size and bucket type.
// @param availabilityZoneId The specific AZ required for S3 Express One Zone buckets.
// @return True if the test scenario completes successfully, false otherwise.
bool RunSingleTest(Aws::S3::S3Client& s3, const TestConfig& config, const Aws::String& availabilityZoneId) {
  std::cout << "\n--- Running Test: Size=" << config.sizeLabel << ", BucketType=" << config.bucketTypeLabel << " ---\n";
  JsonReportingMetrics::SetTestContext(config.sizeLabel, config.bucketTypeLabel);

  Aws::String bucketName;
  Aws::S3::Model::CreateBucketRequest cbr;
  Aws::String raw_uuid = static_cast<Aws::String>(Aws::Utils::UUID::RandomUUID());
  Aws::String id = Aws::Utils::StringUtils::ToLower(raw_uuid.c_str()).substr(0, 8);

  if (config.bucketTypeLabel == "s3-express") {
    bucketName = "perf-express-" + id + "--" + availabilityZoneId + "--x-s3";
    cbr.SetBucket(bucketName);
    Aws::S3::Model::CreateBucketConfiguration bucketConfig;
    bucketConfig.SetLocation(
        Aws::S3::Model::LocationInfo().WithType(Aws::S3::Model::LocationType::AvailabilityZone).WithName(availabilityZoneId));

    bucketConfig.SetBucket(Aws::S3::Model::BucketInfo()
                               .WithType(Aws::S3::Model::BucketType::Directory)
                               .WithDataRedundancy(Aws::S3::Model::DataRedundancy::SingleAvailabilityZone));

    cbr.SetCreateBucketConfiguration(bucketConfig);
  } else {
    bucketName = "perf-standard-" + id;
    cbr.SetBucket(bucketName);
  }

  auto createOutcome = s3.CreateBucket(cbr);
  if (!createOutcome.IsSuccess()) {
    std::cerr << "[ERROR] CreateBucket failed for " << bucketName << ": " << createOutcome.GetError().GetMessage() << std::endl;
    return false;
  }
  std::cout << "Bucket created: " << bucketName << std::endl;

  Aws::String payload(config.sizeBytes, 'x');
  auto stream = Aws::MakeShared<Aws::StringStream>("PerfStream");
  *stream << payload;

  Aws::S3::Model::PutObjectRequest por;
  por.WithBucket(bucketName).WithKey("test-object").SetBody(stream);
  if (!s3.PutObject(por).IsSuccess()) {
    std::cerr << "[ERROR] PutObject failed!" << std::endl;
  } else {
    std::cout << "Uploaded " << config.sizeLabel << std::endl;
  }

  Aws::S3::Model::GetObjectRequest gor;
  gor.WithBucket(bucketName).WithKey("test-object");
  if (!s3.GetObject(gor).IsSuccess()) {
    std::cerr << "[ERROR] GetObject failed!" << std::endl;
  } else {
    std::cout << "Downloaded " << config.sizeLabel << std::endl;
  }

  s3.DeleteObject(Aws::S3::Model::DeleteObjectRequest().WithBucket(bucketName).WithKey("test-object"));
  s3.DeleteBucket(Aws::S3::Model::DeleteBucketRequest().WithBucket(bucketName));
  std::cout << "Cleaned up." << std::endl;

  return true;
}

// The program runs a matrix of tests and outputs performance metrics to a JSON file.
int main(int argc, char** argv) {
  Aws::String region = "us-east-1";
  Aws::String availabilityZoneId = "use1-az4";

  for (int i = 1; i < argc; ++i) {
    Aws::String arg = argv[i];
    if (arg == "--region" && i + 1 < argc) {
      region = argv[++i];
    }
    if (arg == "--az-id" && i + 1 < argc) {
      availabilityZoneId = argv[++i];
    }
  }

  Aws::Vector<TestConfig> testMatrix = {{"8KB", 8 * 1024, "s3-standard"},    {"64KB", 64 * 1024, "s3-standard"},
                                        {"1MB", 1024 * 1024, "s3-standard"}, {"8KB", 8 * 1024, "s3-express"},
                                        {"64KB", 64 * 1024, "s3-express"},   {"1MB", 1024 * 1024, "s3-express"}};

  Aws::SDKOptions options;

  options.monitoringOptions.customizedMonitoringFactory_create_fn.push_back(
      []() { return Aws::MakeUnique<JsonReportingMetricsFactory>("JsonReportingMetricsFactory"); });

  Aws::InitAPI(options);

  {
    Aws::Client::ClientConfiguration cfg;
    cfg.region = region;
    Aws::S3::S3Client s3(cfg);

    for (const auto& config : testMatrix) {
      RunSingleTest(s3, config, availabilityZoneId);
    }
  }

  Aws::ShutdownAPI(options);
  std::cout << "\nAll tests completed. Results saved to perf-results.json" << std::endl;
  return 0;
}