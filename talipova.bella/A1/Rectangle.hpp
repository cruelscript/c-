#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"
class Rectangle :
  public Shape
{
public:
  Rectangle(const double x, const double y, const double w, const double h);
  Rectangle(const point_t pos, const double w, const double h);
  double getArea() const override;
  rectangle_t getFrameRect() const override;	
private:
  double width_;
  double height_;
};

#endif
