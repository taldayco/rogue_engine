#pragma once
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <vector>

namespace rogue_engine {
class RectF {
public:
  float width() const;
  float height() const;
  float square() const;

  RectF();
  RectF(float left, float top, float right, float bottom);

  RectF &set(float left, float top, float right, float bottom);
  RectF &setPos(float x, float y);
  RectF &shift(float x, float y);
  RectF &resize(float w, float h);

  bool isEmpty() const;
  RectF &setEmpty();

  RectF intersect(const RectF &other) const;
  RectF unite(const RectF &other) const;

  RectF &unite(float x, float y);
  RectF &unite(const glm::ivec2 &point);

  bool inside(const glm::ivec2 &point) const;
  glm::ivec2 center() const;

  RectF shrink(float d) const;
  RectF shrink() const;
  RectF scale(float d) const;

  ~RectF();

private:
  float _left;
  float _top;
  float _right;
  float _bottom;
};

} // namespace rogue_engine
