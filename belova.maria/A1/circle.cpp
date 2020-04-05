#include "circle.hpp"
#include <cassert>
#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846

Circle::Circle(const point_t &center, const double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ > 0.0);
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

void Circle::showData(std::ostream& out) const
{
  out << "Circle:\nCenter: " << '(' << center_.x << ", " << center_.y << ')'
      << "\tRadius: " << radius_ << "\n\n";
}

#endif
