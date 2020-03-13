#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &center, double width, double height);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &positionNew) override;
  virtual void move(const double &deltaX, const double &deltaY) override;
  virtual void print() const override;

private:
  point_t center_;
  double width_;
  double height_;

};
#endif


