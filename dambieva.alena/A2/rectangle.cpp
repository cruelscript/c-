#include "rectangle.hpp"
#include <cassert>
#include <stdexcept>
#include <ostream>

dambieva::Rectangle::Rectangle(const point_t & pos, double width, double height) :
  Shape(pos),
  width_(width),
  height_(height)
{
  if (width <= 0)
  {
    throw std::invalid_argument("Error, invalid width");
  }

  if (height <= 0)
  {
    throw std::invalid_argument("Error, invalid height");
  }
}

dambieva::Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{}

dambieva::rectangle_t dambieva::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

double dambieva::Rectangle::getArea() const
{
  return width_ * height_;
}

void dambieva::Rectangle::print(std::ostream & out) const
{
  out << "Rectangle width = " << width_ << ", height = " << height_;
  out << "\n\tPosition: (" << pos_.x << ";" << pos_.y << ")";
}

void dambieva::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Error, invalid coefficient for rectangle");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

double dambieva::Rectangle::getWidth() const
{
  return width_;
}

double dambieva::Rectangle::getHeight() const
{
  return height_;
}

void dambieva::Rectangle::setWidth(double width)
{
  if (width <= 0)
  {
    throw std::invalid_argument("Error, invalid setted width");
  }
  width_ = width;
}

void dambieva::Rectangle::setHeight(double height)
{
  if (height <= 0)
  {
    throw std::invalid_argument("Error, invalid setted height");
  }
  height_ = height;
}
