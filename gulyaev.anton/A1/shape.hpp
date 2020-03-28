#ifndef PROJECT1_SHAPE_HPP
#define PROJECT1_SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  virtual void move(const point_t &point) = 0;

  virtual void move(double deltaX, double deltaY) = 0;
};

#endif //PROJECT1_SHAPE_HPP
