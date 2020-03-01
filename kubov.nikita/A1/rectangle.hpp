#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include <iostream>

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &position, const double width, const double height);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &positionNew) override;
  virtual void move(const double &deltaX, const double &deltaY) override;
  virtual void getInfo() const override;

private:
  point_t position_;
  double width_;
  double height_;

};
#endif


