#ifndef FIRSTLAB_RECTANGLE_HPP
#define FIRSTLAB_RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:

  explicit Rectangle(const rectangle_t &rectangle);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &point) override;

  void move(double dx, double dy) override;

private:
  rectangle_t rectangle_;
};

#endif
