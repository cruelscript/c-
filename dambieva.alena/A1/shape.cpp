#include "shape.hpp"
#include <ostream>

Shape::Shape(const point_t & pos) :
  pos_(pos)
{}

void Shape::move(const point_t & newPos)
{
  pos_ = newPos;
}

void Shape::move(double deltaX, double deltaY)
{
  pos_.x += deltaX;
  pos_.y += deltaY;
}

point_t Shape::getPos() const
{
  return pos_;
}
