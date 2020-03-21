#include "Rectangle.hpp"

#include <cassert>
#include "base-types.hpp"
#include "shape.hpp"

Rectangle::Rectangle(const point_t &center, const double &w, const double &h) :
  center_(center),
  width_(w),
  height_(h)
{
  assert((w > 0.0) && (h > 0.0));
}

Rectangle::Rectangle(const Rectangle &rectangle) :
  center_(rectangle.center_),
  width_(rectangle.width_),
  height_(rectangle.height_)
{
  assert((rectangle.width_ > 0.0) && (rectangle.height_ > 0.0));
}

Rectangle::Rectangle(Rectangle &&rectangle) :
  center_(rectangle.center_),
  width_(rectangle.width_),
  height_(rectangle.height_)
{
  assert((rectangle.width_ > 0.0) && (rectangle.height_ > 0.0));
  rectangle.center_ = { 0.0,0.0 };
  rectangle.width_ = 0.0;
  rectangle.height_ = 0.0;
}

Rectangle::~Rectangle()
{
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, center_ };
}

void Rectangle::move(const point_t &point)
{
  center_ = point;
}

void Rectangle::move(const double &xOffset, const double &yOffset)
{
  center_.x += xOffset;
  center_.y += yOffset;
}
