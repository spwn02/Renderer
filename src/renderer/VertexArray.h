#pragma once

#include <vector>
#include "Buffer.h"
#include "Shader.h"

namespace Renderer {

  class VertexArray
  {
  public:
    virtual ~VertexArray() {}

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    static VertexArray* create();
  protected:
    uint32_t m_rendererID;
  };

}