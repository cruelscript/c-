#include "circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

Circle::Circle(const point_t& center, const double radius) :
  center_{ center.x, center.y },
  radius_{ radius }
{
  assert(radius > 0 && "Error! Radius must be a positive value. Exiting...\n");
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t rect_{ radius_ * 2, radius_ * 2, center_ };
  return rect_;
}

point_t Circle::getCenter() const
{
  return center_;
}

double Circle::getRadius() const
{
  return radius_;
}

void Circle::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void Circle::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}
