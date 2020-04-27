#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, const point_t& center) :
  width_(width),
  height_(height),
  center_(center)
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void Rectangle::move(const double& dX, const double& dY)
{
  center_.x += dX;
  center_.y += dY;
}
