#include "shape.hpp"

golovin::Shape::Shape(const point_t &center):
  center_(center)
{
}

void golovin::Shape::move(const point_t &destinationPoint)
{
  center_ = destinationPoint;
}

void golovin::Shape::move(double dX, double dY)
{
  center_.x += dX;
  center_.y += dY;
}
