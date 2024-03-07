#include "../headers/IOManager.h"
#include <fstream>

namespace rogue_engine {
bool IOManager::readFileToBuffer(std::string filePath,
                                 std::vector<unsigned char> &buffer) {
  std::ifstream file(filePath, std::ios::binary);
  if (file.fail()) {
    perror(filePath.c_str());
    return false;
  }

  // seek to the end of file
  file.seekg(0, std::ios::end);

  // get the file size in bytes
  int fileSize = file.tellg();
  file.seekg(0, std::ios::beg);

  // Ignore any file headers that my be present.
  fileSize -= file.tellg();

  buffer.resize(fileSize);
  file.read((char *)&(buffer[0]), fileSize);
  file.close();

  return true;
};
} // namespace rogue_engine
