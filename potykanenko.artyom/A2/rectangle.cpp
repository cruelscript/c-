#include "rectangle.hpp"
#include <stdexcept>

namespace potykanenko
{
  Rectangle::Rectangle(const double width, const double height, const double x, const double y) :
    Rectangle(width, height, { x, y })
  {}

  Rectangle::Rectangle(const double width, const double height, const point_t &pos) :
    rect_{ width, height, pos }
  {
    if (width <= 0.0)
    {
      throw std::invalid_argument("Error: invalid width");
    }
    if (height <= 0.0)
    {
      throw std::invalid_argument("Error: invalid height");
    }
  }

  double Rectangle::getArea() const
  {
    return rect_.width * rect_.height;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return rect_;
  }

  void Rectangle::move(const double dx, const double dy)
  {
    rect_.pos.x += dx;
    rect_.pos.y += dy;
  }

  void Rectangle::move(const point_t &point)
  {
    rect_.pos = point;
  }

  void Rectangle::scale(const double coefficient)
  {
    if (coefficient <= 0.0)
    {
      throw std::invalid_argument("Error: invalid coefficient for rectangle");
    }
    rect_.height *= coefficient;
    rect_.width *= coefficient;
  }
}
