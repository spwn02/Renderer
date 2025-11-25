#include "OpenGLTexture.h"

#include <glad/glad.h>

namespace Renderer {

  OpenGLTexture::OpenGLTexture(int32_t width, int32_t height, const void* data)
  {
    glCreateTextures(GL_TEXTURE_2D, 1, &m_textureID);
    resize(width, height, data);
    glTextureStorage2D(m_textureID, 1, GL_RGBA, width, height);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    float borderColor[] = { 1.0f, 0.5f, 0.5f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
  }

  OpenGLTexture::~OpenGLTexture()
  {
    unbind();
    glDeleteTextures(1, &m_textureID);
  }

  void OpenGLTexture::bind() const
  {
    glBindTexture(GL_TEXTURE_2D, m_textureID);
  }

  void OpenGLTexture::unbind() const
  {
    glBindTexture(GL_TEXTURE_2D, 0);
  }

  void OpenGLTexture::resize(int32_t width, int32_t height, const void* data)
  {
    m_width = width;
    m_height = height;
    
    bind();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }

  void OpenGLTexture::uploadRgba(glm::vec2 size, std::vector<uint8_t>& rgba)
  {
    glTextureSubImage2D(m_textureID, 0, 0, 0, (GLsizei)size.x, (GLsizei)size.y, GL_RGBA, GL_UNSIGNED_BYTE, rgba.data());
  }

}