#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual void move(const point_t& center) = 0;
  virtual void move(const double dx, const double dy) = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual double getArea() const = 0;
  virtual void showData(std::ostream& out) const = 0;
};

#endif
