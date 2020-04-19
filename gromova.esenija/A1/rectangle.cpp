#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double height, const double width, const point_t& centre) :
  height_(height),
  width_(width),
  centre_(centre)
{
  assert(height_ > 0);
  assert(width_ > 0);
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { height_, width_, centre_ };
}

void Rectangle::move(const point_t& point)
{
  centre_ = point;
}

void Rectangle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
