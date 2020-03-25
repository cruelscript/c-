#include "shape.hpp"

Shape::Shape(const point_t &center):
  center_(center)
{
}

void Shape::move(const point_t &destinationPoint)
{
  center_ = destinationPoint;
}

void Shape::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}

point_t Shape::getPos() const
{
  return center_;
}
