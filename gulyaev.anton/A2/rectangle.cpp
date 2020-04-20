#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

namespace gulyaev
{
  Rectangle::Rectangle(double width, double height, double x, double y) :
    Rectangle(width, height, {x, y})
  {}
  
  Rectangle::Rectangle(double width, double height, const point_t &center) :
    width_(width),
    height_(height),
    pos_(center)
  {
    if (width <= 0.0)
    {
      throw std::invalid_argument("Oops. Width can't be <= 0.0");
    }
    if (height <= 0.0)
    {
      throw std::invalid_argument("Oops. Height can't be <= 0.0");
    }
  }
  
  double Rectangle::getArea() const
  {
    return width_ * height_;
  }
  
  rectangle_t Rectangle::getFrameRect() const
  {
    return {width_, height_, pos_};
  }
  
  void Rectangle::move(const point_t &point)
  {
    pos_ = point;
  }
  
  void Rectangle::move(double deltaX, double deltaY)
  {
    pos_.x += deltaX;
    pos_.y += deltaY;
  }
  
  void Rectangle::scale(const double coefficient)
  {
    if (coefficient <= 0.0)
    {
      throw std::invalid_argument("Oops. Height can't be <= 0.0");
    }
    width_ *= coefficient;
    height_ *= coefficient;
  }
}
