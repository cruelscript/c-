#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

class Circle :
  public Shape
{
public:
  Circle(const double x, const double y, const double radius);
  Circle(const point_t &pos, const double radius);
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void move(const double& dx, const double& dy) override;
  void move(const point_t& point) override;
  point_t getPosition() const override;
private:
  point_t pos_;
  double radius_;
};

#endif
