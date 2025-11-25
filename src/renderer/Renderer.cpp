#include "Corepch.h"

#include "Renderer.h"
#include "RendererAPI.h"

#include "platform/OpenGL/OpenGLRenderer.h"

namespace Renderer {

  void clear()
  {
    switch (RendererAPI::getAPI())
    {
      case OpenGL:
        return OpenGLRenderer::clear();
      default:
        return;
    }
  }

  void clearColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
  {
    switch (RendererAPI::getAPI())
    {
      case OpenGL:
        return OpenGLRenderer::clearColor(r, g, b, a);
      default:
        return;
    }
  }

  void clearColor(float r, float g, float b, float a)
  {
    switch (RendererAPI::getAPI())
    {
      case OpenGL:
        return OpenGLRenderer::clearColor(r, g, b, a);
      default:
        return;
    }
  }

  void setViewport(int32_t x, int32_t y, float width, float height)
  {
    switch (RendererAPI::getAPI())
    {
      case OpenGL:
        return OpenGLRenderer::setViewport(x, y, width, height);
      default:
        return;
    }
  }

  Renderer::Renderer()
  {
    // m_frameBuffer.reset(FrameBuffer::create());
  }

  Renderer* Renderer::create()
  {
    switch (RendererAPI::getAPI())
    {
      case OpenGL:
        return new OpenGLRenderer();
      default:
        return nullptr;
    }
  }

}