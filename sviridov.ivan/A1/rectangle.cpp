#include <iostream>
#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t& centre, double width, double height) :
  width_(width),
  height_(height),
  centre_(centre)
{
  assert((width > 0) && (height > 0));
}

void Rectangle::move(const point_t& point)
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
  return rectangle_t{centre_, width_, height_};
}

point_t Rectangle::getCentre() const
{
  return centre_;
}

void Rectangle::show_frame(Shape* figure_) const
{
  std::cout << "Rectangle frame height: " << figure_->getFrameRect().height << "\n"
    << "Rectangle frame width: " << figure_->getFrameRect().width << "\n"
    << "Rectangle frame pos(x): " << figure_->getFrameRect().pos.x << "\n"
    << "Rectangle frame pos(y): " << figure_->getFrameRect().pos.y << "\n\n";
}

void Rectangle::show_position(Shape* figure_) const
{
  std::cout << "Rectangle centre x: " << figure_->getCentre().x << "\n"
    << "Rectangle centre y: " << figure_->getCentre().y << "\n\n";
}
