#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>
#include "base-types.hpp"

Circle::Circle(const point_t &center, const double &radius) :
  center_(center),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const 
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, center_ };
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::move(const double &xOffset, const double &yOffset)
{
  center_.x += xOffset;
  center_.y += yOffset;
}
