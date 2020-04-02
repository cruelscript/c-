#include "circle.hpp"
#include <cassert>
#define _USE_MATH_DEFINES
#include <cmath>
#include <ostream>

Circle::Circle(const double radius, const point_t& pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, pos_ };
}

void Circle::print(std::ostream& out) const
{
  out << "\n Radius of circle: " << radius_
    << "\n The center of circle x: " << pos_.x << " y: " << pos_.y << "\n";
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t& position)
{
  pos_ = position;
}
