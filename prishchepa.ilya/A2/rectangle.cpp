#include "rectangle.hpp"

#include <cassert>
#include <ostream>
#include <stdexcept>

prishchepa::Rectangle::Rectangle(const prishchepa::point_t & position, double width, double height) :
  Shape(position),
  width_(width),
  height_(height)
{
  if (width <= 0.0)
  {
    throw std::invalid_argument("Width is less than or equal to zero");
  }

  if (height <= 0.0)
  {
    throw std::invalid_argument("Height is less than or equal to zero");
  }
}

double prishchepa::Rectangle::getArea() const
{
  return width_ * height_;
}

prishchepa::rectangle_t prishchepa::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void prishchepa::Rectangle::print(std::ostream & out) const
{
  out << "Rectangle " << width_ << "x" << height_ << " at (" << pos_.x << "; " << pos_.y << ")";
}

void prishchepa::Rectangle::scale(double factor)
{
  if (factor <= 0.0)
  {
    throw std::invalid_argument("Factor is less than or equal to zero");
  }

  width_ *= factor;
  height_ *= factor;
}

double prishchepa::Rectangle::getWidth() const
{
  return width_;
}

double prishchepa::Rectangle::getHeight() const
{
  return height_;
}
