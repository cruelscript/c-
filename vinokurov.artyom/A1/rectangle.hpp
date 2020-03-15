#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& pos, const double width, const double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print() const override;
private:
  double width_;
  double height_;
};
#endif
