#include "rectangle.hpp"
#include <stdexcept>

gyrlov::Rectangle::Rectangle(const point_t& center, const double width, const double height) :
  center_(center),
  width_(width),
  height_(height) 
{
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle height cannot be less zero.");
  }
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Rectangle width cannot be less zero.");
  }
}

double gyrlov::Rectangle::getArea() const
{
  return width_ * height_;
}

gyrlov::rectangle_t gyrlov::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void gyrlov::Rectangle::move(const point_t& moveTo)
{
  center_ = moveTo;
}

void gyrlov::Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void gyrlov::Rectangle::scale(const double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("You can't scale rectangle less zero.");
  }
  width_ *= coeff;
  height_ *= coeff;
}

void gyrlov::Rectangle::print(std::ostream& out) const
{
  out << "Width: " << width_ << "\n";
  out << "Height: " << height_ << "\n";
  out << "Center: (" << center_.x << ", " << center_.y << ")\n\n";
}
