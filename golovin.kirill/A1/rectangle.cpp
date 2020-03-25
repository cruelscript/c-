#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t &center, double width, double height) :
  Shape(center),
  width_(width),
  height_(height) {
  assert((width_ > 0.0) && (height_ > 0.0));
}

double Rectangle::getArea() const {
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const {
  return {width_, height_, center_};
}
