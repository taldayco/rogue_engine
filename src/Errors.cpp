#include "../headers/Errors.h"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>

namespace rogue_engine {
// prints error and exits game
void fatalError(std::string errorString) {
  std::cout << errorString << std::endl;
  std::cout << "Enter any key to quit...";
  int tmp;
  std::cin >> tmp;
  exit(69);
}
} // namespace rogue_engine
