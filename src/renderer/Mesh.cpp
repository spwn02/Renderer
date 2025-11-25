#include "Corepch.h"
#include "Mesh.h"

#include "RendererAPI.h"
#include "platform/OpenGL/OpenGLMesh.h"

namespace Renderer
{
  Mesh* Mesh::create(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Texture*> textures)
  {
    switch (RendererAPI::getAPI())
    {
      case OpenGL:
        return new OpenGLMesh(vertices, indices, textures);
      default:
        return nullptr;
    }
  }

  void Mesh::setupMesh()
  {
    m_VAO.reset(VertexArray::create());
    m_VAO->bind();

    if (!m_vertices.empty())
      m_VBO.reset(VertexBuffer::create((float*)m_vertices.data(), m_vertices.size() * sizeof(Vertex)));

    if (!m_indices.empty())
      m_EBO.reset(IndexBuffer::create(m_indices.data(), m_indices.size() * sizeof(uint32_t)));

    BufferLayout layout = {
      { "position", DataType::Float3 },
      { "normals", DataType::Float3 },
      { "texcoords", DataType::Float2 }
    };

    if (m_VBO)
    {
      m_VBO->setLayout(layout);
      m_VBO->updateLayout();
    }
  }
}