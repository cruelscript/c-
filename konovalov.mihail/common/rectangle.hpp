#ifndef SPBSPU_LABS_2020_202_1_RECTANGLE_HPP
#define SPBSPU_LABS_2020_202_1_RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace konovalov
{
  class Rectangle : public Shape
  {
  public:

    Rectangle(double width, double height, const point_t &center);

    double getHeight() const noexcept;

    double getWidth() const noexcept;

    double getArea() const noexcept override;

    point_t getCenterPoint() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t &point) noexcept override;

    void move(double dx, double dy) noexcept override;

    void scale(double coefficient) override;

  private:
    point_t vertices_[4];
  };
}
#endif
