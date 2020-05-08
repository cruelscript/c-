#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace kubov
{
  class Rectangle : public kubov::Shape
  {
  public:
    Rectangle(const point_t &center, double width, double height);

    double getArea() const noexcept override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const noexcept override;
    double getHeight() const noexcept;
    double getWidth() const noexcept;

    void move(const point_t &positionNew) noexcept override;
    void move(const double deltaX, const double deltaY) noexcept override;
    void print(std::ostream &out) const override;
    void scale(const double coefficient) override;

  private:
    point_t peaks_[4];
  };
}
#endif
