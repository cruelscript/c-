#include "rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const point_t &center, const double w, const double h) :
  center_(center),
  width_(w),
  height_(h)
{
  assert(width_ > 0);
  assert(height_ > 0);
}

point_t Rectangle::getCenter() const
{
  return center_;
}

double Rectangle::getWidth() const
{
  return width_;
}

double Rectangle::getHeight() const
{
  return height_;
}

void Rectangle::move(const point_t &center)
{
  center_ = center;
}

void Rectangle::move(const double dx, const double dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { center_, width_, height_ };
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

void Rectangle::showData() const
{
  std::cout << "Rectangle:\nCenter: " << getCenter() << "\tWidth: "
    << getWidth() << "\tHeight: " << getHeight() << "\n";
}
