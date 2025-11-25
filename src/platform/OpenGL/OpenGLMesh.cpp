#include "Corepch.h"
#include "OpenGLMesh.h"

namespace Renderer {

  OpenGLMesh::OpenGLMesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices, std::vector<Texture*> textures)
  {
    m_vertices = vertices;
    m_indices = indices;
    m_textures = textures;

    setupMesh();
  }

  OpenGLMesh::~OpenGLMesh()
  {
    
  }

  void OpenGLMesh::bind() const
  {
    m_VAO->bind();
  }
  
  void OpenGLMesh::unbind() const
  {
    m_VAO->unbind();
  }

  void OpenGLMesh::draw(const Shader& shader)
  {
    uint32_t diffuseNr = 1;
    uint32_t specularNr = 1;

    for (auto [index, tex] : std::views::enumerate(m_textures))
    {
      glActiveTexture(GL_TEXTURE0 + index); // activate proper texture unit before binding
      if (!tex) continue; // skip invalid textures
      tex->bind(); // bind the texture to the currently active texture unit
      // retrieve texture number (the N in diffuse_textureN)

      std::string number;
      std::string strType;
      TextureTypes type = tex->getType();
      switch (type)
      {
        case TextureTypes::Diffuse:
          number = std::to_string(diffuseNr++);
          strType = "diffuse";
          break;
          case TextureTypes::Specular:
          number = std::to_string(specularNr++);
          strType = "specular";
          break;
      }

      std::string name = ("texture_" + strType + number);

      shader.setUniform1i(name, index);
    }

    m_VAO->bind();
    shader.bind();
    glDrawElements(GL_TRIANGLES, m_EBO->getCount(), GL_UNSIGNED_INT, 0);
    shader.unbind();
    m_VAO->unbind();
  }

}