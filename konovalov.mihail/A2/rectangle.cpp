#include "rectangle.hpp"

#include <stdexcept>
#include "base-types.hpp"

konovalov::Rectangle::Rectangle(const rectangle_t &rectangle) :
  rectangle_(rectangle)
{
  if (rectangle.width <= 0)
  {
    throw std::invalid_argument("Width in rectangle can't be <= 0!!!");
  }
  if (rectangle.height <= 0)
  {
    throw std::invalid_argument("Height in rectangle can't be <= 0!!!");
  }
}

void konovalov::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

double konovalov::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

void konovalov::Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}

konovalov::rectangle_t konovalov::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void konovalov::Rectangle::scale(double coefficient) {
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Scaled coefficient can't be <= 0!!!");
  }

  rectangle_.height *= coefficient;
  rectangle_.width *= coefficient;
}
