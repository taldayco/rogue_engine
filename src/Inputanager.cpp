#include "../headers/InputManager.h"

namespace rogue_engine {

InputManager::InputManager() : _mouseCoords(0.0f) {}

InputManager::~InputManager() {}

void InputManager::pressKey(unsigned int keyID) { _keymap[keyID] = true; }

void InputManager::releaseKey(unsigned int keyID) { _keymap[keyID] = false; }
void InputManager::setMouseCoords(float x, float y) {
  _mouseCoords.x = x;
  _mouseCoords.y = y;
};

bool InputManager::isKeyPressed(unsigned int keyID) {
  auto it = _keymap.find(keyID);
  if (it != _keymap.end()) {
    return it->second;
  } else {
    return false;
  }
}

} // namespace rogue_engine
