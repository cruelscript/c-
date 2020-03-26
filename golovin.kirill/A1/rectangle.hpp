#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &, double width, double height);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

private:
  double width_;
  double height_;
};

#endif
