#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const double width, const double height, const point_t& pos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print() const override;
  void move(const double dx, const double dy) override;
  void move(const point_t& position) override;
private:
  double height_;
  double width_;
  point_t pos_;
};
#endif // !RECTANGLE_HPP_
