#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(const point_t & destination) = 0;
  virtual void move(double deltaX, double deltaY) = 0;
}

#endif
