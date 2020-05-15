#ifndef CIRCLE
#define CIRCLE

#include "shape.hpp"
#include "base-types.hpp"

namespace savenkova
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t& center, const double& radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(const double xOffset, const double yOffset) override;
    void scale(const double coefficient) override;
  private:
    point_t center_;
    double radius_;
  };
}
#endif 
