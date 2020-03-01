#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdexcept>

Circle::Circle() :
  radius_(1.0)
{
  center_.x = 0.0;
  center_.y = 0.0;
}

Circle::Circle(const point_t &center, const double radius) :
  center_(center),
  radius_(radius)
{
  if(radius <= 0.0)
  {
    radius_ = 0.0;
   
    throw std::invalid_argument("Error. Radius can't be <= 0.0");
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  rectangle_t frameRectangle;
  frameRectangle.width = 2.0 * radius_;
  frameRectangle.height = 2.0 * radius_;
  frameRectangle.pos = center_;

  return frameRectangle;
}

void Circle::move(const point_t &positionNew)
{
  center_ = positionNew;
}

void Circle::move(const double &deltaX, const double &deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void Circle::getInfo() const
{
  std::cout << "This is circle" << std::endl;
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Center: " << "(" << center_.x << ", " << center_.y << ")" << std::endl;
}


