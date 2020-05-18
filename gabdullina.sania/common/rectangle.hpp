#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace gabdullina
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& center, double width, double height);
    Rectangle(double x, double y, double width, double height);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getPos() const override;
    void showParameters(std::ostream &out) const override;
    void move(const point_t& center) override;
    void move(double deltaX, double deltaY) override;
    void scale(double scalingFactor) override;

  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif
