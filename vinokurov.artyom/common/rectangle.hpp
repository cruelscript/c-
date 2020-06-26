#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace vinokurov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& center);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& newCenter) noexcept override;
    void move(double deltaX, double deltaY) noexcept override;
    void print(std::ostream& out) const override;
    void scale(double coefficient) override;
    void rotate(double angle) noexcept override;
  private:
    point_t vertices_[4];
    double width() const noexcept;
    double height() const noexcept;
    point_t center() const noexcept;
  };
}

#endif
