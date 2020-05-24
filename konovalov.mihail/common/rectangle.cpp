#include "rectangle.hpp"

#include <stdexcept>
#include <cmath>
#include "base-types.hpp"

konovalov::Rectangle::Rectangle(double width, double height, const point_t &center)
{
  if (width <= 0.0)
  {
    throw std::invalid_argument("Width in rectangle can't be <= 0!!!");
  }
  if (height <= 0.0)
  {
    throw std::invalid_argument("Height in rectangle can't be <= 0!!!");
  }
  vertices_[0] = {center.x - width / 2.0, center.y - height / 2.0};
  vertices_[1] = {center.x - width / 2.0, center.y + height / 2.0};
  vertices_[2] = {center.x + width / 2.0, center.y + height / 2.0};
  vertices_[3] = {center.x + width / 2.0, center.y - height / 2.0};
}

double konovalov::Rectangle::getArea() const noexcept
{
  return getHeight() * getWidth();
}

double konovalov::Rectangle::getHeight() const noexcept
{
  return std::sqrt(std::pow(vertices_[1].x - vertices_[0].x, 2.0) +
    std::pow(vertices_[1].y - vertices_[0].y, 2.0));
}

double konovalov::Rectangle::getWidth() const noexcept
{
  return std::sqrt(std::pow(vertices_[3].x - vertices_[0].x, 2.0) +
    std::pow(vertices_[3].y - vertices_[0].y, 2.0));
}

konovalov::point_t konovalov::Rectangle::getCenterPoint() const noexcept
{
  return getFrameRect().pos;
}

konovalov::rectangle_t konovalov::Rectangle::getFrameRect() const noexcept
{
  double leftSideRectCoordinate = vertices_[0].x;
  double rightSideRectCoordinate = vertices_[0].x;
  double bottomRectCoordinate = vertices_[0].y;
  double topRectCoordinate = vertices_[0].y;

  const int numberOfVertices = sizeof(vertices_) / sizeof(vertices_[0]);
  for (int i = 1; i < numberOfVertices; ++i)
  {
    leftSideRectCoordinate = leftSideRectCoordinate > vertices_[i].x ? vertices_[i].x : leftSideRectCoordinate;
    rightSideRectCoordinate = rightSideRectCoordinate < vertices_[i].x ? vertices_[i].x : rightSideRectCoordinate;
    bottomRectCoordinate = bottomRectCoordinate > vertices_[i].y ? vertices_[i].y : bottomRectCoordinate;
    topRectCoordinate = topRectCoordinate < vertices_[i].y ? vertices_[i].y : topRectCoordinate;
  }

  return {rightSideRectCoordinate - leftSideRectCoordinate,
    topRectCoordinate - bottomRectCoordinate,
    {leftSideRectCoordinate + (rightSideRectCoordinate - leftSideRectCoordinate) / 2.0,
    bottomRectCoordinate + (topRectCoordinate - bottomRectCoordinate) / 2.0}};
}

void konovalov::Rectangle::move(const point_t &point) noexcept
{
  point_t oldCenter = getCenterPoint();
  move(point.x - oldCenter.x, point.y - oldCenter.y);
}

void konovalov::Rectangle::move(double dx, double dy) noexcept
{
  for (point_t &vertex : vertices_)
  {
    vertex.x += dx;
    vertex.y += dy;
  }
}

void konovalov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaled coefficient can't be <= 0!!!");
  }

  point_t center = getCenterPoint();

  for (point_t &vertex : vertices_)
  {
    vertex.x = center.x + (vertex.x - center.x) * coefficient;
    vertex.y = center.y + (vertex.y - center.y) * coefficient;
  }
}
