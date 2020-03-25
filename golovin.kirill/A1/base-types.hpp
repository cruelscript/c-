#ifndef A1_BASE_TYPES_HPP
#define A1_BASE_TYPES_HPP

class point_t
{
public:
  double x_;
  double y_;
};

class rectangle_t
{
public:
  double width_;
  double height_;
  point_t pos;
};

#endif
