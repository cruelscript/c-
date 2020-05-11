#include "rectangle.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <ostream>

chevychelov::Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  if (width <= 0.0)
  {
    throw std::invalid_argument("Width can't be less than 0");
  }
  if (height <= 0.0)
  {
    throw std::invalid_argument("Height can't be less than 0");
  }
}

double chevychelov::Rectangle::getArea() const
{
  return width_ * height_;
}

chevychelov::rectangle_t chevychelov::Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void chevychelov::Rectangle::print(std::ostream& out) const
{
  out << "\n Rectangle parametrs are: \n Width: " << width_
    << "\n Hight: " << height_
    << "\n The center of rectangle x: " << pos_.x << " y: " << pos_.y << "\n";
}

void chevychelov::Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void chevychelov::Rectangle::move(const point_t& position)
{
  pos_ = position;
}

void chevychelov::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient can't be less than 0");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
