#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t& position, const double radius) :
  Shape(position),
  radius_(radius)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return { position_, 2 * radius_, 2 * radius_ };
}

void Circle::print() const
{
  std::cout << "Circle.\n";
  std::cout << "Position: x = " << position_.x << ", y = " << position_.y << '\n';
  std::cout << "Radius = " << radius_ << '\n';
}
