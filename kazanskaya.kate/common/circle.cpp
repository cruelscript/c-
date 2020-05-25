#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

kazanskaya::Circle::Circle(const double radius, const point_t& center) :
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Radius can't be a non-positive number");
  }
}

double kazanskaya::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

kazanskaya::rectangle_t kazanskaya::Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, center_ };
}

void kazanskaya::Circle::move(const point_t& newCenter)
{
  center_ = newCenter;
}
void kazanskaya::Circle::move(const double dX, const double dY)
{
  center_.x += dX;
  center_.y += dY;
}

void kazanskaya::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Coefficient can't be a non-positive number");
  }
  radius_ *= coefficient;
}
