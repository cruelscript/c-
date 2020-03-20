#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle :
  public Shape
{
public:
  Rectangle(const double x, const double y, const double w, const double h);
  Rectangle(const point_t pos, const double w, const double h);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double &dx, const double &dy) override;
  void move(const point_t &point) override;
  point_t getPosition() const override;
private:
  point_t pos_;
  double width_;
  double height_;
};
#endif
