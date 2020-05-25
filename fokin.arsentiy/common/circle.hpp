#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace fokin
{
  class Circle : public Shape
  {
  public:

    Circle(const point_t& center, const double radius);

    double getArea() const noexcept override;

    point_t getCenter() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t& newCenter) override;

    void move(const double dx, const double dy) noexcept override;

    void scale(const double coefficient) override;

  private:

    point_t center_;

    double radius_;
  };
}

#endif
