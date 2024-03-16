#include "GameMath.h"
#include <algorithm>

namespace rogue_engine {

float GameMath::speed(float speed, float acc, float elapsed) {
  if (acc != 0) {
    speed += acc * elapsed;
  }
  return speed;
}

float GameMath::gate(float min, float value, float max) {
  return std::clamp(value, min, max);
}
} // namespace rogue_engine
