#include "rectangle.hpp"
#include <stdexcept>

golovin::Rectangle::Rectangle(const point_t &center, double width, double height):
  Shape(center),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Error\nThe incoming sides of the rectangle must be > 0");
  }
}

double golovin::Rectangle::getArea() const
{
  return width_ * height_;
}

golovin::rectangle_t golovin::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void golovin::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error\nThe incoming coefficient of the scalability must be > 0");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
