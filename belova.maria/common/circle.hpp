#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace belova
{
  class Circle :
    public Shape
  {
  public:
    Circle(const point_t& center, const double radius);
    Circle(const double x, const double y, const double radius);
    void move(const point_t& center) noexcept override;
    void move(const double dx, const double dy) noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    double getArea() const noexcept override;
    void showData(std::ostream& out) const override;
    void scale(const double coeff) override;
  private:
    point_t center_;
    double radius_;
  };
}
#endif
