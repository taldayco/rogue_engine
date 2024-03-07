#include "../headers/rogue_engine.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>

namespace rogue_engine {

int init() {
  SDL_Init(SDL_INIT_EVERYTHING);

  // instead of drawing and clearing on the same Window,
  // Prevents flickering by seperating each process into its own buffer
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  return 0;
}
} // namespace rogue_engine
