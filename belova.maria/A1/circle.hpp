#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle :
  public Shape
{
public:
  Circle(const point_t &center, const double radius);
  void move(const point_t &center) override;
  void move(const double dx, const double dy) override;
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void showData(std::ostream& out) const override;
private:
  point_t center_;
  double radius_;
};

#endif
