#ifndef PROJECT1_RECTANGLE_HPP
#define PROJECT1_RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, double x, double y);

  Rectangle(double width, double height, const point_t &center);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &point) override;

  void move(double deltaX, double deltaY) override;

  point_t getPoint() const override;

private:
  rectangle_t rectangle_;
};

#endif //PROJECT1_RECTANGLE_HPP
