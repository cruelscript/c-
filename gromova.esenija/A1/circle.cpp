#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

Circle::Circle(const double radius, const point_t& centre) :
  radius_(radius),
  centre_(centre)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_,centre_ };
}

void Circle::move(const point_t& point)
{
  centre_ = point;
}

void Circle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}
