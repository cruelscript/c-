#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ostream>

namespace kubov
{
  struct rectangle_t;
  struct point_t;

  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual point_t getCenter() const noexcept = 0;
    virtual void move(const point_t &positionNew) noexcept = 0;
    virtual void move(const double deltaX, const double deltaY) noexcept = 0;
    virtual void print(std::ostream &out) const = 0;
    virtual void scale(const double coefficient) = 0;
  };
}
#endif
