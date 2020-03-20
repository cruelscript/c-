#include "Shape.hpp"

Shape::Shape(const point_t point) :
  pos_(point)
{}

void Shape::move(const double& dx, const double& dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Shape::move(const point_t& point)
{
  pos_ = point;
}

point_t Shape::getPosition() const
{
  return pos_;
}
