#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <iostream>

class Circle : public Shape
{
public:
  Circle(const point_t &position, const double radius);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t &positionNew) override;
  virtual void move(const double &deltaX, const double &deltaY) override;
  virtual void getInfo() const override;
private:
  point_t position_;
  double radius_;

};
#endif


