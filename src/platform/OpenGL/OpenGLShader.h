#pragma once

#include "renderer/Shader.h"

namespace Renderer {

  class OpenGLComputeShader : public ComputeShader
  {
  public:
    OpenGLComputeShader(const std::filesystem::path& path);
    ~OpenGLComputeShader() override;

    void bind() const override;
    void unbind() const override;

    bool generate(const std::filesystem::path& path) override;
    void reload(const std::filesystem::path& path) override;

    virtual int32_t getUniformLocation(const std::string& name) const override;
    virtual void setUniform1f(const std::string& name, float data) const override;
    virtual void setUniform2f(const std::string& name, glm::vec2 data) const override;
    virtual void setUniform3f(const std::string& name, glm::vec3 data) const override;
    virtual void setUniform4f(const std::string& name, glm::vec4 data) const override;
    virtual void setUniform1i(const std::string& name, int32_t data) const override;
  };
  
  class OpenGLGraphicsShader : public GraphicsShader
  {
  public:
    OpenGLGraphicsShader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);
    ~OpenGLGraphicsShader() override;
    
    void bind() const override;
    void unbind() const override;
    
    bool generate(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath) override;
    virtual void reload(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath) override;
    
    virtual int32_t getUniformLocation(const std::string& name) const override;
    virtual void setUniform1f(const std::string& name, float data) const override;
    virtual void setUniform2f(const std::string& name, glm::vec2 data) const override;
    virtual void setUniform3f(const std::string& name, glm::vec3 data) const override;
    virtual void setUniform4f(const std::string& name, glm::vec4 data) const override;
    virtual void setUniform1i(const std::string& name, int32_t data) const override;
  };

}