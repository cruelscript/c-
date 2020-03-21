#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  Shape(const point_t & position);
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void print() const = 0;
  virtual void move(const point_t & destination);
  virtual void move(double deltaX, double deltaY);
  point_t getPosition() const;

protected:
  point_t pos_;
};

#endif
