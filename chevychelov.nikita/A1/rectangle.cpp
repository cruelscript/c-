#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert(width > 0.0);
  assert(height > 0.0);
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::print(std::ostream& out) const
{
  out << "\n Rectangle parametrs are: \n Width: " << width_
    << "\n Hight: " << height_
    << "\n The center of rectangle x: " << pos_.x << " y: " << pos_.y << "\n";
}

void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t& position)
{
  pos_ = position;
}
