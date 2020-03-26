#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
#include <iostream>

class Shape
{
public:
  virtual ~Shape() = default;

  virtual void move(const point_t& newPosition);

  virtual void move(const double dx, const double dy);

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  virtual void print() const = 0;

protected:
  Shape(const point_t& position);
  point_t position_;
};

#endif

