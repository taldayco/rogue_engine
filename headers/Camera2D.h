#pragma once
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace rogue_engine {

class Camera2D {
public:
  Camera2D();
  ~Camera2D();

  // sets up orthoMatrix and screen dimensions
  void init(int screenWidth, int screenHeight);
  // update cameraMatrix
  void update();

  glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);

  // setters
  void setPosition(const glm::vec2 &newPosition) {
    _position = newPosition;
    _needsUpdate = true;
  }
  void setScale(float newScale) {
    _scale = newScale;
    _needsUpdate = true;
  }

  // getters
  glm::vec2 getPosition() { return _position; }
  float getScale() { return _scale; }

  glm::mat4 getCameraMatrix() { return _cameraMatrix; }
  glm::mat4 cameraMatrix() { return _cameraMatrix; }

private:
  bool _needsUpdate;
  int _screenWidth;
  int _screenHeight;
  float _scale;
  glm::vec2 _position;
  glm::mat4 _cameraMatrix;
  glm::mat4 _orthoMatrix;
};
} // namespace rogue_engine
