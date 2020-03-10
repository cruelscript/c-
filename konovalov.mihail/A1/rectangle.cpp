#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const rectangle_t &rectangle) :
  rectangle_(rectangle)
{
  assert(rectangle_.width > 0.0);
  assert(rectangle_.height > 0.0);
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}
