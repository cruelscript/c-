#include "rectangle.hpp"
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

belova::Rectangle::Rectangle(const point_t& center, const double w, const double h) :
  center_(center),
  width_(w),
  height_(h)
{
  if (width_ <= 0.0)
  {
    throw std::invalid_argument("Error: invalid value of width");
  }
  if (height_ <= 0.0)
  {
    throw std::invalid_argument("Error: invalid value of height");
  }
}

void belova::Rectangle::move(const point_t &center)
{
  center_ = center;
}

void belova::Rectangle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

belova::rectangle_t belova::Rectangle::getFrameRect() const
{
  return { center_, width_, height_ };
}

double belova::Rectangle::getArea() const
{
  return width_ * height_;
}

void belova::Rectangle::showData(std::ostream& out) const
{
  out << "Rectangle:\nCenter: " << '(' << center_.x << ", " << center_.y << ')' << "\tWidth: "
    << width_ << "\tHeight: " << height_ << "\n";
}

void belova::Rectangle::scale(const double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("Error: invalid value of scale coefficient");
  }
  width_ *= coeff;
  height_ *= coeff;
}
