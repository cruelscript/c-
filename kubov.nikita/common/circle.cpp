#include "circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

#include "base-types.hpp"

kubov::Circle::Circle(const point_t &center, const double radius):
  center_(center),
  radius_(radius)
{
  if (radius <= 0.0) {
    throw std::invalid_argument("Error. Radius can't be <= 0.0");
  }
}

double kubov::Circle::getArea() const noexcept
{
  return M_PI * radius_ * radius_;
}

kubov::rectangle_t kubov::Circle::getFrameRect() const
{
  return {2.0 * radius_, 2.0 * radius_, center_};
}

kubov::point_t kubov::Circle::getCenter() const noexcept
{
  return center_;
}

void kubov::Circle::move(const point_t &positionNew) noexcept
{
  center_ = positionNew;
}

void kubov::Circle::move(const double deltaX, const double deltaY) noexcept
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void kubov::Circle::print(std::ostream &out) const
{
  out << "This is circle\n";
  out << "Radius: " << radius_ << "\n";
  out << "Center: (" << center_.x << ", " << center_.y << ")\n";
}

void kubov::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0) {
    throw std::invalid_argument("Invalid coefficient");
  }

  radius_ *= coefficient;
}
