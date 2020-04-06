#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t& center, const double radius) :
  center_(center),
  radius_(radius) 
{
  assert(radius_ > 0);
}

double Circle::getArea() const 
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const 
{
  return {2.0 * radius_, 2.0 * radius_, center_};
}

void Circle::move(const double dx, const double dy) 
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move(const point_t& moveTo) 
{
  center_ = moveTo;
}
