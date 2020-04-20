#ifndef SECOND_GIT__RECTANGLE_HPP_
#define SECOND_GIT__RECTANGLE_HPP_

#include "shape.hpp"
#include "base-types.hpp"

namespace gulyaev
{
  
  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double height, double x, double y);
    
    Rectangle(double width, double height, const point_t &center);
    
    double getArea() const override;
    
    rectangle_t getFrameRect() const override;
    
    void move(const point_t &point) override;
    
    void move(double deltaX, double deltaY) override;
    
    void scale(const double coefficient) override;
  
  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif //SECOND_GIT__RECTANGLE_HPP_
