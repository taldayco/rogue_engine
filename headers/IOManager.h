#pragma once
#include <string>
#include <vector>

namespace rogue_engine {
class IOManager {
public:
  static bool readFileToBuffer(std::string filePath,
                               std::vector<unsigned char> &buffer);
};
} // namespace rogue_engine
