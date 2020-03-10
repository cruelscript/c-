#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t& pos, const double radius);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void print() const;
private:
  double radius_;
};
#endif
