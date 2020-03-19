#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace kubov
{
  class Circle : public kubov::Shape
  {
  public:
    Circle(const point_t &center, const double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &positionNew) override;
    void move(const double deltaX, const double deltaY) override;
    void print(std::ostream &out) const override;
    void scale(const double coefficient) override;

  private:
    point_t center_;
    double radius_;

};
}
#endif


