#include "circle.hpp"

#define _USE_MATH_DEFINES
#include <math.h>
#include <ostream>

vinokurov::Circle::Circle(const point_t& pos, const double radius) :
  Shape(pos),
  radius_(radius)
{
  if(radius_ <= 0)
  {
    throw std::invalid_argument("Circle: Error. Radius cannot be less than zero.");
  }
}

double vinokurov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

vinokurov::rectangle_t vinokurov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void vinokurov::Circle::print(std::ostream& out) const
{
  out << "\nRadius of the circle is " << radius_
    << ". The center of the circle is at x: " << pos_.x << ", y: " << pos_.y << "\n";
}

void vinokurov::Circle::scale(const double coefficient)
{
  if(coefficient <= 0)
  {
    throw std::invalid_argument("Circle: Error. Scaling coefficient cannot be less than zero.");
  }

  radius_ *= coefficient;
}
