#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace golovin
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &, double);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void scale(double) override;

  private:
    double radius_;
  };
}
#endif
