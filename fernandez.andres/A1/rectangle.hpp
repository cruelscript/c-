#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <iostream>

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& position, const double width, const double height);

  virtual double getArea() const;

  virtual rectangle_t getFrameRect() const override;

  virtual void print() const override;

private:
  double width_;
  double height_;
};

#endif
