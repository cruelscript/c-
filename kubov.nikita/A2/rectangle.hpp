#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace kubov
{

class Rectangle : public kubov::Shape
{
public:
  Rectangle(const point_t &center, double width, double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &positionNew) override;
  void move(const double deltaX, const double deltaY) override;
  void print() const override;
  void scale(const double coefficient) override;

private:
  point_t center_;
  double width_;
  double height_;

};

}
#endif


