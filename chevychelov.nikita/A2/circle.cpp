#include "circle.hpp"
#include "base-types.hpp"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>
#include <ostream>

chevychelov::Circle::Circle(const double radius, const point_t& pos):
  radius_(radius),
  pos_(pos)
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius can't be less than 0");
  }
}

double chevychelov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

chevychelov::rectangle_t chevychelov::Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, pos_ };
}

void chevychelov::Circle::print(std::ostream& out) const
{
  out << "\n Radius of circle: " << radius_
    << "\n The center of circle x: " << pos_.x << " y: " << pos_.y << "\n";
}

void chevychelov::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void chevychelov::Circle::move(const point_t& position)
{
  pos_ = position;
}

void chevychelov::Circle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient can't be less than 0");
  }
  radius_ *= coefficient;
}
