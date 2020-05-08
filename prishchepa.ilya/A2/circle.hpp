#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iosfwd>
#include "base-types.hpp"
#include "shape.hpp"

namespace prishchepa
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t & position, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void print(std::ostream & out) const override;
    void scale(double factor) override;
    double getRadius() const;

  private:
    double radius_;
  };
}

#endif
