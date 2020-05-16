#include "circle.hpp"
#include <cassert>

#define _USE_MATH_DEFINES

#include <cmath>

sviridov::Circle::Circle(const point_t &centre, double radius):
  radius_(radius),
  centre_(centre)
{
  assert(radius > 0);
}

void sviridov::Circle::move(const point_t &point)
{
  centre_ = point;
}

void sviridov::Circle::move(double  dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

double sviridov::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

sviridov::rectangle_t sviridov::Circle::getFrameRect() const
{
  return { centre_, 2 * radius_, 2 * radius_ };
}

void sviridov::Circle::scale(const double scaleRate)
{
  assert(scaleRate > 0.0);
  radius_ *= scaleRate;
}
