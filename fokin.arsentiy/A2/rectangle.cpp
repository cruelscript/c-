#include "rectangle.hpp"
#include <ostream>
#include <stdexcept>

fokin::Rectangle::Rectangle(const double width, const double height, const fokin::point_t &center) :
  rect_{ width, height, center }
{
  if (width <= 0.0)
  {
    throw std::invalid_argument("Width should be greater than 0!");
  }
  if (height <= 0.0)
  {
    throw std::invalid_argument("Height should be greater than 0!");
  }
}

double fokin::Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

fokin::rectangle_t fokin::Rectangle::getFrameRect() const
{
  return rect_;
}

void fokin::Rectangle::move(const fokin::point_t &newPos)
{
  rect_.pos = newPos;
}

void fokin::Rectangle::move(const double dx, const double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void fokin::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Ñoefficient should be greater than 0!");
  }
  rect_.width *= coefficient;
  rect_.height *= coefficient;
}
