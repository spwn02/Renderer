#pragma once

#include "renderer/Mesh.h"

namespace Renderer {

  class OpenGLMesh : public Mesh
  {
  public:
    OpenGLMesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Texture*> textures);
    ~OpenGLMesh() override;

    void bind() const override;
    void unbind() const override;

    void draw(const Shader& shader) override;
  };

}