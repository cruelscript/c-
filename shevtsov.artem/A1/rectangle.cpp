#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t& center):
  width_(width),
  height_(height),
  center_(center)
{
  assert (width > 0.0);
  assert (height > 0.0);
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void Rectangle::move(double shiftX, double shiftY)
{
  move({center_.x + shiftX, center_.y + shiftY});
}

const char* Rectangle::printName() const
{
  return "Rectangle";
}
