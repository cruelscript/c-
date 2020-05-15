#include "rectangle.hpp"

#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

vinokurov::Rectangle::Rectangle(double width, double height, const point_t& center) :
  width_(width),
  height_(height),
  center_(center)
{
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Height cannot be less than zero.");
  }
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Width cannot be less than zero.");
  }
}

double vinokurov::Rectangle::getArea() const
{
  return width_ * height_;
}

vinokurov::rectangle_t vinokurov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void vinokurov::Rectangle::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void vinokurov::Rectangle::move(const double deltaX, const double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void vinokurov::Rectangle::print(std::ostream& out) const
{
  out << "\nWidth of the rectangle is " << width_
    << ", height of the rectangle is " << height_
    << ". The center of the rectangle is at x: " << center_.x << ", y: " << center_.y << "\n";
}

void vinokurov::Rectangle::scale(const double coefficient)
{
  if(coefficient <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Scaling coefficient cannot be less than zero.");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
