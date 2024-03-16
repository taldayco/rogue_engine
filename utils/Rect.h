#pragma once
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <vector>

namespace rogue_engine {
class Rect {
public:
  int width() const;
  int height() const;
  int square() const;

  Rect();
  Rect(int left, int top, int right, int bottom);

  Rect &set(int left, int top, int right, int bottom);
  Rect &setPos(int x, int y);
  Rect &shift(int x, int y);
  Rect &resize(int w, int h);

  bool isEmpty() const;
  Rect &setEmpty();

  Rect intersect(const Rect &other) const;
  Rect unite(const Rect &other) const;

  Rect &unite(int x, int y);
  Rect &unite(const glm::ivec2 &point);

  bool inside(const glm::ivec2 &point) const;
  glm::ivec2 center() const;

  Rect shrink(int d) const;
  Rect shrink() const;
  Rect scale(int d) const;

  // retrieves all of the points (coordinates) inside the rectangle
  std::vector<glm::ivec2> getPoints() const;

  ~Rect();

private:
  int _left;
  int _top;
  int _right;
  int _bottom;
};

} // namespace rogue_engine
