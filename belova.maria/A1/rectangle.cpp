#include "rectangle.hpp"
#include <cassert>
#include <ostream>

Rectangle::Rectangle(const point_t &center, const double w, const double h) :
  center_(center),
  width_(w),
  height_(h)
{
  assert(width_ > 0.0);
  assert(height_ > 0.0);
}

void Rectangle::move(const point_t &center)
{
  center_ = center;
}

void Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { center_, width_, height_ };
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::showData(std::ostream& out) const
{
  out << "Rectangle:\nCenter: " << '(' << center_.x << ", " << center_.y << ')' << "\tWidth: "
      << width_ << "\tHeight: " << height_ << "\n";
}
