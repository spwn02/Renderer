#include "Corepch.h"

#include "OpenGLRenderer.h"

namespace Renderer {

  void OpenGLRenderer::clear()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  void OpenGLRenderer::clearColor(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
  {
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
  }

  void OpenGLRenderer::clearColor(float r, float g, float b, float a)
  {
    glClearColor(r, g, b, a);
  }

  void OpenGLRenderer::setViewport(int32_t x, int32_t y, float width, float height)
  {
    glViewport(0, 0, (int32_t)width, (int32_t)height);
  }

  void OpenGLRenderer::drawIndexed(
    const Mesh& mesh,
    const Shader& shader) const
  {
    // Log::Assert(m_vertexArray->getIndexBuffer() != nullptr, "IndexBuffer has not been initialized!");

    // bool hasFB = m_frameBuffer->hasBuffer();
    // if (hasFB) m_frameBuffer->bind();
    shader.bind();
    mesh.bind();
    glDrawElements(GL_TRIANGLES, mesh.getCount(), GL_UNSIGNED_INT, nullptr);
    
    shader.unbind();
    mesh.unbind();
    // if (hasFB) m_frameBuffer->unbind();
  }

  void OpenGLRenderer::drawCount(
    const std::unique_ptr<Mesh>& mesh,
    const std::unique_ptr<Shader>& shader,
    uint32_t first,
    uint32_t count) const
  {
    // bool hasFB = m_frameBuffer->hasBuffer();
    // if (hasFB)
    // {
    //   m_frameBuffer->bind();
    // }
    shader->bind();
    mesh->bind();

    glDrawArrays(GL_TRIANGLES, first, count);

    shader->unbind();
    mesh->unbind();
    // if (hasFB)
    //   m_frameBuffer->unbind();
  }

}