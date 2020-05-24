#ifndef SPBSPU_LABS_2020_202_1_BASE_TYPES_HPP
#define SPBSPU_LABS_2020_202_1_BASE_TYPES_HPP

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
