#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace gyrlov
{
  class Rectangle : public Shape 
  {
  public:
    Rectangle(const point_t&, const double width, const double height);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const point_t&) override;
    void scale(const double) override;
    void print(std::ostream&) const override;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}
#endif
