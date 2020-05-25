#include "composite-shape.hpp"

#include <stdexcept>

fokin::CompositeShape::CompositeShape() :
  shape_() {}

fokin::CompositeShape::CompositeShape(const std::shared_ptr<fokin::Shape>& shape) :
  shape_()
{
  if (!shape)
  {
    throw std::invalid_argument("Object does not exist!");
  }
  shape_.add(shape);
}

fokin::CompositeShape::CompositeShape(const fokin::CompositeShape& compositeShape) :
  shape_(compositeShape.shape_) {}

fokin::CompositeShape::CompositeShape(fokin::CompositeShape&& obj) :
  shape_(obj.shape_) {}

fokin::CompositeShape& fokin::CompositeShape::operator=(const fokin::CompositeShape& compositeShape)
{
  if (this != &compositeShape)
  {
    shape_ = compositeShape.shape_;
  }

  return *this;
}

fokin::CompositeShape& fokin::CompositeShape::operator=(fokin::CompositeShape&& compositeShape)
{
  if (this != &compositeShape)
  {
    shape_ = compositeShape.shape_;
  }

  return *this;
}

std::shared_ptr<fokin::Shape>& fokin::CompositeShape::operator[](const unsigned int index)
{
  if (index >= shape_.getLength())
  {
    throw std::out_of_range("Index is out of range!");
  }

  return shape_[index];
}

void fokin::CompositeShape::addShape(const std::shared_ptr<fokin::Shape>& shape)
{
  if (!shape)
  {
    throw std::invalid_argument("Object does not exist!");
  }
  if (shape.get() == this)
  {
    throw std::invalid_argument("Trying to add a composite shape to itself!");
  }
  shape_.add(shape);
}

void fokin::CompositeShape::removeShape()
{
  if (shape_.getLength() <= 0)
  {
    throw std::length_error("The size is 0!");
  }
  shape_.remove();
}

void fokin::CompositeShape::clear() noexcept
{
  shape_.clear();
}

void fokin::CompositeShape::move(const fokin::point_t& point)
{
  const point_t initialCenter = getCenter();
  move(point.x - initialCenter.x, point.y - initialCenter.y);
}

void fokin::CompositeShape::move(const double dx, const double dy) noexcept
{
  for (size_t i = 0; i < getLength(); i++)
  {
    shape_[i]->move(dx, dy);
  }
}

void fokin::CompositeShape::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Ñoefficient should be greater than 0!");
  }

  const point_t initialCenter = getCenter();
  point_t shapeCenterPoint = {};
  for (size_t i = 0; i < getLength(); i++)
  {
    shapeCenterPoint = shape_[i]->getCenter();
    shape_[i]->move({ initialCenter.x + coefficient * (shapeCenterPoint.x - initialCenter.x),
      initialCenter.y + coefficient * (shapeCenterPoint.y - initialCenter.y) });
    shape_[i]->scale(coefficient);
  }
}

double fokin::CompositeShape::getArea() const noexcept
{
  double area = 0;
  for (size_t i = 0; i < getLength(); i++)
  {
    area += shape_[i]->getArea();
  }

  return area;
}

fokin::rectangle_t fokin::CompositeShape::getFrameRect() const
{
  if (shape_.isEmpty())
  {
    throw std::runtime_error("Composite shape is empty!");
  }

  rectangle_t tempFrameRectangle = shape_[0]->getFrameRect();
  double leftSideRectCoordinate = tempFrameRectangle.pos.x - tempFrameRectangle.width / 2.0;
  double rightSideRectCoordinate = tempFrameRectangle.pos.x + tempFrameRectangle.width / 2.0;
  double bottomRectCoordinate = tempFrameRectangle.pos.y - tempFrameRectangle.height / 2.0;
  double topRectCoordinate = tempFrameRectangle.pos.y + tempFrameRectangle.height / 2.0;

  for (size_t i = 1; i < getLength(); i++)
  {
    tempFrameRectangle = shape_[i]->getFrameRect();
    leftSideRectCoordinate = leftSideRectCoordinate > tempFrameRectangle.pos.x - tempFrameRectangle.width / 2.0 ?
      tempFrameRectangle.pos.x - tempFrameRectangle.width / 2.0 : leftSideRectCoordinate;
    rightSideRectCoordinate = rightSideRectCoordinate < tempFrameRectangle.pos.x + tempFrameRectangle.width / 2.0 ?
      tempFrameRectangle.pos.x + tempFrameRectangle.width / 2.0 : rightSideRectCoordinate;
    bottomRectCoordinate = bottomRectCoordinate > tempFrameRectangle.pos.y - tempFrameRectangle.height / 2.0 ?
      tempFrameRectangle.pos.y - tempFrameRectangle.height / 2.0 : bottomRectCoordinate;
    topRectCoordinate = topRectCoordinate < tempFrameRectangle.pos.y + tempFrameRectangle.height / 2.0 ?
      tempFrameRectangle.pos.y + tempFrameRectangle.height / 2.0 : topRectCoordinate;
  }

  return { rightSideRectCoordinate - leftSideRectCoordinate, topRectCoordinate - bottomRectCoordinate,
    { leftSideRectCoordinate + (rightSideRectCoordinate - leftSideRectCoordinate) / 2.0,
    bottomRectCoordinate + (topRectCoordinate - bottomRectCoordinate) / 2.0 } };
}

fokin::point_t fokin::CompositeShape::getCenter() const
{
  return getFrameRect().pos;
}

bool fokin::CompositeShape::isEmpty() const noexcept
{
  return shape_.isEmpty();
}

size_t fokin::CompositeShape::getLength() const noexcept
{
  return shape_.getLength();
}

size_t fokin::CompositeShape::getCapacity() const noexcept
{
  return shape_.getCapacity();
}
