#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include "base-types.hpp"

namespace vinokurov
{
  class Shape
  {
  public:
    Shape(const point_t& pos);
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void print(std::ostream& out) const = 0;
    virtual void move(const double deltaX, const double deltaY);
    virtual void move(const point_t& point);
    virtual void scale(const double coefficient) = 0;
  protected:
    point_t pos_;
  };
}
#endif
