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

void Shape::printFrame(std::ostream & out) const
{
  out << "Frame width = " << getFrameRect().width << ", height = " << getFrameRect().height << "\n";
  printPoint(out);
}

void Shape::printPoint(std::ostream & out) const
{
  out << "Position: (" << pos_.x << ";" << pos_.y << ")";
}
