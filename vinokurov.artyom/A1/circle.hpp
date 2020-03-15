#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t& pos, const double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print() const override;
private:
  double radius_;
};
#endif
