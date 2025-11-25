#pragma once

#include "renderer/VertexArray.h"

namespace Renderer {

  class OpenGLVertexArray : public VertexArray
  {
  public:
    OpenGLVertexArray();
    virtual ~OpenGLVertexArray() override;

    virtual void bind() const override;
    virtual void unbind() const override;
  };

}