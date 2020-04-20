#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include "base-types.hpp"

namespace gabdullina
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual point_t getPos() const = 0;
    virtual void showParameters(std::ostream &out) const = 0;
    virtual void move(const point_t& center) = 0;
    virtual void move(double deltaX, double deltaY) = 0;
    virtual void scale(double scalingFactor) = 0;
  };
}

#endif
