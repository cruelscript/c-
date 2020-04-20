#ifndef A1__SHAPE_HPP_
#define A1__SHAPE_HPP_
#include <iosfwd>
#include "base-types.hpp"

namespace shevtsov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual shevtsov::rectangle_t getFrameRect() const = 0;
    virtual void move(const shevtsov::point_t& newCenter) = 0;
    virtual void move(const double shiftX, const double shiftY) = 0;
    virtual void scale(const double scaleRate) = 0;
    virtual void printInfo(std::ostream& out) const = 0;
  };
}

#endif //A1__SHAPE_HPP_
