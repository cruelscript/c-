#include "shape.hpp"

Shape::Shape(const point_t& position) :
  position_(position)
{}

void Shape::move(const point_t& newPosition)
{
  position_ = newPosition;
}

void Shape::move(const double dx, const double dy)
{
  position_.x += dx;
  position_.y += dy;
}
