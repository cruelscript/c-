#include "circle.hpp"

#include <cassert>
#include <cmath>

Circle::Circle(const point_t& center, double radius) :
  center_(center),
  radius_(radius)
{
  assert(radius_ >= 0.0);
}

Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{}

double Circle::getArea() const 
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const 
{
  return {radius_ * 2, radius_ * 2, center_};
}

point_t Circle::getPos() const 
{
    return center_;
}

void Circle::move(const point_t& center) 
{
  center_ = center;
}

void Circle::move(double deltaX, double deltaY) 
{
  center_.x += deltaX;
  center_.y += deltaY;
}
