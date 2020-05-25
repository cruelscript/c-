#ifndef SECOND_GIT__CIRCLE_HPP_
#define SECOND_GIT__CIRCLE_HPP_

#include "shape.hpp"
#include "base-types.hpp"

namespace gulyaev
{
  class Circle : public Shape
  {
  public:
    Circle(double radius, const point_t &center);
    
    Circle(double radius, double x, double y);
    
    double getArea() const noexcept override;
    
    rectangle_t getFrameRect() const override;
    
    void move(const point_t &point) noexcept override;
    
    void move(double deltaX, double deltaY) noexcept override;
    
    void scale(const double coefficient) override;
  
  private:
    double radius_;
    point_t center_;
  };
  
}

#endif //SECOND_GIT__CIRCLE_HPP_
