cmake_minimum_required(VERSION 3.13)

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)

add_project(performance_tests
    "A suite of simple AWS C++ SDK performance tests"
    aws-cpp-sdk-core
    aws-cpp-sdk-s3
)

add_library(json_metrics STATIC
    reporting/JsonReportingMetrics.cpp 
    reporting/JsonReportingMetrics.h   
)

target_include_directories(json_metrics PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/reporting" 
)

target_link_libraries(json_metrics
    PUBLIC
    aws-cpp-sdk-core
    nlohmann_json::nlohmann_json
)

# Define the S3 performance test executable
add_executable(s3_performance_test         
    s3/S3PerformanceTest.cpp            
)

set_compiler_flags(s3_performance_test)     
set_compiler_warnings(s3_performance_test)  

target_link_libraries(s3_performance_test  
    PRIVATE
    ${PROJECT_LIBS}
    json_metrics
)