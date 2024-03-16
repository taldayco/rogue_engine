#include "RectF.h"

namespace rogue_engine {
RectF::RectF() : _left(0), _top(0), _right(0), _bottom(0) {}
RectF::RectF(float left, float top, float right, float bottom)
    : _left(left), _top(top), _right(right), _bottom(bottom) {}

RectF::~RectF() {}

float RectF::width() const { return _right - _left; }
float RectF::height() const { return _bottom - _top; }
float RectF::square() const { return width() * height(); }

// Sets the coordinates of the RectFangle
RectF &RectF::set(float left, float top, float right, float bottom) {
  _left = left;
  _top = top;
  _right = right;
  _bottom = bottom;
  return *this;
}
// Sets the position of the RectFangle
RectF &RectF::setPos(float x, float y) {
  float width = this->width();
  float height = this->height();
  _left = x;
  _top = y;
  _right = x + width;
  _bottom = y + height;
  return *this;
}
// shift RectFangle by a given amound in the x and y diRectFion
RectF &RectF::shift(float x, float y) {
  _top += y;
  _bottom += y;
  _left += x;
  _right += x;
  return *this;
}
// resize RectFangle
RectF &RectF::resize(float w, float h) {
  _right = _left + w;
  _bottom = _top + h;
  return *this;
}
// This function returns true if the RectFangle is empty,
// (has zero or negative area) and false otherwise.
bool RectF::isEmpty() const { return _right <= _left || _bottom <= _top; };
// reset all the coordinates of the RectFangle to zero, effectively making it
// an empty RectFangle with no width or height
RectF &RectF::setEmpty() {
  _left = _right = _top = _bottom = 0;
  return *this;
};
// finds the overlapping region between two RectFangles and returns a new
// RectFangle representing that floatersection. if the RectFangles do not
// overlap, the resulting RectFangle will have zero area, indicating an empty
// intersection.
RectF RectF::intersect(const RectF &other) const {
  RectF result;
  result._left = std::max(_left, other._left);
  result._right = std::min(_right, other._right);
  result._top = std::max(_top, other._top);
  result._bottom = std::min(_bottom, other._bottom);
  return result;
}
// calculates the union of two RectFangles by finding the smallest RectFangle
// that contains both input RectFangles without modifying the original
// RectFangles and returns it as a new RectF object.
RectF RectF::unite(const RectF &other) const {
  RectF result;
  result._left = std::min(_left, other._left);
  result._right = std::max(_right, other._right);
  result._top = std::min(_top, other._top);
  result._bottom = std::max(_bottom, other._bottom);
  return result;
}

// ensures that the RectFangle contains the specified pofloat(x, y) by expanding
// the RectFangle as necessary. If the RectFangle is empty, it sets the
// RectFangle to be a single pofloatat (x, y). Otherwise, it adjusts the edges
// of the RectFangle to include the pofloatwhile maintaining the RectFangle's
// integrity.
RectF &RectF::unite(float x, float y) {
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
RectF &RectF::unite(const glm::ivec2 &point) { return unite(point.x, point.y); }

// determines whether a given pofloatis inside the RectFangle defined by its
// four coordinates.
bool RectF::inside(const glm::ivec2 &point) const {
  return point.x >= _left && point.x < _right && point.y >= _top &&
         point.y < _bottom;
}

// return center of the RectFangle
glm::ivec2 RectF::center() const {
  return glm::ivec2((_left + _right) / 2, (_top + _bottom) / 2);
}

// creates and returns a new RectFangle that is a shrunken version of the
// original RectFangle.
RectF RectF::shrink(float d) const {
  return RectF(_left + d, _top + d, _right - d, _bottom - d);
}

// provides a convenient way to shrink RectFangles by a default amount
RectF RectF::shrink() const { return shrink(1); }

// creates and returns a new RectFangle that is a scaled version of the
// original RectFangle.
RectF RectF::scale(float d) const {
  return RectF(_left * d, _top * d, _right * d, _bottom * d);
}
} // namespace rogue_engine
