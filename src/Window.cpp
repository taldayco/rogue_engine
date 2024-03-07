#include "../headers/Window.h"
#include "../headers/Errors.h"
#include <SDL2/SDL_video.h>

namespace rogue_engine {
Window::Window() {}

Window::~Window() {}

int Window::create(std::string windowName, int screenWidth, int screenHeight,
                   unsigned int currentFlags) {

  Uint32 flags = SDL_WINDOW_OPENGL;

  if (currentFlags & INVISIBLE) {
    flags |= SDL_WINDOW_HIDDEN;
  }
  if (currentFlags & FULLSCREEN) {
    flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
  }
  if (currentFlags & BORDERLESS) {
    flags |= SDL_WINDOW_BORDERLESS;
  }
  // set openGL up
  _sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screenWidth,
                                screenHeight, SDL_WINDOW_OPENGL);

  // more errorchecking
  if (_sdlWindow == nullptr) {
    fatalError("SDL Window Could Not Be Created");
  }

  SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
  if (glContext == nullptr) {
    fatalError("SDL_GL Context could not be created.");
  }

  GLenum error = glewInit();
  if (error != GLEW_OK) {
    fatalError("Could Not Init Glew");
  }

  // check the openGL version
  std::printf("*** openGL Version: %s ***", glGetString(GL_VERSION));

  // sets default color when glClear is called
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

  // enable vsync
  SDL_GL_SetSwapInterval(1);

  return 0;
};

void Window::swapBuffer() {
  // swap our buffer before drawing
  SDL_GL_SwapWindow(_sdlWindow);
};
} // namespace rogue_engine
