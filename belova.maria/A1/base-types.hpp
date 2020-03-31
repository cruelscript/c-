#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iostream>

struct point_t
{
  double x_;
  double y_;

  friend std::ostream& operator<<(std::ostream &out, const point_t &point)
  {
    out << '(' << point.x_ << ", " << point.y_ << ')';
    return out;
  }
};

struct rectangle_t
{
  point_t pos_;
  double width_;
  double height_;
};

#endif
