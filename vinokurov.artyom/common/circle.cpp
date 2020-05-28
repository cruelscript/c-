#include "circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

vinokurov::Circle::Circle(double radius, const point_t& center) :
  radius_(radius),
  center_(center)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Circle: Error. Radius cannot be less than zero.");
  }
}

double vinokurov::Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

vinokurov::rectangle_t vinokurov::Circle::getFrameRect() const noexcept
{
  return {2 * radius_, 2 * radius_, center_};
}

void vinokurov::Circle::move(const point_t& newCenter) noexcept
{
  center_ = newCenter;
}

void vinokurov::Circle::move(double deltaX, double deltaY) noexcept
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void vinokurov::Circle::print(std::ostream& out) const
{
  out << "\nRadius of the circle is " << radius_;
  out << "\nCenter of the circle is at (" << center_.x << ", " << center_.y << ")\n";
}

void vinokurov::Circle::scale(double coefficient)
{
  if(coefficient <= 0)
  {
    throw std::invalid_argument("Circle: Error. Scaling coefficient cannot be less than zero.");
  }
  radius_ *= coefficient;
}

void vinokurov::Circle::rotate(double) noexcept
{}
