#ifndef A1__SHAPE_HPP_
#define A1__SHAPE_HPP_
#include "base-types.hpp"

class Shape
{
 public:

  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &point) = 0;
  virtual void move(double dX, double dY) = 0;
};

#endif //A1__SHAPE_HPP_
