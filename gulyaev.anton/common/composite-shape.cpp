#include <iostream>
#include "composite-shape.hpp"
gulyaev::CompositeShape::CompositeShape() :
  array_()
{}

gulyaev::CompositeShape::CompositeShape(const std::shared_ptr<Shape> &shape) :
  array_()
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Pointer is null");
  }
  array_.add(shape);
}
gulyaev::CompositeShape::CompositeShape(const gulyaev::CompositeShape &compositeShape):
  array_(compositeShape.array_)
{}

gulyaev::CompositeShape::CompositeShape(const gulyaev::CompositeShape &&compositeShape) noexcept :
  array_(std::move(compositeShape.array_))
{}

double gulyaev::CompositeShape::getArea() const noexcept
{
  double area = 0.;
  for (size_t i = 0; i < this->getSize(); ++i)
  {
    area += array_[i]->getArea();
  }
  return area;
}

gulyaev::rectangle_t gulyaev::CompositeShape::getFrameRect() const
{
  if (getSize() == 0)
  {
    throw std::out_of_range("CompositeShape is empty");
  }
  
  rectangle_t rectangle = array_[0]->getFrameRect();
  double leftSideRect = rectangle.pos.x - rectangle.width / 2;
  double topSideRect = rectangle.pos.y + rectangle.height / 2;
  double rightSideRect = rectangle.pos.x + rectangle.width / 2;
  double bottomSideRect = rectangle.pos.y - rectangle.height / 2;
  
  for (size_t i = 1; i < getSize(); ++i)
  {
    rectangle = array_[i]->getFrameRect();
    leftSideRect = (rectangle.pos.x - rectangle.width / 2 < leftSideRect) ? rectangle.pos.x - rectangle.width / 2 : leftSideRect;
    topSideRect = (rectangle.pos.y + rectangle.height / 2 > topSideRect) ? rectangle.pos.y + rectangle.height / 2 : topSideRect;
    rightSideRect = (rectangle.pos.x + rectangle.width / 2 > rightSideRect) ? rectangle.pos.x + rectangle.width / 2 : rightSideRect;
    bottomSideRect = (rectangle.pos.y - rectangle.height / 2 < bottomSideRect) ? rectangle.pos.y - rectangle.height / 2 : bottomSideRect;
  }
  return {rightSideRect - leftSideRect, topSideRect - bottomSideRect, {(rightSideRect + leftSideRect) / 2,
(topSideRect + bottomSideRect) / 2}};
}

void gulyaev::CompositeShape::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Oops. Height can't be <= 0.0");
  }
  for (size_t i = 0; i < this->getSize(); ++i)
  {
    double deltaX = (getFrameRect().pos.x - array_[i]->getFrameRect().pos.x) * coefficient;
    double deltaY = (getFrameRect().pos.y - array_[i]->getFrameRect().pos.y) * coefficient;
    array_[i]->move(deltaX, deltaY);
    array_[i]->scale(coefficient);
  }
}

std::shared_ptr<gulyaev::Shape> &gulyaev::CompositeShape::operator[](size_t index)
{
  if (index >= array_.getAmount())
  {
    throw std::out_of_range("Out of range");
  }
  return array_[index];
}

size_t gulyaev::CompositeShape::getSize() const noexcept
{
  return array_.getAmount();
}

void gulyaev::CompositeShape::add(const std::shared_ptr<Shape> &shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Pointer is null");
  }
  if(this == shape.get())
  {
    throw std::invalid_argument("Adding equal composite shape");
  }
  array_.add(shape);
}

void gulyaev::CompositeShape::remove()
{
  if (array_.getAmount() == 0)
  {
    throw std::out_of_range("Composite shape is empty");
  }
  array_.remove();
}

void gulyaev::CompositeShape::clear() noexcept
{
  array_.clear();
}
gulyaev::point_t gulyaev::CompositeShape::getCenter() const
{
  return getFrameRect().pos;
}

void gulyaev::CompositeShape::move(const gulyaev::point_t &point)
{
  
  const point_t center = getCenter();
  move(point.x - center.x, point.y - center.y);
}

void gulyaev::CompositeShape::move(double deltaX, double deltaY) noexcept
{
  for (size_t i = 0; i < array_.getAmount(); ++i)
  {
    array_[i]->move(deltaX, deltaY);
  }
}





