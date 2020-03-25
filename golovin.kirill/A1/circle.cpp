#include "circle.hpp"
#include <cmath>
#include <cassert>

Circle::Circle(const point_t &center, double radius):
  Shape(center),
  radius_(radius) {
  assert(radius_ > 0.0);
}

double Circle::getArea() const {
  return M_PI * pow(radius_, 2);
}

rectangle_t Circle::getFrameRect() const {
  return {2 * radius_, 2 * radius_, center_};
}
