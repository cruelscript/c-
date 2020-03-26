#ifndef A1_SHAPE_HPP
#define A1_SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  void move(const point_t &);

  void move(double dX, double dY);

  point_t getPos() const;

protected:
  point_t center_;

  explicit Shape(const point_t &);
};

#endif
