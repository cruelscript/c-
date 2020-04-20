#ifndef SECOND_GIT__SHAPE_HPP_
#define SECOND_GIT__SHAPE_HPP_

#include "base-types.hpp"

namespace gulyaev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    
    virtual double getArea() const = 0;
    
    virtual rectangle_t getFrameRect() const = 0;
    
    virtual void move(const point_t &point) = 0;
    
    virtual void move(double deltaX, double deltaY) = 0;
    
    virtual void scale(const double coefficient) = 0;
  };
}

#endif //SECOND_GIT__SHAPE_HPP_
