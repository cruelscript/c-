#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace gyrlov
{
  class Circle : public Shape 
  {
  public:
    Circle(const point_t&, const double);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const point_t&) override;
    void scale(const double) override;
    void print(std::ostream&) const override;
  private:
    point_t center_;
    double radius_;
  };
}
#endif 
