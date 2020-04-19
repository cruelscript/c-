#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace vinokurov
{
  class Rectangle : public vinokurov::Shape
  {
  public:
    Rectangle(const point_t& pos, const double width, const double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void print(std::ostream& out) const override;
    void scale(const double coefficient) override;
  private:
    double width_;
    double height_;
  };
}
#endif
