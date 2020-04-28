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
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(const double dx, const double dy) override;
    void scale(const double coefficient) override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
