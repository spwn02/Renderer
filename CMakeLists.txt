# Configuration
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HDRS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" "Core.h" "Core.pch.h")

add_library(Core STATIC ${SRCS} ${HDRS})

# Match VS filters to directory structure on disk
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRCS} ${HDRS})

target_compile_definitions(Core PUBLIC
  CORE_DEBUG
  _CRT_SECURE_NO_WARNINGS
  NOMINMAX
  GLFW_INCLUDE_NONE
)

# Linking
if (WIN32)
  message(STATUS "Linking vendor libraries for Windows")
  target_link_libraries(Core PUBLIC
  opengl32
  )
elseif (LINUX)
find_package(X11 REQUIRED COMPONENTS Xrandr Xcursor Xi Xinerama Xxf86vm)

message(STATUS "Linking vendor libraries for Linux")
  target_link_libraries(Core PUBLIC
  dl
  pthread
  X11::X11
  X11::Xrandr
  X11::Xi
  X11::Xcursor
  X11::Xinerama
  X11::Xxf86vm
  )
else()
  message(FATAL_ERROR "Unsupported platform")
endif()

target_link_libraries(Core PUBLIC
  glad
  glfw
  glm
  spdlog
  stb
)

target_precompile_headers(Core PUBLIC "Corepch.h")

target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/core" "src" "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(vendor)