#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t & position, double width, double height);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print(std::ostream & out) const override;
  double getWidth() const;
  double getHeight() const;

private:
  double width_;
  double height_;
};

#endif
