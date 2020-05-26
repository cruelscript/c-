#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace vinokurov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& center);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(double deltaX, double deltaY) override;
    void print(std::ostream& out) const override;
    void scale(double coefficient) override;
    void rotate(double angle) override;
  private:
    point_t vertex_[4];
    double width() const;
    double height() const;
    point_t center() const;
  };
}

#endif
