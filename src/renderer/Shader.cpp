#include "Corepch.h"

#include "Shader.h"
#include "renderer/RendererAPI.h"

#include "platform/OpenGL/OpenGLShader.h"

namespace Renderer {

  ComputeShader* ComputeShader::create(const std::filesystem::path& path)
  {
    switch (RendererAPI::getAPI())
    {
    case OpenGL:
      return new OpenGLComputeShader(path);
    default:
      return nullptr;
    }
  }

  GraphicsShader* GraphicsShader::create(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath)
  {
    switch (RendererAPI::getAPI())
    {
    case OpenGL:
      return new OpenGLGraphicsShader(vertexPath, fragmentPath);
    default:
      return nullptr;
    }
  }
  
}