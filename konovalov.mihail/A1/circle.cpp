#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(double radius, const point_t &center) :
        radius_(radius),
        center_(center)
{
  assert(radius_ > 0.0);
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::move(double dx, double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  double side = 2 * radius_;
  return {side, side, center_};
}
