#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t &centre, double width, double height) :
  width_(width),
  height_(height),
  centre_(centre)
{
  assert((width > 0) && (height > 0));
}

void Rectangle::move(const point_t &point)
{
  centre_ = point;
}

void Rectangle::move(double dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {centre_, width_, height_};
}

void Rectangle::printCentre(std::ostream &out) const
{
  out << "Rectangle centre: (" << centre_.x << ", " << centre_.y << ")\n";
}
