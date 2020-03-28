#include "circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &center, const double radius) :
  center_{ center },
  radius_{ radius }
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, center_ };
}

void Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
