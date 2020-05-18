#include "circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <ostream>
#include <stdexcept>
#include "base-types.hpp"

gabdullina::Circle::Circle(const point_t& center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ < 0.0)
  {
    throw std::invalid_argument("Radius can not be negative number");
  }
}

gabdullina::Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{}

double gabdullina::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

gabdullina::rectangle_t gabdullina::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, center_};
}

gabdullina::point_t gabdullina::Circle::getPos() const
{
  return center_;
}

void gabdullina::Circle::showParameters(std::ostream &out) const
{
  out << "\nCoordinates of the circle center is ("
    << center_.x << " ; " << center_.y << ")\n";
  out << "Radius of the circle is " << radius_ << "\n";
}

void gabdullina::Circle::move(const point_t& center)
{
  center_ = center;
}

void gabdullina::Circle::move(double deltaX, double deltaY)
{
  center_.x += deltaX;
  center_.y += deltaY;
}

void gabdullina::Circle::scale(double scalingFactor)
{
  if (scalingFactor < 0.0)
  {
    throw std::invalid_argument("Circle scale factor can not be negative");
  }
  radius_ *= scalingFactor;
}
