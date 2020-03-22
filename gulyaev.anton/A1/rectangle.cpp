#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(double width, double height, double x, double y) :
  Rectangle(width, height, {x, y})
{}

Rectangle::Rectangle(double width, double height, const point_t &center) :
  rectangle_({width, height, center})
{
  assert(width > 0.0);
  assert(height > 0.0);
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}

void Rectangle::move(double deltaX, double deltaY)
{
  rectangle_.pos.x += deltaX;
  rectangle_.pos.y += deltaY;
}
