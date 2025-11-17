# Configuration
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project (Renderer VERSION 1.0)

set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "src/*.h")

add_library(Core STATIC ${SRCS} ${HDRS})

# Match VS filters to directory structure on disk
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRCS} ${HDRS})

target_compile_definitions(Core PUBLIC
  CORE_DEBUG
  _CRT_SECURE_NO_WARNINGS
  NOMINMAX
)

target_precompile_headers(Core PUBLIC "Corepch.h")

target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/core" "src" "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(vendor)