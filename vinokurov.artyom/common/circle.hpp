#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace vinokurov
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, const point_t& center);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(double deltaX, double deltaY) override;
    void print(std::ostream& out) const override;
    void scale(double coefficient) override;
    void rotate(double angle) override;
  private:
    double radius_;
    point_t center_;
  };
}

#endif
