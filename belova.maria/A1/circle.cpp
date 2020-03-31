#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Circle::Circle(const point_t &center, const double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0);
}

point_t Circle::getCenter() const
{
  return center_;
}

double Circle::getRadius() const
{
  return radius_;
}

void Circle::move(const point_t &center)
{
  center_ = center;
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

rectangle_t Circle::getFrameRect() const
{
  return { center_, radius_ * 2, radius_ * 2 };
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void Circle::showData() const
{
  std::cout << "Circle:\nCenter: " << getCenter()
      << "\tRadius: " << getRadius() << "\n\n";
}
