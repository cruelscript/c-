#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace potykanenko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const double width, const double height, const double x, const double y);
    Rectangle(const double width, const double height, const point_t &pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const point_t &point) override;
    void scale(const double coefficient) override;
  private:
    rectangle_t rect_;
  };
}

#endif
