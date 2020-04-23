#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <ostream>
#include <stdexcept>

fokin::Circle::Circle(const fokin::point_t &center, const double radius) :
  center_{ center },
  radius_{ radius }
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius should be greater than 0!");
  }
}

double fokin::Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

fokin::rectangle_t fokin::Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, center_ };
}

void fokin::Circle::move(const fokin::point_t &newCenter)
{
  center_ = newCenter;
}

void fokin::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void fokin::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Ñoefficient should be greater than 0!");
  }
  radius_ *= coefficient;
}
