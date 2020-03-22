#include "rectangle.hpp"

#include <cassert>
#include "base-types.hpp"
#include "shape.hpp"

Rectangle::Rectangle(const point_t &center, const double &w, const double &h) :
  center_(center),
  width_(w),
  height_(h)
{
  assert((w > 0.0) && (h > 0.0));
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, center_ };
}

void Rectangle::move(const point_t &point)
{
  center_ = point;
}

void Rectangle::move(const double &xOffset, const double &yOffset)
{
  center_.x += xOffset;
  center_.y += yOffset;
}
