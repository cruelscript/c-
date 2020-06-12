#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>

namespace vinokurov
{
  struct point_t;
  struct rectangle_t;

  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newCenter) = 0;
    virtual void move(double deltaX, double deltaY) noexcept = 0;
    virtual void print(std::ostream& out) const = 0;
    virtual void scale(double coefficient) = 0;
    virtual void rotate(double angle) = 0;
  };
}

#endif
