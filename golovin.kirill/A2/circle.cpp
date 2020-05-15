#include "circle.hpp"
#include <cmath>
#include <stdexcept>

golovin::Circle::Circle(const point_t &center, double radius):
  Shape(center),
  radius_(radius)
{
  if (radius_ <= 0.0)
  {
    throw std::invalid_argument("Error\nThe incoming raduis of the circle must be > 0");
  }
}

double golovin::Circle::getArea() const
{
  return M_PI * std::pow(radius_, 2);
}

golovin::rectangle_t golovin::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, center_};
}

void golovin::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error\nThe incoming coefficient of the scalability must be > 0");
  }
  radius_ *= coefficient;
}
