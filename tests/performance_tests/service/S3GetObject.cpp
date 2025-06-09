/**
 * Simple perf test: create bucket -> put 64 KiB -> get it once -> cleanup
 */
#include <aws/core/Aws.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UUID.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/CreateBucketRequest.h>
#include <aws/s3/model/DeleteBucketRequest.h>
#include <aws/s3/model/DeleteObjectRequest.h>
#include <aws/s3/model/GetObjectRequest.h>
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
    Aws::String bucket = Aws::String("get-bucket-benchmark-") + id;

    // 2) create bucket
    Aws::S3::Model::CreateBucketRequest cbr;
    cbr.WithBucket(bucket);
    if (!s3.CreateBucket(cbr).IsSuccess()) {
      std::cerr << "[ERROR] CreateBucket\n";
      return 1;
    }

    // 3) put a 64KiB test object
    std::string payload(64 * 1024, 'x');
    auto stream = Aws::MakeShared<Aws::StringStream>("PerfStream");
    *stream << payload;

    Aws::S3::Model::PutObjectRequest por;
    por.WithBucket(bucket).WithKey("test-object").SetBody(stream);
    if (!s3.PutObject(por).IsSuccess()) {
      std::cerr << "[ERROR] PutObject\n";
      return 1;
    }
    std::cout << "Uploaded 64 KiB to " << bucket << "/test-object\n";

    // 4) get object
    Aws::S3::Model::GetObjectRequest gor;
    gor.WithBucket(bucket).WithKey("test-object");

    auto goOutcome = s3.GetObject(gor);
    if (!goOutcome.IsSuccess()) {
      std::cerr << "[ERROR] GetObject: " << goOutcome.GetError().GetMessage() << "\n";
      return 1;
    }
    std::cout << "Downloaded " << goOutcome.GetResult().GetContentLength() << " bytes\n";

    // 5) cleanup
    s3.DeleteObject(Aws::S3::Model::DeleteObjectRequest().WithBucket(bucket).WithKey("test-object"));
    s3.DeleteBucket(Aws::S3::Model::DeleteBucketRequest().WithBucket(bucket));
    std::cout << "Cleaned up\n";
  }
  Aws::ShutdownAPI(options);
  return 0;
}