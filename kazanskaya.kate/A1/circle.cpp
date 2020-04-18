#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>

Circle::Circle(const double radius, const point_t& center) :
  radius_(radius),
  center_(center)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void Circle::move(const point_t& newCenter)
{
  center_ = newCenter;
}
void Circle::move(const double& dX, const double& dY)
{
  center_.x += dX;
  center_.y += dY;
}
