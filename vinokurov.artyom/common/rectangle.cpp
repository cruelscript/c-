#include "rectangle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

vinokurov::Rectangle::Rectangle(double width, double height, const point_t& center)
{
  if (height <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Height cannot be less than zero.");
  }
  if (width <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Width cannot be less than zero.");
  }
  vertex_[0] = {center.x - width / 2, center.y - height / 2};
  vertex_[1] = {center.x - width / 2, center.y + height / 2};
  vertex_[2] = {center.x + width / 2, center.y + height / 2};
  vertex_[3] = {center.x + width / 2, center.y - height / 2};
}

double vinokurov::Rectangle::getArea() const noexcept
{
  return width() * height();
}

vinokurov::rectangle_t vinokurov::Rectangle::getFrameRect() const noexcept
{
  double maxX = vertex_[0].x;
  double maxY = vertex_[0].y;
  double minX = vertex_[0].x;
  double minY = vertex_[0].y;

  for(point_t vertices: vertex_)
  {
    if(vertices.x > maxX)
    {
      maxX = vertices.x;
    }
    if(vertices.x < minX)
    {
      minX = vertices.x;
    }
    if(vertices.y > maxY)
    {
      maxY = vertices.y;
    }
    if(vertices.y < minY)
    {
      minY = vertices.y;
    }
  }
  return {maxX - minX, maxY - minY, {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2}};
}

void vinokurov::Rectangle::move(const point_t& newCenter) noexcept
{
  point_t center = getFrameRect().pos;
  move(newCenter.x - center.x, newCenter.y - center.y);
}

void vinokurov::Rectangle::move(const double deltaX, const double deltaY) noexcept
{
  for(point_t& vertices : vertex_)
  {
    vertices.x += deltaX;
    vertices.y += deltaY;
  }
}

void vinokurov::Rectangle::print(std::ostream& out) const
{
  out << "\nWidth of the rectangle is " << width();
  out << "\nHeight of the rectangle is " << height();
  out << "\nCenter of the rectangle is at (" << center().x << ", " << center().y << ")\n";
}

void vinokurov::Rectangle::scale(const double coefficient)
{
  if(coefficient <= 0.0)
  {
    throw std::invalid_argument("Rectangle: Error. Scaling coefficient cannot be less than zero.");
  }
  point_t center_ = center();

  for (point_t& vertices : vertex_)
  {
    vertices = {center_.x + (vertices.x - center_.x) * coefficient,
      center_.y + (vertices.y - center_.y) * coefficient};
  }
}

void vinokurov::Rectangle::rotate(double angle) noexcept
{
  angle *= M_PI / 180;
  point_t center_ = center();

  for(point_t& vertices: vertex_)
  {
    vertices = {center_.x + (vertices.x - center_.x) * std::cos(angle) - (vertices.y - center_.y) * std::sin(angle),
      center_.y + (vertices.y - center_.y) * std::cos(angle) + (vertices.x - center_.x) * std::sin(angle)};
  }
}

double vinokurov::Rectangle::width() const noexcept
{
  return std::sqrt(std::pow(vertex_[2].x - vertex_[1].x, 2) 
    + std::pow(vertex_[2].y - vertex_[1].y, 2));
}

double vinokurov::Rectangle::height() const noexcept
{
  return std::sqrt(std::pow(vertex_[0].x - vertex_[1].x, 2) 
    + std::pow(vertex_[1].y - vertex_[0].y, 2));
}

vinokurov::point_t vinokurov::Rectangle::center() const noexcept
{
  return getFrameRect().pos;
}
