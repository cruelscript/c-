#include "shape.hpp"
#include "base-types.hpp"

vinokurov::Shape::Shape(const point_t& point) :
  pos_(point) {}

void vinokurov::Shape::move(const double deltaX, const double deltaY)
{
  pos_.x += deltaX;
  pos_.y += deltaY;
}

void vinokurov::Shape::move(const point_t & point)
{
  pos_ = point;
}
