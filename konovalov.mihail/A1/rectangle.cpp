#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t &rectangle) :
        rectangle_(rectangle)
{
  assert(rectangle_.width_ > 0.0);
  assert(rectangle_.height_ > 0.0);
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos_.x_ += dx;
  rectangle_.pos_.y_ += dy;
}

double Rectangle::getArea() const
{
  return rectangle_.width_ * rectangle_.height_;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.pos_ = point;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}
