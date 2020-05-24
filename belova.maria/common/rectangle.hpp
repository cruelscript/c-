#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace belova
{
  class Rectangle :
    public Shape
  {
  public:
    Rectangle(const point_t& center, const double w, const double h);
    Rectangle(const double x, const double y, const double w, const double h);
    void move(const point_t& center) noexcept override;
    void move(const double dx, const double dy) noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    double getArea() const noexcept override;
    void showData(std::ostream& out) const override;
    void scale(const double coeff) override;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}
#endif
