#include "rectangle.hpp"
#include <cassert>
#include <ostream>
#include "base-types.hpp"

Rectangle::Rectangle(const point_t& position, const double width, const double height) :
  Shape(position),
  width_(width),
  height_(height)
{
  assert(width_ > 0.0);
  assert(height_ > 0.0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { position_, width_, height_ };
}

void Rectangle::print(std::ostream & out) const
{
  out << "Rectangle.\n";
  out << "Position: x = " << position_.x << ", y = " << position_.y << '\n';
  out << "height = " << height_ << " width = " << width_ << '\n';
}
