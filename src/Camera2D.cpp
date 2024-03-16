#include "../headers/Camera2D.h"
#include <glm/fwd.hpp>

namespace rogue_engine {
Camera2D::Camera2D()
    : _position(0.0f, 0.0f), _cameraMatrix(1.0f), _scale(1.0f),
      _orthoMatrix(1.0f), _needsUpdate(true), _screenWidth(500),
      _screenHeight(500) {}
Camera2D::~Camera2D() {}

void Camera2D::init(int screenWidth, int screenHeight) {
  _screenWidth = screenWidth;
  _screenHeight = screenHeight;
  _orthoMatrix =
      glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
}

void Camera2D::update() {
  if (_needsUpdate) {

    // Camera Translation
    glm::vec3 translate(-_position.x, -_position.y, 0.0f);
    _cameraMatrix = glm::translate(_orthoMatrix, translate);

    // Camera Scale
    glm::vec3 scale(_scale, _scale, 0.0f);
    _cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;
    _needsUpdate = false;
  }
}
glm::vec2 Camera2D::convertScreenToWorld(glm::vec2 screenCoords) {
  // invert y direction
  screenCoords.y = _screenHeight - screenCoords.y;
  // 0 becomes center and
  screenCoords -= glm::vec2(_screenWidth / 2, _screenHeight / 2);
  // scale coordinates
  screenCoords /= _scale;
  // translate camera position
  screenCoords += _position;

  return screenCoords;
};
} // namespace rogue_engine
