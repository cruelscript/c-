#ifndef A1__RECTANGLE_HPP_
#define A1__RECTANGLE_HPP_
#include "base-types.hpp"
#include "shape.hpp"

namespace shevtsov
{
  class Rectangle : public shevtsov::Shape
  {
  public:
    Rectangle(const double width, const double height, const shevtsov::point_t& center);
    double getArea() const override;
    shevtsov::rectangle_t getFrameRect() const override;
    void move(const shevtsov::point_t& newCenter) override;
    void move(const double shiftX, const double shiftY) override;
    void scale(const double scaleRate) override;
    void printInfo(std::ostream& out) const override;

  private:
    double width_;
    double height_;
    shevtsov::point_t center_;
  };
}

#endif //A1__RECTANGLE_HPP_
