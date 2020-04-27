#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

konovalov::Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius can't be <= 0!!!");
  }
}

void konovalov::Circle::move(const point_t &point)
{
  center_ = point;
}

void konovalov::Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

double konovalov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

konovalov::rectangle_t konovalov::Circle::getFrameRect() const
{
  double side = 2 * radius_;
  return {side, side, center_};
}

void konovalov::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Scaled coefficient can't be <= 0!!!");
  }

  radius_ *= coefficient;
}
