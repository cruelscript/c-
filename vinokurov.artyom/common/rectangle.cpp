#include "rectangle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

vinokurov::Rectangle::Rectangle(double width, double height, const point_t& center) :
  vertices_
  {
    {center.x - width / 2, center.y - height / 2},
    {center.x - width / 2, center.y + height / 2},
    {center.x + width / 2, center.y + height / 2},
    {center.x + width / 2, center.y - height / 2}
  }
{
  if (height <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Height cannot be less than zero.");
  }
  if (width <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Width cannot be less than zero.");
  }
}

double vinokurov::Rectangle::getArea() const noexcept
{
  return width() * height();
}

vinokurov::rectangle_t vinokurov::Rectangle::getFrameRect() const noexcept
{
  double maxX = vertices_[0].x;
  double maxY = vertices_[0].y;
  double minX = vertices_[0].x;
  double minY = vertices_[0].y;

  for(point_t vertex: vertices_)
  {
    if(vertex.x > maxX)
    {
      maxX = vertex.x;
    }
    if(vertex.x < minX)
    {
      minX = vertex.x;
    }
    if(vertex.y > maxY)
    {
      maxY = vertex.y;
    }
    if(vertex.y < minY)
    {
      minY = vertex.y;
    }
  }
  return {maxX - minX, maxY - minY, {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2}};
}

void vinokurov::Rectangle::move(const point_t& newCenter) noexcept
{
  point_t center = getFrameRect().pos;
  move(newCenter.x - center.x, newCenter.y - center.y);
}

void vinokurov::Rectangle::move(double deltaX, double deltaY) noexcept
{
  for(point_t& vertex : vertices_)
  {
    vertex.x += deltaX;
    vertex.y += deltaY;
  }
}

void vinokurov::Rectangle::print(std::ostream& out) const
{
  out << "\nWidth of the rectangle is " << width();
  out << "\nHeight of the rectangle is " << height();
  out << "\nCenter of the rectangle is at (" << center().x << ", " << center().y << ")\n";
}

void vinokurov::Rectangle::scale(double coefficient)
{
  if(coefficient <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Scaling coefficient cannot be less than zero.");
  }
  point_t center_ = center();

  for (point_t& vertex : vertices_)
  {
    vertex.x = center_.x + (vertex.x - center_.x) * coefficient;
    vertex.y = center_.y + (vertex.y - center_.y) * coefficient;
  }
}

void vinokurov::Rectangle::rotate(double angle) noexcept
{
  angle *= M_PI / 180;
  point_t center_ = center();

  for(point_t& vertex: vertices_)
  {
    vertex = {center_.x + (vertex.x - center_.x) * std::cos(angle) - (vertex.y - center_.y) * std::sin(angle),
      center_.y + (vertex.y - center_.y) * std::cos(angle) + (vertex.x - center_.x) * std::sin(angle)};
  }
}

double vinokurov::Rectangle::width() const noexcept
{
  return std::sqrt(std::pow(vertices_[2].x - vertices_[1].x, 2) 
    + std::pow(vertices_[2].y - vertices_[1].y, 2));
}

double vinokurov::Rectangle::height() const noexcept
{
  return std::sqrt(std::pow(vertices_[0].x - vertices_[1].x, 2) 
    + std::pow(vertices_[1].y - vertices_[0].y, 2));
}

vinokurov::point_t vinokurov::Rectangle::center() const noexcept
{
  return getFrameRect().pos;
}
