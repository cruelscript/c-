#include "circle.hpp"

#define _USE_MATH_DEFINES

#include <cassert>
#include <cmath>
#include <ostream>
#include "base-types.hpp"

Circle::Circle(const point_t& position, const double radius) :
  Shape(position),
  radius_(radius)
{
  assert(radius_ > 0.0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return { position_, 2 * radius_, 2 * radius_ };
}

void Circle::print(std::ostream & out) const
{
  out << "Circle.\n";
  out << "Position: x = " << position_.x << ", y = " << position_.y << '\n';
  out << "Radius = " << radius_ << '\n';
}
