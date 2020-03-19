#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t& pos, double width, double height) :
  Shape(pos),
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

void Rectangle::print() const
{
  std::cout << "\nWidth of the rectangle is " << width_
    << ", height of the rectangle is " << height_
    << ". The center of the rectangle is at x: " << pos_.x << ", y: " << pos_.y << "\n";
}
