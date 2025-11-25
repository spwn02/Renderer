#pragma once

#include <filesystem>
#include <stdint.h>
#include <glm/glm.hpp>

namespace Renderer {

  class Shader
  {
  public:
    virtual ~Shader() = default;
    uint32_t getHandle() { return m_handle; }

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual void setUniform1f(const std::string& name, float data) const = 0;
    virtual void setUniform2f(const std::string& name, glm::vec2 data) const = 0;
    virtual void setUniform3f(const std::string& name, glm::vec3 data) const = 0;
    virtual void setUniform4f(const std::string& name, glm::vec4 data) const = 0;
    virtual void setUniform1i(const std::string& name, int32_t data) const = 0;
    virtual int32_t getUniformLocation(const std::string& name) const = 0;
  protected:
    uint32_t m_handle = 0;
  };

  // ----------------------------------------
  //                 Shaders
  // ----------------------------------------
  class ComputeShader : public Shader
  {
  public:
    virtual bool generate(const std::filesystem::path& path) = 0;
    virtual void reload(const std::filesystem::path& path) = 0;

    static ComputeShader* create(const std::filesystem::path& path);
  };

  class GraphicsShader : public Shader
  {
  public:
    virtual bool generate(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath) = 0;
    virtual void reload(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath) = 0;

    static GraphicsShader* create(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
  };

}