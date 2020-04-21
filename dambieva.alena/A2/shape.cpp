#include "shape.hpp"
#include <ostream>

dambieva::Shape::Shape(const point_t & pos) :
  pos_(pos)
{}

void dambieva::Shape::move(const point_t & newPos)
{
  pos_ = newPos;
}

void dambieva::Shape::move(double deltaX, double deltaY)
{
  pos_.x += deltaX;
  pos_.y += deltaY;
}

dambieva::point_t dambieva::Shape::getPos() const
{
  return pos_;
}
