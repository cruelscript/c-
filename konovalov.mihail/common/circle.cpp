#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

konovalov::Circle::Circle(double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius can't be <= 0!!!");
  }
}

double konovalov::Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

konovalov::point_t konovalov::Circle::getCenterPoint() const noexcept
{
  return center_;
}

konovalov::rectangle_t konovalov::Circle::getFrameRect() const noexcept
{
  double side = 2.0 * radius_;
  return {side, side, center_};
}

void konovalov::Circle::move(const point_t &point) noexcept
{
  center_ = point;
}

void konovalov::Circle::move(double dx, double dy) noexcept
{
  center_.x += dx;
  center_.y += dy;
}

void konovalov::Circle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaled coefficient can't be <= 0!!!");
  }

  radius_ *= coefficient;
}
