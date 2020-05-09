#ifndef A1__BASE_TYPES_HPP_
#define A1__BASE_TYPES_HPP_

namespace shcherbinin
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}

#endif //A1__BASE_TYPES_HPP_
