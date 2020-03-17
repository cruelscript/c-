#ifndef A1_CIRCLE
#define A1_CIRCLE

#include "base-types.hpp"
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t& center, double radius);
  Circle(double x, double y, double radius);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPos() const override;
  void move(const point_t& center) override;
  void move(double deltaX, double deltaY) override;

private:
  point_t center_;
  double radius_;
};

#endif
