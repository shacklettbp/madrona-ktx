cmake_minimum_required(VERSION 3.26)
project(madrona_ktx)

#set(CMAKE_CXX_STANDARD 17)

set(KTX_FEATURE_STATIC_LIBRARY ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/KTX-Software EXCLUDE_FROM_ALL)
target_compile_options(ktx PUBLIC "-fPIC")

target_link_libraries(ktx PUBLIC madrona_libcxx madrona_noexceptrtti)
include(CMakePrintHelpers)
cmake_print_variables(CMAKE_CURRENT_SOURCE_DIR)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/KTX-Software/include)
add_library(madrona_ktx madrona_ktx.cpp madrona_ktx.h)
target_link_libraries(madrona_ktx PUBLIC madrona_libcxx madrona_noexceptrtti ktx)
