#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace gromova
{
  class Rectangle :
    public Shape
  {
  public:
    Rectangle(const double height, const double width, const point_t& centre);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(const double dx, const double dy) override;
    void scale(const double k) override;

  private:
    double height_;
    double width_;
    point_t centre_;
  };
}

#endif
