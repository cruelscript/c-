#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(const point_t& center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  assert((width_ > 0.0) && (height_ > 0.0));
}

Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x,y}, width, height)
{}

double Rectangle::getArea() const 
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const 
{
  return {width_, height_, center_};
}

point_t Rectangle::getPos() const 
{
  return center_;
}

void Rectangle::move(const point_t& center)
{
  center_ = center;
}

void Rectangle::move(double deltaX, double deltaY) 
{
  center_.x += deltaX;
  center_.y += deltaY;
}
