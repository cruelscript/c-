#include "rectangle.hpp"
#include <ostream>
#include <stdexcept>

shevtsov::Rectangle::Rectangle(const double width, const double height, const shevtsov::point_t& center):
  width_(width),
  height_(height),
  center_(center)
{
  if (width <= 0.0)
  {
    throw std::invalid_argument("Width can't be less or equil 0");
  }
  if (height <= 0.0)
  {
    throw std::invalid_argument("Height can't be less or equil 0");
  }
}

double shevtsov::Rectangle::getArea() const
{
  return (width_ * height_);
}

shevtsov::rectangle_t shevtsov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void shevtsov::Rectangle::move(const shevtsov::point_t& newCenter)
{
  center_ = newCenter;
}

void shevtsov::Rectangle::move(const double shiftX, const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}

void shevtsov::Rectangle::scale(const double scaleRate)
{
  if (scaleRate <= 0.0)
  {
    throw std::invalid_argument("Scale rate can't be less or equil 0");
  }
  width_ *= scaleRate;
  height_ *= scaleRate;
}

void shevtsov::Rectangle::printInfo(std::ostream& out) const
{
  out << "Rectangle:"
    << "\n - Width of rectangle - " << width_
    << "\n - Height of rectangle - " << height_
    << "\n - Center of rectangle - (" << center_.x << "; " << center_.y << ")\n";
}
