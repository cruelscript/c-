#include "shape.hpp"

Shape::Shape(const point_t& point) :
  pos_(point) {}

void Shape::move(const double deltaX, const double deltaY)
{
  pos_.x += deltaX;
  pos_.y += deltaY;
}

void Shape::move(const point_t & point)
{
  pos_ = point;
}
