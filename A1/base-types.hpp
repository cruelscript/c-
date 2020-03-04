#ifndef FIRSTLAB_BASE_TYPES_HPP
#define FIRSTLAB_BASE_TYPES_HPP

struct point_t
{
public:
  double x_;
  double y_;
};

struct rectangle_t
{
public:
  double width_;
  double height_;
  point_t pos_;
};

#endif
