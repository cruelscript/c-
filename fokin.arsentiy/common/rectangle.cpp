#include "rectangle.hpp"

#include <ostream>
#include <cmath>
#include <stdexcept>

fokin::Rectangle::Rectangle(const double width, const double height, const fokin::point_t& center)
{
  if (width <= 0.0)
  {
    throw std::invalid_argument("Width should be greater than 0!");
  }
  if (height <= 0.0)
  {
    throw std::invalid_argument("Height should be greater than 0!");
  }
  vertex_[0] = { center.x - (width / 2.0), center.y - (height / 2.0) };
  vertex_[1] = { center.x - (width / 2.0), center.y + (height / 2.0) };
  vertex_[2] = { center.x + (width / 2.0), center.y + (height / 2.0) };
  vertex_[3] = { center.x + (width / 2.0), center.y - (height / 2.0) };
}

double fokin::Rectangle::getWidth() const noexcept
{
  return std::sqrt(std::pow(vertex_[3].x - vertex_[0].x, 2.0) + std::pow(vertex_[3].y - vertex_[0].y, 2.0));
}

double fokin::Rectangle::getHeight() const noexcept
{
  return std::sqrt(std::pow(vertex_[1].x - vertex_[0].x, 2.0) + std::pow(vertex_[1].y - vertex_[0].y, 2.0));
}

double fokin::Rectangle::getArea() const noexcept
{
  return getHeight() * getWidth();
}

fokin::point_t fokin::Rectangle::getCenter() const noexcept
{
  return getFrameRect().pos;
}

fokin::rectangle_t fokin::Rectangle::getFrameRect() const noexcept
{
  double leftSideCoordinate = vertex_[0].x;
  double rightSideCoordinate = vertex_[0].x;
  double bottomSideCoordinate = vertex_[0].y;
  double topSideCoordinate = vertex_[0].y;

  const unsigned int numberOfVertices = sizeof(vertex_) / sizeof(vertex_[0]);
  for (unsigned int i = 1; i < numberOfVertices; i++)
  {
    leftSideCoordinate = leftSideCoordinate > vertex_[i].x ? vertex_[i].x : leftSideCoordinate;
    rightSideCoordinate = rightSideCoordinate < vertex_[i].x ? vertex_[i].x : rightSideCoordinate;
    bottomSideCoordinate = bottomSideCoordinate > vertex_[i].y ? vertex_[i].y : bottomSideCoordinate;
    topSideCoordinate = topSideCoordinate < vertex_[i].y ? vertex_[i].y : topSideCoordinate;
  }

  return { rightSideCoordinate - leftSideCoordinate, topSideCoordinate - bottomSideCoordinate,
    { leftSideCoordinate + ((rightSideCoordinate - leftSideCoordinate) / 2.0),
    bottomSideCoordinate + ((topSideCoordinate - bottomSideCoordinate) / 2.0) } };
}

void fokin::Rectangle::move(const fokin::point_t& newPos)
{
  point_t prevPos = getCenter();
  move(newPos.x - prevPos.x, newPos.y - prevPos.y);
}

void fokin::Rectangle::move(const double dx, const double dy) noexcept
{
  const unsigned int numberOfVertices = sizeof(vertex_) / sizeof(vertex_[0]);
  for (unsigned int i = 0; i < numberOfVertices; i++)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

void fokin::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Ñoefficient should be greater than 0!");
  }

  point_t center = getCenter();

  for (int i = 0; i < 4; i++)
  {
    vertex_[i] = { center.x + ((vertex_[i].x - center.x) * coefficient),
      center.y + ((vertex_[i].y - center.y) * coefficient) };
  }
}
