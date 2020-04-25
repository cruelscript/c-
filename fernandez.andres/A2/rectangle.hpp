#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"
#include "base-types.hpp"

namespace fernandez
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& position, const double width, const double height);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void print(std::ostream & out) const override;

    void scale(const double factor) override;

    void move(const point_t& newPosition) override;

    void move(const double dx, const double dy) override;

    point_t getPos() const override;
  private:
    double width_;
    double height_;
    point_t position_;
  };
}

#endif
