#include "../headers/ResourceManager.h"

namespace rogue_engine {
TextureCache ResourceManager::_textureCache;

GLTexture ResourceManager::getTexture(std::string texturePath) {
  return _textureCache.getTexture(texturePath);
}
} // namespace rogue_engine
