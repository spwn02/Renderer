#include "Corepch.h"

#include "OpenGLBuffer.h"

namespace Renderer {
  
  static GLenum DataTypeToOpenGLType(DataType type)
  {
    switch (type)
    {
    case DataType::Float:   return GL_FLOAT;
    case DataType::Float2:  return GL_FLOAT;
    case DataType::Float3:  return GL_FLOAT;
    case DataType::Float4:  return GL_FLOAT;
    case DataType::Mat3:    return GL_FLOAT;
    case DataType::Mat4:    return GL_FLOAT;
    case DataType::Int:     return GL_INT;
    case DataType::Int2:    return GL_INT;
    case DataType::Int3:    return GL_INT;
    case DataType::Int4:    return GL_INT;
    case DataType::Boolean:    return GL_BOOL;
    }

    Log::Assert(false, "Unknown DataType!");
    return 0;
  }

  OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
  {
    glCreateBuffers(1, &m_rendererID);
    sendData(vertices, size);
  }

  void OpenGLVertexBuffer::bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
  }

  void OpenGLVertexBuffer::unbind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void OpenGLVertexBuffer::sendData(float* vertices, uint32_t size) const
  {
    glNamedBufferData(m_rendererID, size, vertices, GL_STATIC_DRAW);
  }

  OpenGLVertexBuffer::~OpenGLVertexBuffer()
  {
    glDeleteBuffers(1, &m_rendererID);
  }

  void OpenGLVertexBuffer::updateLayout() const
  {
    Log::Assert(getLayout().getElements().size(), "Vertex buffer has no layout!");
    
    bind();

    int i = 0;

    for (const auto& elem : m_layout)
    {
      glEnableVertexAttribArray(i);
      glVertexAttribPointer(
        i,
        elem.getComponentCount(),
        DataTypeToOpenGLType(elem.type),
        elem.normalized ? GL_TRUE : GL_FALSE,
        m_layout.getStride(),
        (void*)elem.offset
      );
      i++;
    }
  }

  void OpenGLVertexBuffer::updateLayout(std::unique_ptr<Shader>& shader) const
  {
    Log::Assert(getLayout().getElements().size(), "Vertex buffer has no layout!");

    bind();

    int32_t location;

    for (const auto& elem : m_layout)
    {
      location = glGetAttribLocation(shader->getHandle(), elem.name.c_str());

      glEnableVertexAttribArray(location);
      glVertexAttribPointer(
        location,
        elem.getComponentCount(),
        DataTypeToOpenGLType(elem.type),
        elem.normalized ? GL_TRUE : GL_FALSE,
        m_layout.getStride(),
        (const void*)elem.offset
      );
    }
  }

  OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t size)
  {
    glGenBuffers(1, &m_rendererID);
    bind();
    set(indices, size);
  }

  OpenGLIndexBuffer::~OpenGLIndexBuffer()
  {
    glDeleteBuffers(1, &m_rendererID);
  }

  void OpenGLIndexBuffer::bind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
  }

  void OpenGLIndexBuffer::unbind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

  void OpenGLIndexBuffer::set(uint32_t* indices, uint32_t size) const
  {
    m_count = size / sizeof(uint32_t);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    glNamedBufferData(m_rendererID, size, indices, GL_STATIC_DRAW);
  }

}