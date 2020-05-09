#ifndef A1__RECTANGLE_HPP_
#define A1__RECTANGLE_HPP_
#include "shape.hpp"
#include "base-types.hpp"

namespace shcherbinin
{
  class Rectangle : public Shape
  {

   public:

    Rectangle(double width, double height, double x, double y);
    Rectangle(double width, double height, const point_t &center);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dX, double dY) override;
    void scale(double coefficient) override;

   private:
    rectangle_t rectangle_;
  };
}

#endif //A1__RECTANGLE_HPP_
