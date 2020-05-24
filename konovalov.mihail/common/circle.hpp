#ifndef SPBSPU_LABS_2020_202_1_CIRCLE_HPP
#define SPBSPU_LABS_2020_202_1_CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace konovalov
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, const point_t &center);

    double getArea() const noexcept override;

    point_t getCenterPoint() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t &point) noexcept override;

    void move(double dx, double dy) noexcept override;

    void scale(double coefficient) override;

  private:
    double radius_;
    point_t center_;
  };
}
#endif
