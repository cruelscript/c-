#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& position, const double width, const double height);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void print(std::ostream & out) const override;

private:
  double width_;
  double height_;
};

#endif
