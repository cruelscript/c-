#ifndef FIRSTLAB_BASE_TYPES_HPP
#define FIRSTLAB_BASE_TYPES_HPP

struct point_t
{
public:
  double x;
  double y;
};

struct rectangle_t
{
public:
  double width;
  double height;
  point_t pos;
};

#endif
