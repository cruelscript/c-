#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace gabdullina
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t& center, double radius);
    Circle(double x, double y, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getPos() const override;
    void showParameters(std::ostream &out) const override;
    void move(const point_t& center) override;
    void move(double deltaX, double deltaY) override;
    void scale(double scalingFactor) override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif
