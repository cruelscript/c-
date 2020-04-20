#ifndef SECOND_GIT__BASE_TYPES_HPP_
#define SECOND_GIT__BASE_TYPES_HPP_

namespace gulyaev
{
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
}

#endif //SECOND_GIT__BASE_TYPES_HPP_
