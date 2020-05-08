#include "shape.hpp"

prishchepa::Shape::Shape(const prishchepa::point_t & position) :
  pos_(position) {}

void prishchepa::Shape::move(const prishchepa::point_t & destination)
{
  pos_ = destination;
}

void prishchepa::Shape::move(double deltaX, double deltaY)
{
  pos_.x += deltaX;
  pos_.y += deltaY;
}

prishchepa::point_t prishchepa::Shape::getPosition() const
{
  return pos_;
}
