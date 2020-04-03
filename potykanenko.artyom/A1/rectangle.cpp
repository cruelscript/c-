#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const double x, const double y) :
  Rectangle(width, height, { x, y })
{}

Rectangle::Rectangle(const double width, const double height, const point_t &pos) :
  rect_{ width, height, pos }
{
  assert((width > 0.0) && (height > 0.0));
}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::move(const point_t &point)
{
  rect_.pos = point;
}
