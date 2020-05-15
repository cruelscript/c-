#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

savenkova::Circle::Circle(const point_t& center, const double& radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Error: circle's radius cannot be negative or zero");
  }
}

double savenkova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

savenkova::rectangle_t savenkova::Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, center_ };
}

void savenkova::Circle::move(const point_t& point)
{
  center_ = point;
}

void savenkova::Circle::move(const double xOffset, const double yOffset)
{
  center_.x += xOffset;
  center_.y += yOffset;
}

void savenkova::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Error: circle's coefficient cannot be negative or zero");
  }
  radius_ *= coefficient;
}
