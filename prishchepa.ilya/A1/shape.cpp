#include "shape.hpp"

Shape::Shape(const point_t & position) :
  pos_(position) {}

void Shape::move(const point_t & destination)
{
  pos_ = destination;
}

void Shape::move(double deltaX, double deltaY)
{
  pos_.x += deltaX;
  pos_.y += deltaY;
}

point_t Shape::getPosition() const
{
  return pos_;
}
