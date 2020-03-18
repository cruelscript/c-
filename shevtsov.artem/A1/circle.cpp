#include <cassert>
#define _USE_MATH_DEFINES
#include <cmath>
#include "circle.hpp"

Circle::Circle(double radius, const point_t& center):
  radius_(radius),
  center_(center)
{
  assert (radius > 0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void Circle::move(double shiftX, double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}

const char* Circle::printName() const
{
  return "Circle";
}
