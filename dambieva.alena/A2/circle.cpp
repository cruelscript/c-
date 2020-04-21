#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <ostream>

dambieva::Circle::Circle(const point_t & position, double radius) :
  Shape(position),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Error, invalid radius");
  }
}

dambieva::Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{}

double dambieva::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

dambieva::rectangle_t dambieva::Circle::getFrameRect() const
{
  return {radius_ * 2.0, radius_ * 2.0, pos_};
}

void dambieva::Circle::print(std::ostream & out) const
{
  out << "Circle radius = " << radius_;
  out << "\n\tPosition: (" << pos_.x << ";" << pos_.y << ")";
}

void dambieva::Circle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error, invalid coefficient for radius");
  }
  radius_ *= coefficient;
}

double dambieva::Circle::getRadius() const
{
  return radius_;
}

void dambieva::Circle::setRadius(double radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Error, invalid setted radius");
  }
  radius_ = radius;
}
