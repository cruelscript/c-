#include "circle.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

namespace shcherbinin
{
  Circle::Circle(double radius, double x, double y) :
    Circle(radius, {x, y})
  {}

  Circle::Circle(double radius, const point_t &center) :
    radius_(radius),
    center_(center)
  {
    if (radius <= 0.0)
    {
      throw std::invalid_argument("ERROR: radius can't be <= 0.0");
    }
  }

  double Circle::getArea() const
  {
    return (M_PI * radius_ * radius_);
  }

  rectangle_t Circle::getFrameRect() const
  {
    double side = radius_ * 2;
    return {side, side, center_};
  }

  void Circle::move(const point_t &point)
  {
    center_ = point;
  }

  void Circle::move(double dX, double dY)
  {
    center_.x += dX;
    center_.y += dY;
  }

  void Circle::scale(double coefficient)
  {
    if (coefficient <= 0.0)
    {
      throw std::invalid_argument("ERROR: coefficient can't be <= 0.0");
    }

    radius_ *= coefficient;
  }
}
