#ifndef A1_SHAPE_HPP
#define A1_SHAPE_HPP

#include "base-types.hpp"

namespace golovin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void scale(double) = 0;

    virtual void move(const point_t &);

    virtual void move(double dX, double dY);

  protected:
    point_t center_;

    explicit Shape(const point_t &);
  };
}
#endif
