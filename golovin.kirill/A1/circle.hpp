#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape {
public:
  Circle(const point_t &, double);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

private:
  double radius_;
};

#endif
