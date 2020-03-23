#include "rectangle.hpp"

#include <cassert>
#include <ostream>

Rectangle::Rectangle(const point_t & position, double width, double height) :
  Shape(position),
  width_(width),
  height_(height)
{
  assert(width > 0.0);
  assert(height > 0.0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void Rectangle::print(std::ostream & out) const
{
  out << "Rectangle " << width_ << "x" << height_;
}

double Rectangle::getWidth() const
{
  return width_;
}

double Rectangle::getHeight() const
{
  return height_;
}
