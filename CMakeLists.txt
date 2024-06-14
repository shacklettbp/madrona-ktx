cmake_minimum_required(VERSION 3.26)
project(madrona_ktx)

set(CMAKE_CXX_STANDARD 17)

set(KTX_FEATURE_STATIC_LIBRARY ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/KTX-Software)
include_directories(external/KTX-Software/include)

add_library(madrona_ktx madrona_ktx.cpp)
