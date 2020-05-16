#include "rectangle.hpp"
#include <cassert>

sviridov::Rectangle::Rectangle(const point_t &centre, double width, double height) :
  width_(width),
  height_(height),
  centre_(centre)
{
  assert((width > 0) && (height > 0));
}

void sviridov::Rectangle::move(const point_t &point)
{
  centre_ = point;
}

void sviridov::Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

double sviridov::Rectangle::getArea() const
{
  return width_ * height_;
}

sviridov::rectangle_t sviridov::Rectangle::getFrameRect() const
{
  return { centre_, width_, height_ };
}

void sviridov::Rectangle::scale(const double scaleRate)
{
  assert(scaleRate > 0.0);
  width_ *= scaleRate;
  height_ *= scaleRate;
}
