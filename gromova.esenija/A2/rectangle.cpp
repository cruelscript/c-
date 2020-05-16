#include "rectangle.hpp"
#include <stdexcept>

gromova::Rectangle::Rectangle(const double height, const double width, const point_t& centre) :
  height_(height),
  width_(width),
  centre_(centre)
{
  if (height_ <= 0)
  {
    throw std::invalid_argument("Wrong height!");
  }

  if (width_ <= 0)
  {
    throw std::invalid_argument("Wrong width!");
  }

}

double gromova::Rectangle::getArea() const
{
  return height_ * width_;
}

gromova::rectangle_t gromova::Rectangle::getFrameRect() const
{
  return { height_, width_, centre_ };
}

void gromova::Rectangle::move(const point_t& point)
{
  centre_ = point;
}

void gromova::Rectangle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

void gromova::Rectangle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Wrong coefficient!");
  }

  height_ *= k;
  width_ *= k;
}
