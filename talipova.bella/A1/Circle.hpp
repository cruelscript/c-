#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle :
  public Shape
{
public:
  Circle(const double x, const double y, const double radius);
  Circle(const point_t pos, const double radius);
  rectangle_t getFrameRect() const override;
  double getArea() const override;
private:
  double radius_;
};

#endif
