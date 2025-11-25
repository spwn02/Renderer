#pragma once

#include <glm/glm.hpp>
#include <memory>

#include "Texture.h"
#include "Buffer.h"
#include "VertexArray.h"

#include <ranges>

namespace Renderer {

  struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
  };

  class Mesh {
    public:
      Mesh() {}
      virtual ~Mesh() {}

      virtual void bind() const = 0;
      virtual void unbind() const = 0;

      virtual void draw(const Shader& shader) = 0;

      uint32_t getCount() const { return m_EBO->getCount(); }

      static Mesh* create(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Texture*> textures);
    protected:
      // Mesh data
      std::vector<Vertex> m_vertices;
      std::vector<uint32_t> m_indices;
      std::vector<Texture*> m_textures;
      
      // Render data
      std::unique_ptr<VertexArray> m_VAO = nullptr;
      std::unique_ptr<VertexBuffer> m_VBO = nullptr;
      std::unique_ptr<IndexBuffer> m_EBO = nullptr;
    protected:
      void setupMesh();
  };

}