#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <iosfwd>
#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t & position, double radius);
  Circle(const double x, const double y, double radius);

  double getRadius() const;
  void setRadius(double radius);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print(std::ostream & out) const override;
private:
  double radius_;
};

#endif
