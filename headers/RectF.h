#pragma once
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <vector>

namespace rogue_engine {
class Rect {
public:
  float width() const;
  float height() const;
  float square() const;

  Rect();
  Rect(float left, float top, float right, float bottom);

  Rect &set(float left, float top, float right, float bottom);
  Rect &setPos(float x, float y);
  Rect &shift(float x, float y);
  Rect &resize(float w, float h);

  bool isEmpty() const;
  Rect &setEmpty();

  Rect intersect(const Rect &other) const;
  Rect unite(const Rect &other) const;

  Rect &unite(float x, float y);
  Rect &unite(const glm::ivec2 &point);

  bool inside(const glm::ivec2 &point) const;
  glm::ivec2 center() const;

  Rect shrink(float d) const;
  Rect shrink() const;
  Rect scale(float d) const;

  ~Rect();

private:
  float _left;
  float _top;
  float _right;
  float _bottom;
};

} // namespace rogue_engine
