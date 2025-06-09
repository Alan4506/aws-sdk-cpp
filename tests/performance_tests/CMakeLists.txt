cmake_minimum_required(VERSION 3.13)

# ── 1. Find nlohmann_json ───────────────────────────────────────────
include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)

# ── 2. Declare the performance_tests "project" (provides PROJECT_LIBS, etc.) ───────
add_project(performance_tests
    "A suite of simple AWS C++ SDK performance tests"
    aws-cpp-sdk-core
    aws-cpp-sdk-s3
)

# ── 3. Build the monitoring implementation into a static library ────────────────────────────────
#
#   [THE FIX] By explicitly making this a STATIC library, its code will be compiled
#   directly into the executables, which resolves the linking error.
#
add_library(json_metrics STATIC
    service/JsonReportingMetrics.cpp
    service/JsonReportingMetrics.h
)

# 【FIX】Add the AWS core header search path for json_metrics
# This is the key to resolving the "Cannot open include file" error.
target_include_directories(json_metrics PUBLIC
    "${PROJECT_SOURCE_DIR}/aws-cpp-sdk-core/include"
)

# Allow executables to #include "JsonReportingMetrics.h"
target_include_directories(json_metrics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/service)
# Link the core SDK + nlohmann_json
target_link_libraries(json_metrics
    PUBLIC
        aws-cpp-sdk-core
        nlohmann_json::nlohmann_json
)

# ── 4. PutObject Performance Test ────────────────────────────────────────────
add_executable(s3_put_object_perf
    service/S3PutObject.cpp
)
set_compiler_flags(s3_put_object_perf)
set_compiler_warnings(s3_put_object_perf)
target_link_libraries(s3_put_object_perf
    PRIVATE
        ${PROJECT_LIBS}
        json_metrics
)

# ── 5. GetObject Performance Test ────────────────────────────────────────────
add_executable(s3_get_object_perf
    service/S3GetObject.cpp
)
set_compiler_flags(s3_get_object_perf)
set_compiler_warnings(s3_get_object_perf)
target_link_libraries(s3_get_object_perf
    PRIVATE
        ${PROJECT_LIBS}
        json_metrics
)