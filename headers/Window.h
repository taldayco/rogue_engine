#pragma once
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>

namespace rogue_engine {
enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

class Window {
public:
  Window();
  ~Window();

  int create(std::string windowName, int screenWidth, int screenHeight,
             unsigned int currentFlags);

  void swapBuffer();

  int getScreenWidth() { return _screenWidth; }
  int getScreenHeight() { return _screenHeight; }

private:
  SDL_Window *_sdlWindow;
  int _screenWidth, _screenHeight;
};
} // namespace rogue_engine
