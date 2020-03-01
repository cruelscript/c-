#ifndef PROJECT1_CIRCLE_HPP
#define PROJECT1_CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double radius, const point_t &center);

  Circle(double radius, double x, double y);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &point) override;

  void move(double x, double y) override;

  point_t getPoint() const override;

private:
  double radius_;
  point_t center_;
};

#endif //PROJECT1_CIRCLE_HPP
