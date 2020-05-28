#include "composite-shape.hpp"

#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <ostream>
#include "base-types.hpp"

vinokurov::CompositeShape::CompositeShape() :
  size_(0),
  capacity_(10),
  array_(std::make_unique<shapePtr[]>(capacity_))
{}

vinokurov::CompositeShape::CompositeShape(const CompositeShape& copyShape) :
  size_(copyShape.size_),
  capacity_(copyShape.capacity_),
  array_(std::make_unique<shapePtr[]>(copyShape.size_))
{
  for(size_t i = 0; i < size_; i++)
  {
    array_[i] = copyShape.array_[i];
  }
}

vinokurov::CompositeShape::CompositeShape(CompositeShape&& shape) noexcept :
  size_(shape.size_),
  capacity_(shape.capacity_),
  array_(std::move(shape.array_))
{
  shape.size_ = 0;
  shape.capacity_ = 0;
}

vinokurov::CompositeShape& vinokurov::CompositeShape::operator=(const CompositeShape& copyShape)
{
  if(this != &copyShape)
  {
    size_ = copyShape.size_;
    capacity_ = copyShape.capacity_;
    shapeArray temp(std::make_unique<shapePtr[]>(copyShape.size_));

    for(size_t i = 0; i < size_; i++)
    {
      temp[i] = copyShape.array_[i];
    }
    array_.swap(temp);
  }
  return *this;
}

vinokurov::CompositeShape& vinokurov::CompositeShape::operator=(CompositeShape&& shape) noexcept
{
  if(this != &shape)
  {
    size_ = shape.size_;
    array_ = std::move(shape.array_);
    capacity_ = shape.capacity_;
    shape.size_ = 0;
    shape.capacity_ = 0;
  }
  return *this;
}

vinokurov::CompositeShape::shapePtr vinokurov::CompositeShape::operator[](unsigned int index) const
{
  if(index >= size_)
  {
    throw std::out_of_range("CompositeShape: Error. Index is out of range.");
  }
  return array_[index];
}

void vinokurov::CompositeShape::add(const shapePtr& element)
{
  if(!element)
  {
    throw std::invalid_argument("CompositeShape: Error. Pointer of added element cannot be nullptr.");
  }
  if(!array_)
  {
    array_ = std::make_unique<shapePtr[]>(capacity_);
  }
  else if(size_ >= capacity_)
  {
    const int GROW_COEFFICIENT = 2;
    shapeArray temp(std::make_unique<shapePtr[]>(GROW_COEFFICIENT * capacity_));
    capacity_ *= GROW_COEFFICIENT;

    for(size_t i = 0; i < size_; i++)
    {
      temp[i] = array_[i];
    }
    array_.swap(temp);
  }
  array_[size_] = element;
  size_++;
}

void vinokurov::CompositeShape::remove()
{
  if(size_ == 0)
  {
    throw std::logic_error("CompositeShape: Error. Array underflow.");    
  }
  array_[size_ - 1].reset();
  size_--;
}

double vinokurov::CompositeShape::getArea() const noexcept
{
  double sumArea = 0.0;

  for(size_t i = 0; i < size_; i++)
  {
    sumArea += array_[i]->getArea();
  }
  return sumArea;
}

vinokurov::rectangle_t vinokurov::CompositeShape::getFrameRect() const
{
  if(size_ == 0)
  {
    throw std::invalid_argument("CompositeShape: Error. Frame rectangle is not defined"); 
  }
  rectangle_t tempFrame = array_[0]->getFrameRect();
  double minX = tempFrame.pos.x - tempFrame.width / 2;
  double maxX = tempFrame.pos.x + tempFrame.width / 2;
  double maxY = tempFrame.pos.y + tempFrame.height / 2;
  double minY = tempFrame.pos.y - tempFrame.height / 2;

  for (size_t i = 1; i < size_; i++)
  {
    tempFrame = array_[i]->getFrameRect();

    double current = tempFrame.pos.x - tempFrame.width / 2;
    minX = (current < minX) ? current : minX;

    current = tempFrame.pos.x + tempFrame.width / 2;
    maxX = (current > maxX) ? current : maxX;

    current = tempFrame.pos.y + tempFrame.height / 2;
    maxY = (current > maxY) ? current : maxY;

    current = tempFrame.pos.y - tempFrame.height / 2;
    minY = (current < minY) ? current : minY;
  }
  return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2}};
}

void vinokurov::CompositeShape::move(const double deltaX, const double deltaY) noexcept
{
  for(size_t i = 0; i < size_; i++)
  {
    array_[i]->move(deltaX, deltaY);
  }
}

void vinokurov::CompositeShape::move(const point_t& newCenter)
{
  point_t center = getFrameRect().pos;
  move(newCenter.x - center.x, newCenter.y - center.y);
}

void vinokurov::CompositeShape::print(std::ostream& out) const
{
  rectangle_t frameRect = getFrameRect();

  out << "\nWidth of the composite shape is " << frameRect.width;
  out << "\nHeight of the composite shape is " << frameRect.height;
  out << "\nCenter of the composite shape is at (" << frameRect.pos.x << ", " << frameRect.pos.y << ")\n";

  for(size_t i = 0; i < size_; i++)
  {
    out << "\n" << i + 1 << " part of composite shape: ";
    array_[i]->print(out);
  }
}

void vinokurov::CompositeShape::scale(double coefficient)
{
  if(coefficient <= 0.0)
  {
    throw std::invalid_argument("CompositeShape: Error. Scaling coefficient cannot be less than zero.");
  }
  point_t center = getFrameRect().pos;

  for(size_t i = 0; i < size_; i++)
  {
    point_t shapeCenter = array_[i]->getFrameRect().pos;
    array_[i]->move({center.x + (shapeCenter.x - center.x) * coefficient, 
      center.y + (shapeCenter.y - center.y) * coefficient});
    array_[i]->scale(coefficient);
  }
}

void vinokurov::CompositeShape::rotate(double angle) noexcept
{
  if(!array_ || size_ == 0)
  {
    return;
  }
  point_t center = getFrameRect().pos;
  double sinAngle = std::sin(angle * M_PI / 180);
  double cosAngle = std::cos(angle * M_PI / 180);

  for(size_t i = 0; i < size_; i++)
  {
    if(array_[i])
    {
      point_t shapeCenter = array_[i]->getFrameRect().pos;

      array_[i]->move({center.x + (shapeCenter.x - center.x) * cosAngle - (shapeCenter.y - center.y) * sinAngle,
        center.y + (shapeCenter.y - center.y) * cosAngle + (shapeCenter.x - center.x) * sinAngle});
      array_[i]->rotate(angle);      
    }
  }
}

const vinokurov::CompositeShape::shapeArray& vinokurov::CompositeShape::asArray() const noexcept
{
  return array_;
}

size_t vinokurov::CompositeShape::size() const noexcept
{
  return size_;
}
