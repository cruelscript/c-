#include "circle.hpp"

#define _USE_MATH_DEFINES

#include <cassert>
#include <cmath>
#include <ostream>
#include <stdexcept>

prishchepa::Circle::Circle(const prishchepa::point_t & position, double radius) :
  Shape(position),
  radius_(radius)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius is less than or equal to zero");
  }
}

double prishchepa::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

prishchepa::rectangle_t prishchepa::Circle::getFrameRect() const
{
  return {radius_ * 2.0, radius_ * 2.0, pos_};
}

void prishchepa::Circle::print(std::ostream & out) const
{
  out << "Circle r=" << radius_ << " at (" << pos_.x << "; " << pos_.y << ")";
}

void prishchepa::Circle::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Factor is less than or equal to zero");
  }

  radius_ *= factor;
}

double prishchepa::Circle::getRadius() const
{
  return radius_;
}
