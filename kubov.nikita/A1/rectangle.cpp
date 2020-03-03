#include "rectangle.hpp"
#include <stdexcept>
#include <iostream>

Rectangle::Rectangle(const point_t &center, const double width, const double height) :
  center_(center),
  width_(width),
  height_(height)
{
    if (width_ <= 0.0)
    {
      width_ = 0.0;
      
      throw std::invalid_argument("Error. Width can't be <= 0");
    }
    
    if (height_ <= 0.0)
    {
      height_ = 0.0;
      
      throw std::invalid_argument("Error. Height can't be <= 0");
    }
}
 
double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

void Rectangle::move(const point_t &positionNew)
{
  center_ = positionNew;
}

void Rectangle::move(const double &deltaX, const double &deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void Rectangle::print() const
{
  std::cout << "This is rectangle\n";
  std::cout << "Width: " << width_ << "\n";
  std::cout << "Height: " << height_ << "\n";
  std::cout << "Center: (" << center_.x << ", " << center_.y << ")\n";
}


