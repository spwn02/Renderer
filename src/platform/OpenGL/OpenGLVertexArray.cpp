#include "Corepch.h"

#include "OpenGLVertexArray.h"

namespace Renderer {

  OpenGLVertexArray::OpenGLVertexArray()
  {
    glCreateVertexArrays(1, &m_rendererID);
  }

  OpenGLVertexArray::~OpenGLVertexArray()
  {
    glDeleteVertexArrays(1, &m_rendererID);
  }

  void OpenGLVertexArray::bind() const
  {
    glBindVertexArray(m_rendererID);
  }

  void OpenGLVertexArray::unbind() const
  {
    glBindVertexArray(0);
  }

}