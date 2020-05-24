#ifndef SPBSPU_LABS_2020_202_1_SHAPE_H
#define SPBSPU_LABS_2020_202_1_SHAPE_H

#include "base-types.hpp"

namespace konovalov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const noexcept = 0;

    virtual point_t getCenterPoint() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(const point_t &point) = 0;

    virtual void move(double dx, double dy) = 0;

    virtual void scale(double coefficient) = 0;
  };
}
#endif
