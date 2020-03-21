#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t & position, double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print() const override;
  double getRadius() const;

private:
  double radius_;
};

#endif
