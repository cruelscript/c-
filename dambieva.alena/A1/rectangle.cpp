#include "rectangle.hpp"
#include <cassert>
#include <ostream>

Rectangle::Rectangle(const point_t & pos, double width, double height) :
  Shape(pos),
  width_(width),
  height_(height)
{
  assert(width > 0.0);
  assert(height > 0.0);
}

Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::print(std::ostream & out) const
{
  out << "Rectangle width = " << width_ << ", height = " << height_;
  out << "\nPosition: (" << pos_.x << ";" << pos_.y << ")";
}

double Rectangle::getWidth() const
{
  return width_;
}

double Rectangle::getHeight() const
{
  return height_;
}

void Rectangle::setWidth(double width)
{
  assert(width > 0.0);
  width_ = width;
}

void Rectangle::setHeight(double height)
{
  assert(height > 0.0);
  height_ = height;
}
