#include "circle.hpp"
#include <iostream>
#include <cassert>

#define _USE_MATH_DEFINES

#include <cmath>

Circle::Circle(const point_t& centre, double radius):
  radius_(radius),
  centre_(centre)
{
  assert(radius > 0);
}

void Circle::move(const point_t& point)
{
  centre_ = point;
}

void Circle::move(double  dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return { centre_, 2 * radius_, 2 * radius_};
}

void Circle::printCentre() const 
{
  std::cout << "Circle centre: (" << centre_.x << ", " << centre_.y << ")\n";
}
