#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

namespace shcherbinin
{
  Rectangle::Rectangle(double width, double height, double x, double y) :
    Rectangle(width, height, {x, y})
  {}

  Rectangle::Rectangle(double width, double height, const point_t &center) :
    rectangle_({width, height, center})
  {
    if (width <= 0.0)
    {
      throw std::invalid_argument("ERROR: width can't be <= 0.0");
    }
    if (height <= 0.0)
    {
      throw std::invalid_argument("ERROR: height can't be <= 0.0");
    }
  }

  double Rectangle::getArea() const
  {
    return (rectangle_.width * rectangle_.height);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return rectangle_;
  }

  void Rectangle::move(const point_t &point)
  {
    rectangle_.pos = point;
  }

  void Rectangle::move(double dX, double dY)
  {
    rectangle_.pos.x += dX;
    rectangle_.pos.y += dY;
  }

  void Rectangle::scale(double coefficient)
  {
    if (coefficient <= 0.0)
    {
      throw std::invalid_argument("ERROR: coefficient can't be <= 0.0");
    }

    rectangle_.width *= coefficient;
    rectangle_.height *= coefficient;
  }
}
