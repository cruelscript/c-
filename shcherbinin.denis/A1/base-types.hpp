#ifndef A1__BASE_TYPES_HPP_
#define A1__BASE_TYPES_HPP_

struct point_t {
  double x = 0.0;
  double y = 0.0;
};

struct rectangle_t {
  double width = 0.0;
  double height = 0.0;
  point_t pos;
};

#endif //A1__BASE_TYPES_HPP_
