#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &pos, const double radius) :
  pos_(pos),
  radius_(radius)
{
  assert(radius > 0 && "Error: Radius <= 0.\n");
}

Circle::Circle(const double x, const double y, const double radius) :
  Circle({x, y}, radius)
{}

rectangle_t Circle::getFrameRect() const
{
  return { pos_, radius_ * 2, radius_ * 2 };
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
};

void Circle::move(const double& dx, const double& dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t& point)
{
  pos_ = point;
}

point_t Circle::getPosition() const
{
  return pos_;
}
