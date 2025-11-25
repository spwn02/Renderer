#include "Texture.h"

#include "RendererAPI.h"
#include "platform/OpenGL/OpenGLTexture.h"

namespace Renderer {

  Texture* Texture::create(int32_t width, int32_t height, const void* data)
  {
    switch (RendererAPI::getAPI())
    {
    case OpenGL:
      return new OpenGLTexture(width, height, data);
    default:
      return nullptr;
    }
  }

}