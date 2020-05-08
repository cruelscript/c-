#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include "base-types.hpp"

namespace prishchepa
{
  class Shape
  {
  public:
    Shape(const point_t & position);
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void print(std::ostream & out) const = 0;
    virtual void scale(double factor) = 0;
    virtual void move(const point_t & destination);
    virtual void move(double deltaX, double deltaY);
    point_t getPosition() const;

  protected:
    point_t pos_;
  };
}

#endif
