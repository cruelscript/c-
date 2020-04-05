#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle :
  public Shape
{
public:
  Rectangle(const point_t &center, const double w, const double h);
  void move(const point_t &center) override;
  void move(const double dx, const double dy) override;
  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void showData(std::ostream& out) const override;
private:
  point_t center_;
  double width_;
  double height_;
};

#endif
