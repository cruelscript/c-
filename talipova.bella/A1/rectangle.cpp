#include "Rectangle.hpp"
#include <cassert>
#include "base-types.hpp"

Rectangle::Rectangle(const point_t &pos, const double w, const double h) :
  pos_(pos),
  width_(w),
  height_(h)
{
  assert(width_ > 0);
  assert(height_ > 0);
}

Rectangle::Rectangle(const double x, const double y, const double w, const double h) :
  Rectangle({ x, y }, w, h)
{}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t &point)
{
  pos_ = point;
}

point_t Rectangle::getPosition() const
{
  return pos_;
};
