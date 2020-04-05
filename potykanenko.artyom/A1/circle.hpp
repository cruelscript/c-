#ifndef CIRCLE_CPP
#define CIRCLE_CPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const double rad, const double x, const double y);
  Circle(const double rad, const point_t &point);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t &point) override;
private:
  double radius_;
  point_t center_;
};

#endif
