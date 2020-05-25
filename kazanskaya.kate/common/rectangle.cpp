#include "rectangle.hpp"
#include <cassert>
#include <ostream>
#include "base-types.hpp"


kazanskaya::Rectangle::Rectangle(double width, double height, const point_t& center) :
  width_(width),
  height_(height),
  center_(center)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Width can't be a non-positive number");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Height can't be a non-positive number");
  }
}

double kazanskaya::Rectangle::getArea() const
{
  return width_ * height_;
}

kazanskaya::rectangle_t kazanskaya::Rectangle::getFrameRect() const
{
  return { width_, height_, center_ };
}

void kazanskaya::Rectangle::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void kazanskaya::Rectangle::move(const double dX, const double dY)
{
  center_.x += dX;
  center_.y += dY;
}

void kazanskaya::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be a non-positive number");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
