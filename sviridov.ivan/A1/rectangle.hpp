#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &centre, double width, double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& point) override;
  void move(const double dx, const double dy) override;
  point_t getCentre() const override;
  void show_frame(Shape* figure) const;
  void show_position(Shape* figure) const;
private:
  double width_;
  double height_;
  point_t centre_;
};
#endif
