#include "rectangle.hpp"

#include <cassert>
#include <iostream>

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
  return rectangle_t{width_, height_, pos_};
}

void Rectangle::print() const
{
  std::cout << "Rectangle " << width_ << "x" << height_;
}

double Rectangle::getWidth() const
{
  return width_;
}

double Rectangle::getHeight() const
{
  return height_;
}
