#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iostream>

struct point_t
{
  double x;
  double y;

  friend std::ostream& operator<<(std::ostream &out, const point_t &point)
  {
    out << '(' << point.x << ", " << point.y << ')';
    return out;
  }
};

struct rectangle_t
{
  point_t pos;
  double width;
  double height;
};

#endif
