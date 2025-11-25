#pragma once

#include "renderer/Renderer.h"

namespace Renderer {

  class OpenGLRenderer : public Renderer
  {
  public:
    static void clear();
    static void clearColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
    static void clearColor(float r, float g, float b, float a);
    static void setViewport(int32_t x, int32_t y, float width, float height);  

    void drawIndexed(const Mesh& mesh, const Shader& shader) const override;
    void drawCount(
      const std::unique_ptr<Mesh>& mesh,
      const std::unique_ptr<Shader>& shader,
      uint32_t first,
      uint32_t count) const override;
  };

}