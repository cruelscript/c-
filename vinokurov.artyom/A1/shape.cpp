#include "shape.hpp"

Shape::Shape(const point_t& point) :
  pos_(point) {}

void Shape::move(const double x, const double y)
{
  pos_.x = x;
  pos_.y = y;
}

void Shape::move(const point_t & point)
{
  pos_ = point;
}
