#ifndef BASE_TYPES
#define BASE_TYPES
struct point_t //точка с координатами
{
  double x;
  double y;
};
struct rectangle_t //прямоугольник с параметрами и центром
{
  double width;
  double height;
  point_t pos;
};
#endif
