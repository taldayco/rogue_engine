#include "../headers/RectF.h"

namespace rogue_engine {
Rect::Rect() : _left(0), _top(0), _right(0), _bottom(0) {}
Rect::Rect(float left, float top, float right, float bottom)
    : _left(left), _top(top), _right(right), _bottom(bottom) {}

Rect::~Rect() {}

float Rect::width() const { return _right - _left; }
float Rect::height() const { return _bottom - _top; }
float Rect::square() const { return width() * height(); }

// Sets the coordinates of the rectangle
Rect &Rect::set(float left, float top, float right, float bottom) {
  _left = left;
  _top = top;
  _right = right;
  _bottom = bottom;
  return *this;
}
// Sets the position of the rectangle
Rect &Rect::setPos(float x, float y) {
  float width = this->width();
  float height = this->height();
  _left = x;
  _top = y;
  _right = x + width;
  _bottom = y + height;
  return *this;
}
// shift rectangle by a given amound in the x and y direction
Rect &Rect::shift(float x, float y) {
  _top += y;
  _bottom += y;
  _left += x;
  _right += x;
  return *this;
}
// resize rectangle
Rect &Rect::resize(float w, float h) {
  _right = _left + w;
  _bottom = _top + h;
  return *this;
}
// This function returns true if the rectangle is empty,
// (has zero or negative area) and false otherwise.
bool Rect::isEmpty() const { return _right <= _left || _bottom <= _top; };
// reset all the coordinates of the rectangle to zero, effectively making it
// an empty rectangle with no width or height
Rect &Rect::setEmpty() {
  _left = _right = _top = _bottom = 0;
  return *this;
};
// finds the overlapping region between two rectangles and returns a new
// rectangle representing that floatersection. if the rectangles do not overlap,
// the resulting rectangle will have zero area, indicating an empty
// intersection.
Rect Rect::intersect(const Rect &other) const {
  Rect result;
  result._left = std::max(_left, other._left);
  result._right = std::min(_right, other._right);
  result._top = std::max(_top, other._top);
  result._bottom = std::min(_bottom, other._bottom);
  return result;
}
// calculates the union of two rectangles by finding the smallest rectangle
// that contains both input rectangles without modifying the original
// rectangles and returns it as a new Rect object.
Rect Rect::unite(const Rect &other) const {
  Rect result;
  result._left = std::min(_left, other._left);
  result._right = std::max(_right, other._right);
  result._top = std::min(_top, other._top);
  result._bottom = std::max(_bottom, other._bottom);
  return result;
}

// ensures that the rectangle contains the specified pofloat(x, y) by expanding
// the rectangle as necessary. If the rectangle is empty, it sets the rectangle
// to be a single pofloatat (x, y). Otherwise, it adjusts the edges of the
// rectangle to include the pofloatwhile maintaining the rectangle's integrity.
Rect &Rect::unite(float x, float y) {
  if (isEmpty()) {
    return set(x, y, x + 1, y + 1);
  } else {
    if (x < _left) {
      _left = x;
    } else if (x >= _right) {
      _right = x + 1;
    }
    if (y < _top) {
      _top = y;
    } else if (y >= _bottom) {
      _bottom = y + 1;
    }
    return *this;
  }
}
Rect &Rect::unite(const glm::ivec2 &point) { return unite(point.x, point.y); }

// determines whether a given pofloatis inside the rectangle defined by its four
// coordinates.
bool Rect::inside(const glm::ivec2 &point) const {
  return point.x >= _left && point.x < _right && point.y >= _top &&
         point.y < _bottom;
}

// return center of the rectangle
glm::ivec2 Rect::center() const {
  return glm::ivec2((_left + _right) / 2, (_top + _bottom) / 2);
}

// creates and returns a new rectangle that is a shrunken version of the
// original rectangle.
Rect Rect::shrink(float d) const {
  return Rect(_left + d, _top + d, _right - d, _bottom - d);
}

// provides a convenient way to shrink rectangles by a default amount
Rect Rect::shrink() const { return shrink(1); }

// creates and returns a new rectangle that is a scaled version of the
// original rectangle.
Rect Rect::scale(float d) const {
  return Rect(_left * d, _top * d, _right * d, _bottom * d);
}
} // namespace rogue_engine
