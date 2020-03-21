#ifndef CIRCLE
#define CIRCLE

#include "shape.h"
#include "base-types.h"
class Circle : public Shape
{
public:
  Circle(const point_t &center, const double &radius);
  ~Circle();
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(const double &xOffset, const double &yOffset) override;
private:
  point_t center_;
  double radius_;
  Circle(const Circle &circle);
  Circle(Circle &&circle);
};
#endif 
