#define _USE_MATH_DEFINES

#include <iostream>
#include "circle.hpp"
#include <cassert>
#include <cmath>

Circle::Circle(const point_t& centre, double radius):
  radius_(radius),
  centre_(centre)
{
  assert(radius > 0);
}

void Circle::move(const point_t& point)
{
  centre_ = point;
}

void Circle::move(double  dx, double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{ centre_, 2 * radius_, 2 * radius_};
}

point_t Circle::getCentre() const
{
  return centre_;
}

void Circle::show_frame(Shape* figure_) const
{
  std::cout << "Rectangle around circle height: " << figure_->getFrameRect().height << "\n"
    << "Rectangle around circle width: " << figure_->getFrameRect().width << "\n"
    << "Rectangle around circle pos(x): " << figure_->getFrameRect().pos.x << "\n"
    << "Rectangle around circle pos(y): " << figure_->getFrameRect().pos.y << "\n\n";
}

void Circle::show_position(Shape* figure_) const
{
  std::cout << "Circle centre x: " << figure_->getCentre().x << "\n"
    << "Circle centre y: " << figure_->getCentre().y << "\n\n";
}
