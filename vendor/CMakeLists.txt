cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# General
find_package(OpenGL REQUIRED)

add_subdirectory(glm)
add_subdirectory(spdlog)
add_subdirectory(glfw)
target_compile_definitions(spdlog PRIVATE
  _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
  _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
)

# Glad
add_library(glad "glad/src/glad.c")
target_include_directories(glad PUBLIC "glad/include")

# stb
add_library(stb "stb/stb_image.cpp")
target_include_directories(stb PUBLIC "stb")

target_compile_definitions(Core PUBLIC
  GLFW_INCLUDE_NONE
  GLFW_PLATFORM_X11
  IMGUI_IMPL_OPENGL_LOADER_CUSTOM
)

# Linking
if (WIN32)
  message(STATUS "Linking vendor libraries for Windows")
  target_link_libraries(Core PUBLIC
  opengl32
  )
elseif (LINUX)
find_package(X11 REQUIRED)

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
  OpenGL::GL
  glad
  glfw
  glm
  spdlog
  stb
)