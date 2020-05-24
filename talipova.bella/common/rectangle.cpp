#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

talipova::Rectangle::Rectangle(const point_t& pos, const double w, const double h) :
  pos_(pos),
  width_(w),
  height_(h)
{
  if (width_ <= 0)
  {
    throw std::invalid_argument("Error! Invalid width.");
  }
  if (height_ <= 0)
  {
    throw std::invalid_argument("Error! Invalid height.");
  }
}

talipova::Rectangle::Rectangle(const double x, const double y, const double w, const double h) :
  Rectangle({ x, y }, w, h)
{}

double talipova::Rectangle::getArea() const
{
  return width_ * height_;
}

talipova::rectangle_t talipova::Rectangle::getFrameRect() const
{
  return { pos_, width_, height_ };
}

void talipova::Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void talipova::Rectangle::move(const point_t& point)
{
  pos_ = point;
}

talipova::point_t talipova::Rectangle::getPosition() const
{
  return pos_;
};

void talipova::Rectangle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error! Invalid coefficient.");
  }
  width_ *= k;
  height_ *= k;
}
