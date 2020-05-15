#include "rectangle.hpp"
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

savenkova::Rectangle::Rectangle(const point_t& center, const double& w, const double& h) :
  center_(center),
  width_(w),
  height_(h)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Error: rectangle's width and height cannot be negative or zero");
  }

}

double savenkova::Rectangle::getArea() const
{
  return width_ * height_;
}

savenkova::rectangle_t savenkova::Rectangle::getFrameRect() const
{
  return { width_, height_, center_ };
}

void savenkova::Rectangle::move(const point_t& point)
{
  center_ = point;
}

void savenkova::Rectangle::move(const double xOffset, const double yOffset)
{
  center_.x += xOffset;
  center_.y += yOffset;
}

void savenkova::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Error: ractangle's coefficient cannot be negative or zero");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
