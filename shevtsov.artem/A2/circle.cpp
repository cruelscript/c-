#include "circle.hpp"
#include <ostream>
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>

shevtsov::Circle::Circle(const double radius, const shevtsov::point_t& center):
  radius_(radius),
  center_(center)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius can't be less or equil 0");
  }
}

double shevtsov::Circle::getArea() const
{
  return (M_PI * radius_ * radius_);
}

shevtsov::rectangle_t shevtsov::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void shevtsov::Circle::move(const shevtsov::point_t& newCenter)
{
  center_ = newCenter;
}

void shevtsov::Circle::move(const double shiftX, const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}

void shevtsov::Circle::scale(const double scaleRate)
{
  if (scaleRate <= 0.0)
  {
    throw std::invalid_argument("Scale rate can't be less or equil 0");
  }
  radius_ *= scaleRate;
}

void shevtsov::Circle::printInfo(std::ostream& out) const
{
  out << "Circle:"
    << "\n - Radius of circle - " << radius_
    << "\n - Center of circle - (" << center_.x << "; " << center_.y << ")\n";
}
