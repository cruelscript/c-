#include "Rectangle.hpp"
#include "base-types.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t pos, const double w, const double h) :
  Shape(pos),
  width_(w),
  height_(h)
{
  assert(width_ > 0 && "Error: Width <= 0.\n");
  assert(height_ > 0 && "Error: Height <= 0.\n");
}

Rectangle::Rectangle(const double x, const double y, const double w, const double h) :
  Rectangle({x, y}, w, h)
{}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { pos_, width_, height_};
}
