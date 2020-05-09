#ifndef A1__CIRCLE_HPP_
#define A1__CIRCLE_HPP_
#include "shape.hpp"
#include "base-types.hpp"

namespace  shcherbinin
{
  class Circle : public Shape
  {

   public:
    Circle(double radius, double x, double y);
    Circle(double radius, const point_t &center);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dX, double dY) override;
    void scale(double coefficient) override;
   private:
    double radius_;
    point_t center_;
  };
}

#endif //A1__CIRCLE_HPP_
