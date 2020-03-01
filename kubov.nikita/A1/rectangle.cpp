#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(const point_t &position, const double width, const double height) :
  position_(position),
  width_(width),
  height_(height)
{
    if(width_ <= 0.0)
    {
      width_ = 0.0;
      
      throw std::invalid_argument("Error. Width can't be <= 0");
    }
    
    if(height_ <= 0.0)
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
  rectangle_t frameRectangle;
  frameRectangle.height = height_;
  frameRectangle.width = width_;
  frameRectangle.position = position_;

  return frameRectangle;
}

void Rectangle::move(const point_t &positionNew)
{
  position_ = positionNew;
}

void Rectangle::move(const double &deltaX, const double &deltaY)
{
  position_.x += deltaX;
  position_.y += deltaY;
}

void Rectangle::getInfo() const
{
  std::cout << "This is rectangle." << std::endl;
  std::cout << "Width: " << width_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Center: " << "(" << position_.x << ", " << position_.y << ")" << std::endl;
}