#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdexcept>

Circle::Circle(const point_t &position, const double radius) :
  position_(position),
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
  frameRectangle.position = position_;

  return frameRectangle;
}

void Circle::move(const point_t &positionNew)
{
  position_ = positionNew;
}

void Circle::move(const double &deltaX, const double &deltaY)
{
  position_.x += deltaX;
  position_.y += deltaY;
}

void Circle::getInfo() const
{
  std::cout << "This is circle" << std::endl;
  std::cout << "Radius: " << radius_ << std::endl;
  std::cout << "Center: " << "(" << position_.x << ", " << position_.y << ")" << std::endl;
}