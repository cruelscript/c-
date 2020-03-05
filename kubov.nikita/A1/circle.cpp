#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <iostream>

Circle::Circle(const point_t &center, const double radius) :
  center_(center),
  radius_(radius)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Error. Radius can't be <= 0.0");
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2.0 * radius_, 2.0 * radius_, center_};
}

void Circle::move(const point_t &positionNew)
{
  center_ = positionNew;
}

void Circle::move(const double &deltaX, const double &deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void Circle::print() const
{
  std::cout << "This is circle\n";
  std::cout << "Radius: " << radius_ << "\n";
  std::cout << "Center: (" << center_.x << ", " << center_.y << ")\n";
}


