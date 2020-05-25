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
    
    double getArea() const noexcept override;
    
    rectangle_t getFrameRect() const override;
  
    void move(const point_t &point) noexcept override;
    
    void move(double deltaX, double deltaY) noexcept override;
    
    void scale(const double coefficient) override;
  
  private:
    point_t top_[4];
    
    double getHeight() const noexcept;
    double getWidth() const noexcept;
    point_t getCenter() const noexcept;
  };
}

#endif //SECOND_GIT__RECTANGLE_HPP_
