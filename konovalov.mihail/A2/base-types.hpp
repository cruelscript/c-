#ifndef FIRSTLAB_BASE_TYPES_HPP
#define FIRSTLAB_BASE_TYPES_HPP

namespace konovalov
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
#endif
