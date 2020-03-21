#ifndef RECTANGLE
#define RECTANGLE

#include "shape.h"
#include "base-types.h"
class Rectangle: public Shape
{
public:
  Rectangle(const point_t &center, const double &w, const double &h);
  ~Rectangle();
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(const double &xOffset, const double &yOffset) override;
private:
  point_t center_;
  double width_;
  double height_;
  Rectangle(const Rectangle &rectangle);
  Rectangle(Rectangle &&rectangle);
};
#endif 
