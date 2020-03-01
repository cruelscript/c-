#ifndef PROJECT1_BASE_TYPES_HPP
#define PROJECT1_BASE_TYPES_HPP

struct point_t
{
  double x = 0;
  double y = 0;
};

struct rectangle_t
{
  double width = 0;
  double height = 0;
  point_t pos;
};
#endif //PROJECT1_BASE_TYPES_HPP
