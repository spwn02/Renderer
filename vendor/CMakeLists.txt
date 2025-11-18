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
