#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iosfwd>
#include "base-types.hpp"

namespace dambieva
{
  class Shape
  {
  public:
    Shape(const point_t & pos);
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & newPos);
    virtual void move(double deltaX, double deltaY);
    virtual void scale(const double coefficient) = 0;

    virtual void print(std::ostream & out) const = 0;
    point_t getPos() const;
  protected:
    point_t pos_;
  };
}

#endif
