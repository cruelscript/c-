#ifndef A1__CIRCLE_HPP_
#define A1__CIRCLE_HPP_
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(double radius, const point_t& center);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newCenter) override;
  void move(double shiftX, double shiftY) override;
  const char* getName() const override;

private:
  double radius_;
  point_t center_;
};

#endif //A1__CIRCLE_HPP_
