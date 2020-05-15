#ifndef RECTANGLE
#define RECTANGLE

#include "shape.hpp"
#include "base-types.hpp"

namespace savenkova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& center, const double& w, const double& h);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(const double xOffset, const double yOffset) override;
    void scale(const double coefficient) override;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}
#endif 
