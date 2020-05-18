#include "rectangle.hpp"

#include <ostream>
#include <stdexcept>
#include "base-types.hpp"

gabdullina::Rectangle::Rectangle(const point_t& center, double width, double height) :
  center_(center),
  width_(width),
  height_(height)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Width and height can not be negative numbers");
  }
}

gabdullina::Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{}

double gabdullina::Rectangle::getArea() const
{
  return width_ * height_;
}

gabdullina::rectangle_t gabdullina::Rectangle::getFrameRect() const
{
  return {width_, height_, center_};
}

gabdullina::point_t gabdullina::Rectangle::getPos() const
{
  return center_;
}

void gabdullina::Rectangle::showParameters(std::ostream &out) const
{
  out << "\nCoordinates of the rectangle center is ("
    << center_.x << " ; " << center_.y << ")\n";
  out << "Width of the rectangle is " << width_ << " and height is " << height_ << "\n";
}

void gabdullina::Rectangle::move(const point_t& center)
{
  center_ = center;
}

void gabdullina::Rectangle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void gabdullina::Rectangle::scale(double scalingFactor)
{
  if (scalingFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor can not be negative number");
  }
  width_ *= scalingFactor;
  height_ *= scalingFactor;
}
