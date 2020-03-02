#ifndef A1__CIRCLE_HPP_
#define A1__CIRCLE_HPP_

#include <cmath>
#include <cassert>
#include "shape.hpp"

class Circle : public Shape {

 public:
  Circle(double radius, double x, double y);
  Circle(double radius, const point_t &center);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(double dX, double dY) override;

  point_t getPoint() const override;

 private:
  double radius_;
  point_t center_;
};

#endif //A1__CIRCLE_HPP_
