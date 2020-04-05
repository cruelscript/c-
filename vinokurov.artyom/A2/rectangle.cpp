#include "rectangle.hpp"

#include <stdexcept>
#include <ostream>

vinokurov::Rectangle::Rectangle(const point_t& pos, double width, double height) :
  Shape(pos),
  width_(width),
  height_(height)
{
  if(height_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Height cannot be less than zero.");
  }
  if(width_ <= 0.0)
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
  return {width_, height_, pos_};
}

void vinokurov::Rectangle::print(std::ostream& out) const
{
  out << "\nWidth of the rectangle is " << width_
    << ", height of the rectangle is " << height_
    << ". The center of the rectangle is at x: " << pos_.x << ", y: " << pos_.y << "\n";
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
