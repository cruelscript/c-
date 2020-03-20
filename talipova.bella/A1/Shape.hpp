#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const double& dx, const double& dy);
  virtual void move(const point_t& point);
  virtual point_t getPosition() const;
protected:
  point_t pos_; 
  Shape(const point_t point);
};

#endif
