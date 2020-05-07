#include "circle.hpp"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>

gyrlov::Circle::Circle(const point_t& center, const double radius) :
  center_(center),
  radius_(radius) 
{
  if (radius <= 0.0)
  {
    throw std::invalid_argument("Radius can't be less zero");
  }
}

double gyrlov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

gyrlov::rectangle_t gyrlov::Circle::getFrameRect() const
{
  return {2.0 * radius_, 2.0 * radius_, center_};
}

void gyrlov::Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void gyrlov::Circle::move(const point_t& moveTo)
{
  center_ = moveTo;
}

void gyrlov::Circle::scale(const double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("You can't scale circle less zero.");
  }
  radius_ *= coeff;
}

void gyrlov::Circle::print(std::ostream& out) const
{
  out << "Radius: " << radius_ << "\n";
  out << "Center: (" << center_.x << ", " << center_.y << ")\n\n";
}
