#ifndef A1_RECTANGLE
#define A1_RECTANGLE

#include "base-types.hpp"
#include "shape.hpp"

class Rectangle:public Shape
{
public:
  Rectangle(const point_t& pos, double width, double height);
  Rectangle(double x, double y, double width, double height);

  double getArea() const override;
  rectangle_t getFrameRect()const override;
  point_t getPos() const override;
  void move(const point_t& center) override;
  void move(double deltaX, double deltaY) override;

private:
  point_t center_;
  double width_;
  double height_;
};

#endif