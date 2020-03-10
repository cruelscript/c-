#define _USE_MATH_DEFINES

#include "circle.hpp"
#include <cmath>
#include <cassert>
#include <iostream>

Circle::Circle(const point_t& pos, const double radius) :
  Shape(pos),
  radius_(radius)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return M_PI*radius_*radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2*radius_, 2*radius_, pos_};
}

void Circle::print() const
{
  std::cout << "\nRadius of the circle is " << radius_ 
    << ". The center of the circle is at x: " << pos_.x << ", y: " << pos_.y << "\n";
}
