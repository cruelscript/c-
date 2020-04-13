#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>
#include <ostream>

Circle::Circle(const point_t & position, double radius) :
  Shape(position),
  radius_(radius)
{
  assert(radius > 0.0);
}

Circle::Circle(const double x, const double y, double radius) :
  Circle({x, y}, radius)
{}

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
  out << "Circle radius = " << radius_;
  out << "\nPosition: (" << pos_.x << ";" << pos_.y << ")";
}

double Circle::getRadius() const
{
  return radius_;
}

void Circle::setRadius(double radius)
{
  radius_ = radius;
}
