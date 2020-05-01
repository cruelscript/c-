#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

talipova::Circle::Circle(const point_t& pos, const double radius) :
  pos_(pos),
  radius_(radius)
{
  if (radius_ <= 0)
  {
    throw std::invalid_argument("Error! Invalid radius.");
  }
}

talipova::Circle::Circle(const double x, const double y, const double radius) :
  Circle({ x, y }, radius)
{}

talipova::rectangle_t talipova::Circle::getFrameRect() const
{
  return { pos_, radius_ * 2, radius_ * 2 };
}

double talipova::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

void talipova::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void talipova::Circle::move(const point_t& point)
{
  pos_ = point;
}

talipova::point_t talipova::Circle::getPosition() const
{
  return pos_;
};

void talipova::Circle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error! Invalid coefficient.");
  }
  radius_ *= k;
}
