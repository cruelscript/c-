#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iosfwd>
#include "shape.hpp"
#include "base-types.hpp"

namespace fernandez
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t& position, const double radius);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void print(std::ostream & out) const override;

    void scale(const double factor) override;

    void move(const point_t& newPosition) override;

    void move(const double dx, const double dy) override;

    point_t getPos() const override;

  private:
    double radius_;
    point_t center_;
  };
}

#endif
