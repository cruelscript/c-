#include "circle.hpp"
#include <cassert>
#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(const double rad, const double x, const double y) :
  Circle{ rad, { x, y } }
{}

Circle::Circle(const double rad, const point_t &point) :
  radius_(rad),
  center_(point)
{
  assert(rad > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_* radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, center_ };
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t &point)
{
  center_ = point;
}
