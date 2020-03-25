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
  center_.x_ += dX;
  center_.y_ += dY;
}

point_t Shape::getPos() const
{
  return center_;
}
