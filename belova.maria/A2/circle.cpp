#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

belova::Circle::Circle(const point_t &center, const double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Error: invalid value of radius");
  }
}

void belova::Circle::move(const point_t &center)
{
  center_ = center;
}

void belova::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

belova::rectangle_t belova::Circle::getFrameRect() const
{
  return { center_, radius_ * 2, radius_ * 2 };
}

double belova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void belova::Circle::showData(std::ostream& out) const
{
  out << "Circle:\nCenter: " << '(' << center_.x << ", " << center_.y << ')'
    << "\tRadius: " << radius_ << "\n";
}

void belova::Circle::scale(const double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("Error: invalid value of scale coefficient");
  }
  radius_ *= coeff;
}
