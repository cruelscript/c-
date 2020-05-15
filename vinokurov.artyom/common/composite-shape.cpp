#include "composite-shape.hpp"

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
  center_(copyShape.center_),
  capacity_(copyShape.capacity_),
  array_(std::make_unique<shapePtr[]>(copyShape.size_))
{
  for(size_t i = 0; i < size_; i++)
  {
    array_[i] = copyShape.array_[i];
  }
}

vinokurov::CompositeShape::CompositeShape(CompositeShape&& shape) :
  size_(shape.size_),
  center_(shape.center_),
  capacity_(shape.capacity_),
  array_(std::move(shape.array_))
{
  shape.size_ = 0;
  shape.center_ = {0, 0};
  shape.capacity_ = 0;
}

vinokurov::CompositeShape& vinokurov::CompositeShape::operator=(const CompositeShape& copyShape)
{
  if(this != &copyShape)
  {
    size_ = copyShape.size_;
    center_ = copyShape.center_;
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

vinokurov::CompositeShape& vinokurov::CompositeShape::operator=(CompositeShape&& shape)
{
  if(this != &shape)
  {
    size_ = shape.size_;
    center_ = shape.center_;
    array_ = std::move(shape.array_);
    capacity_ = shape.capacity_;
    shape.size_ = 0;
    shape.center_ = {0, 0};
    shape.capacity_ = 0;
  }
  return *this;
}

vinokurov::CompositeShape::shapePtr& vinokurov::CompositeShape::operator[](unsigned int index) const
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
    int const GROW_COEFFICIENT = 2;
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
  center_ = getFrameRect().pos;
}

void vinokurov::CompositeShape::remove()
{
  if(size_ == 0)
  {
    throw std::logic_error("CompositeShape: Error. Array underflow.");    
  }
  array_[size_ - 1].reset();
  size_--;
  center_ = (size_ > 0) ? getFrameRect().pos : point_t{0, 0};
}

double vinokurov::CompositeShape::getArea() const
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
  double leftX = tempFrame.pos.x - tempFrame.width / 2;
  double rightX = tempFrame.pos.x + tempFrame.width / 2;
  double topY = tempFrame.pos.y + tempFrame.height / 2;
  double bottomY = tempFrame.pos.y - tempFrame.height / 2;

  for (size_t i = 1; i < size_; i++)
  {
    tempFrame = array_[i]->getFrameRect();

    double current = tempFrame.pos.x - tempFrame.width / 2;
    leftX = (current < leftX) ? current : leftX;

    current = tempFrame.pos.x + tempFrame.width / 2;
    rightX = (current > rightX) ? current : rightX;

    current = tempFrame.pos.y + tempFrame.height / 2;
    topY = (current > topY) ? current : topY;

    current = tempFrame.pos.y - tempFrame.height / 2;
    bottomY = (current < bottomY) ? current : bottomY;
  }
  return {rightX - leftX, topY - bottomY,
    {(rightX + leftX) / 2, (topY + bottomY) / 2}};
}

void vinokurov::CompositeShape::print(std::ostream& out) const
{
  rectangle_t frameRect = getFrameRect();

  out << "\nWidth of the composite shape is " << frameRect.width
    << ", height of the composite shape is " << frameRect.height
    << ". The center of the composite shape is at (" << center_.x << ", " << center_.y << ")\n";

  for(size_t i = 0; i < size_; i++)
  {
    out << i + 1 << " part of composite shape: ";
    array_[i]->print(out);
  }
}

void vinokurov::CompositeShape::move(const double deltaX, const double deltaY)
{
  for(size_t i = 0; i < size_; i++)
  {
    array_[i]->move(deltaX, deltaY);
  }
  center_.x += deltaX;
  center_.y += deltaY;
}

void vinokurov::CompositeShape::move(const point_t& point)
{
  double deltaX = point.x - center_.x;
  double deltaY = point.y - center_.y;
  move(deltaX, deltaY);
  center_ = point;
}

void vinokurov::CompositeShape::scale(const double coefficient)
{
  if(coefficient <= 0.0)
  {
    throw std::invalid_argument("CompositeShape: Error. Scaling coefficient cannot be less than zero.");
  }
  for(size_t i = 0; i < size_; i++)
  {
    double deltaX = array_[i]->getFrameRect().pos.x - center_.x;
    double deltaY = array_[i]->getFrameRect().pos.y - center_.y;
    array_[i]->move(center_.x + deltaX * coefficient, center_.y + deltaY * coefficient);
    array_[i]->scale(coefficient);
  }
}
