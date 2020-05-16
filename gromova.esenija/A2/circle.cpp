#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

gromova::Circle::Circle(const double radius, const point_t& centre) :
  radius_(radius),
  centre_(centre)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Wrong radius!");
  }
}

double gromova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

gromova::rectangle_t gromova::Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, centre_ };
}

void gromova::Circle::move(const point_t& point)
{
  centre_ = point;
}

void gromova::Circle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void gromova::Circle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Wrong coefficient!");
  }

  radius_ *= k;
}
