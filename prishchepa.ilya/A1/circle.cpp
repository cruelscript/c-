#include "circle.hpp"

#include <cassert>
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(const point_t & position, double radius) :
  Shape(position),
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
  return {radius_ * 2.0, radius_ * 2.0, pos_};
}

void Circle::print(std::ostream & out) const
{
  out << "Circle r=" << radius_;
}

double Circle::getRadius() const
{
  return radius_;
}
