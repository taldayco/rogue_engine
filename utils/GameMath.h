#pragma once
#include <glm/glm.hpp>

class GameMath {
public:
  static float speed(float speed, float acc, float elapsed);
  static float gate(float min, float value, float max);
};
