#pragma once
#include "../headers/GLTexture.h"
#include <string>

// loads images into GLTextures
namespace rogue_engine {
class ImageLoader {
public:
  static GLTexture loadPNG(std::string filePath);
};
} // namespace rogue_engine
