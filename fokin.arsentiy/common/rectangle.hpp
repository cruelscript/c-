#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace fokin
{
  class Rectangle : public Shape
  {
  public:

    Rectangle(const double width, const double height, const point_t& center);

    double getWidth() const noexcept;

    double getHeight() const noexcept;

    double getArea() const noexcept override;

    point_t getCenter() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t& newPos) override;

    void move(const double dx, const double dy) noexcept override;

    void scale(const double coefficient) override;

  private:

    point_t vertex_[4];
  };
}

#endif
