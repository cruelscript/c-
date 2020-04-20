#ifndef A1__CIRCLE_HPP_
#define A1__CIRCLE_HPP_
#include "base-types.hpp"
#include "shape.hpp"

namespace shevtsov
{
  class Circle : public shevtsov::Shape
  {
  public:
    Circle(const double radius, const shevtsov::point_t& center);
    double getArea() const override;
    shevtsov::rectangle_t getFrameRect() const override;
    void move(const shevtsov::point_t& newCenter) override;
    void move(const double shiftX, const double shiftY) override;
    void scale(const double scaleRate) override;
    void printInfo(std::ostream& out) const override;

  private:
    double radius_;
    shevtsov::point_t center_;
  };
}

#endif //A1__CIRCLE_HPP_
