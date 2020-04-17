#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iosfwd>
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t & pos, double width, double height);
  Rectangle(double x, double y, double width, double height);

  rectangle_t getFrameRect() const override;
  double getArea() const override;
  void print(std::ostream & out) const override;
  double getWidth() const;
  double getHeight() const;
  void setWidth(double width);
  void setHeight(double height);
private:
  double width_;
  double height_;
};

#endif
