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

Rectangle::Rectangle(const double x, const double y, const double width, const double height) :
  Rectangle({x, y}, width, height)
{}

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
  width_ = width;
}

void Rectangle::setHeight(double height)
{
  height_ = height;
}

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
