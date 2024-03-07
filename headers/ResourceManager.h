#pragma once
#include "TextureCache.h"
#include <string>

namespace rogue_engine {
class ResourceManager {
public:
  static GLTexture getTexture(std::string texturePath);

private:
  static TextureCache _textureCache;
};
} // namespace rogue_engine
