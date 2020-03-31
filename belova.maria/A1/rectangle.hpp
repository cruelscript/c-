#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle :
  public Shape
{
public:
  Rectangle(const point_t &center, const double w, const double h);

  point_t getCenter() const;
  double getWidth() const;
  double getHeight() const;

  void move(const point_t &center);
  void move(const double dx, const double dy);
  rectangle_t getFrameRect() const;
  double getArea() const;
  void showData() const;
private:
  point_t center_;
  double width_;
  double height_;
};

#endif
