#ifndef A1__RECTANGLE_HPP_
#define A1__RECTANGLE_HPP_
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, const point_t& center);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newCenter) override;
  void move(double shiftX, double shiftY) override;
  const char* getName() const override;

private:
  double width_;
  double height_;
  point_t center_;
};

#endif //A1__RECTANGLE_HPP_
