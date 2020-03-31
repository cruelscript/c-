#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle :
  public Shape
{
public:
  Circle(const point_t &center, const double radius);

  point_t getCenter() const;
  double getRadius() const;

  void move(const point_t &center);
  void move(const double dx, const double dy);
  rectangle_t getFrameRect() const;
  double getArea() const;
  void showData() const;
private:
  point_t center_;
  double radius_;
};

#endif
