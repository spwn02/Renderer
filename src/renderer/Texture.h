#pragma once

#include <stdint.h>
#include <vector>
#include <glm/glm.hpp>

namespace Renderer {

  enum class TextureTypes : uint8_t
  {
    Null = 0, Diffuse, Specular
  };

  struct Texture
  {
  public:
    virtual ~Texture() {}

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    virtual void resize(int32_t width, int32_t height, const void* data = nullptr) = 0;
    virtual void uploadRgba(glm::vec2 size, std::vector<uint8_t>& rgba) = 0;

    static inline void putPx(std::vector<uint8_t>& px, glm::vec3 coords, glm::vec4 color)
    {
      size_t i = ((size_t)coords.y * (size_t)coords.z + (size_t)coords.x) * 4;
      px[i + 0] = (uint8_t)color.r;
      px[i + 1] = (uint8_t)color.g;
      px[i + 2] = (uint8_t)color.b;
      px[i + 3] = (uint8_t)color.a;
    }

    inline uint32_t getTextureID() { return m_textureID; }
    inline TextureTypes getType() { return m_type; }
    inline int32_t getWidth() const { return m_width; }
    inline int32_t getHeight() const { return m_height; }

    inline void setType(TextureTypes type) { m_type = type; }

    static Texture* create(int32_t width, int32_t height, const void* data = nullptr);
    static Texture* create(glm::vec2 size, const void* data = nullptr) { return create((int32_t)size.x, (int32_t)size.y, data); };
  protected:
    uint32_t m_textureID = 0;
    TextureTypes m_type = TextureTypes::Null;
    std::string m_path;
    int32_t m_width, m_height = 0;
  };

}