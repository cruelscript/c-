#include "composite-shape.hpp"

konovalov::CompositeShape::CompositeShape() :
  shapeArray_() {}

konovalov::CompositeShape::CompositeShape(const konovalov::CompositeShape &compositeShape) :
  shapeArray_(compositeShape.shapeArray_) {}

konovalov::CompositeShape &konovalov::CompositeShape::operator=(const konovalov::CompositeShape &compositeShape)
{
  shapeArray_ = compositeShape.shapeArray_;
  return *this;
}

std::shared_ptr<konovalov::Shape> &konovalov::CompositeShape::operator[](unsigned int index)
{
  return shapeArray_[index];
}

double konovalov::CompositeShape::getArea() const noexcept
{
  double compositeArea = 0;
  for (size_t i = 0; i < getSize(); ++i)
  {
    compositeArea += shapeArray_[i]->getArea();
  }

  return compositeArea;
}

konovalov::point_t konovalov::CompositeShape::getCenterPoint() const
{
  return getFrameRect().pos;
}

konovalov::rectangle_t konovalov::CompositeShape::getFrameRect() const
{
  if (shapeArray_.isEmpty())
  {
    throw std::runtime_error("Empty compositeShape!!!");
  }
  rectangle_t tempFrameRectangle = shapeArray_[0]->getFrameRect();
  double leftSideRectCoordinate = tempFrameRectangle.pos.x - tempFrameRectangle.width / 2.0;
  double rightSideRectCoordinate = tempFrameRectangle.pos.x + tempFrameRectangle.width / 2.0;
  double bottomRectCoordinate = tempFrameRectangle.pos.y - tempFrameRectangle.height / 2.0;
  double topRectCoordinate = tempFrameRectangle.pos.y + tempFrameRectangle.height / 2.0;

  for (size_t i = 1; i < getSize(); ++i)
  {
    tempFrameRectangle = shapeArray_[i]->getFrameRect();
    leftSideRectCoordinate = leftSideRectCoordinate > tempFrameRectangle.pos.x - tempFrameRectangle.width / 2.0 ?
      tempFrameRectangle.pos.x - tempFrameRectangle.width / 2.0 : leftSideRectCoordinate;
    rightSideRectCoordinate = rightSideRectCoordinate < tempFrameRectangle.pos.x + tempFrameRectangle.width / 2.0 ?
      tempFrameRectangle.pos.x + tempFrameRectangle.width / 2.0 : rightSideRectCoordinate;
    bottomRectCoordinate = bottomRectCoordinate > tempFrameRectangle.pos.y - tempFrameRectangle.height / 2.0 ?
      tempFrameRectangle.pos.y - tempFrameRectangle.height / 2.0 : bottomRectCoordinate;
    topRectCoordinate = topRectCoordinate < tempFrameRectangle.pos.y + tempFrameRectangle.height / 2.0 ?
      tempFrameRectangle.pos.y + tempFrameRectangle.height / 2.0 : topRectCoordinate;
  }

  return {rightSideRectCoordinate - leftSideRectCoordinate,
    topRectCoordinate - bottomRectCoordinate,
    {leftSideRectCoordinate + (rightSideRectCoordinate - leftSideRectCoordinate) / 2.0,
    bottomRectCoordinate + (topRectCoordinate - bottomRectCoordinate) / 2.0}};
}

void konovalov::CompositeShape::move(const point_t &point)
{
  const point_t oldCenter = getCenterPoint();
  move(point.x - oldCenter.x, point.y - oldCenter.y);
}

void konovalov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < getSize(); ++i)
  {
    shapeArray_[i]->move(dx, dy);
  }
}

void konovalov::CompositeShape::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Scaled coefficient can't be <= 0!!!");
  }

  const point_t compositeShapeCenterPoint = getCenterPoint();
  point_t centerShapePoint = {};
  for (size_t i = 0; i < getSize(); ++i)
  {
    centerShapePoint = shapeArray_[i]->getCenterPoint();
    shapeArray_[i]->move(
      {compositeShapeCenterPoint.x + coefficient * (centerShapePoint.x - compositeShapeCenterPoint.x),
      compositeShapeCenterPoint.y + coefficient * (centerShapePoint.y - compositeShapeCenterPoint.y)});
    shapeArray_[i]->scale(coefficient);
  }
}

void konovalov::CompositeShape::pushShapeBack(const std::shared_ptr<Shape> &shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Can't pushBack null pointer shape!!!");
  }
  shapeArray_.pushBack(shape);
}

void konovalov::CompositeShape::addShape(unsigned int index, const std::shared_ptr<Shape> &shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Can't pushBack null pointer shape!!!");
  }
  shapeArray_.addElement(index, shape);
}

void konovalov::CompositeShape::deleteShapeFromBack()
{
  shapeArray_.deleteBack();
}

void konovalov::CompositeShape::deleteShape(unsigned int index)
{
  shapeArray_.deleteElement(index);
}

bool konovalov::CompositeShape::isEmpty() const noexcept
{
  return shapeArray_.isEmpty();
}

size_t konovalov::CompositeShape::getSize() const noexcept
{
  return shapeArray_.getSize();
}
