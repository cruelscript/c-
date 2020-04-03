#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle :
  public Shape
{
public:
  Circle(const double radius, const point_t& centre);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(const double dx, const double dy) override;

private:
  double radius_;
  point_t centre_;
};

#endif
