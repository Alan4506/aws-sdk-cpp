/**
 * Simple perf test: create bucket -> put 64 KiB object -> delete object + bucket
 */
#include <aws/core/Aws.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UUID.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/CreateBucketConfiguration.h>
#include <aws/s3/model/CreateBucketRequest.h>
#include <aws/s3/model/DeleteBucketRequest.h>
#include <aws/s3/model/DeleteObjectRequest.h>
#include <aws/s3/model/PutObjectRequest.h>

#include <iostream>

#include "JsonReportingMetrics.h"

int main(int argc, char** argv) {
  Aws::SDKOptions options;

  options.monitoringOptions.customizedMonitoringFactory_create_fn.push_back(
      []() { return Aws::MakeUnique<JsonReportingMetricsFactory>("jsonFactory"); });

  Aws::InitAPI(options);
  {
    Aws::Client::ClientConfiguration cfg;
    if (argc > 1) cfg.region = argv[1];

    cfg.enableHttpClientTrace = true;

    Aws::S3::S3Client s3(cfg);

    // 1) bucket name
    Aws::String raw = static_cast<Aws::String>(Aws::Utils::UUID::RandomUUID());
    Aws::String id = Aws::Utils::StringUtils::ToLower(raw.c_str()).substr(10);
    Aws::String bucket = Aws::String("put-bucket-benchmark-") + id;

    // 2) create bucket
    Aws::S3::Model::CreateBucketRequest cbr;
    cbr.WithBucket(bucket);
    auto cbOutcome = s3.CreateBucket(cbr);
    if (!cbOutcome.IsSuccess()) {
      std::cerr << "[ERROR] CreateBucket: " << cbOutcome.GetError().GetMessage() << "\n";
      return 1;
    }

    // 3) put a 64KiB test object
    std::string payload(64 * 1024, 'x');
    auto stream = Aws::MakeShared<Aws::StringStream>("PerfStream");
    *stream << payload;

    // 4) PutObject
    Aws::S3::Model::PutObjectRequest por;
    por.WithBucket(bucket).WithKey("test-object").SetBody(stream);

    auto poOutcome = s3.PutObject(por);
    if (!poOutcome.IsSuccess()) {
      std::cerr << "[ERROR] PutObject: " << poOutcome.GetError().GetMessage() << "\n";
      return 1;
    }
    std::cout << "Uploaded 64 KiB to " << bucket << "/test-object\n";

    // 5) cleanup
    s3.DeleteObject(Aws::S3::Model::DeleteObjectRequest().WithBucket(bucket).WithKey("test-object"));
    s3.DeleteBucket(Aws::S3::Model::DeleteBucketRequest().WithBucket(bucket));
    std::cout << "Cleaned up\n";
  }
  Aws::ShutdownAPI(options);
  return 0;
}