#pragma once

#include "Shader.h"
#include "FrameBuffer.h"
#include "Mesh.h"

namespace Renderer {

  // ----- Commands ----- //
  void clear();
  void clearColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
  void clearColor(float r, float g, float b, float a);
  void setViewport(int32_t x, int32_t y, float width, float height);

  // ----- Renderer ----- //
  class Renderer
  {
  public:
    Renderer();

    virtual void drawIndexed(const Mesh& mesh, const Shader& shader) const = 0;
    virtual void drawCount(
      const std::unique_ptr<Mesh>& mesh,
      const std::unique_ptr<Shader>& shader,
      uint32_t first,
      uint32_t count) const = 0;

    // inline const std::shared_ptr<FrameBuffer>& getFrameBuffer() const { return m_frameBuffer; }

    static Renderer* create();
  protected:
    // std::shared_ptr<FrameBuffer> m_frameBuffer;
  };

}