#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& pos, const double width, const double height);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void print() const;
private:
  double width_;
  double height_;
};
#endif //! RECTANGLE_HPP