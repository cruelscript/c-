#include <stdexcept>
#include <utility>
#include "composite-shape.hpp"
#include "shape.hpp"

talipova::CompositeShape::CompositeShape() :
  array_(nullptr),
  size_(0),
  capacity_(0)
{}

talipova::CompositeShape::CompositeShape(const size_t capacity) :
  array_(std::make_unique<shape_ptr[]>(capacity)),
  size_(0),
  capacity_(capacity)
{}

talipova::CompositeShape::CompositeShape(const CompositeShape& src) :
  array_(std::make_unique<shape_ptr[]>(src.capacity_)),
  size_(src.size_),
  capacity_(src.capacity_)
{
  for (size_t i = 0; i < size_; i++)
  {
    array_[i] = src.array_[i];
  }
}

talipova::CompositeShape::CompositeShape(CompositeShape&& src) :
  array_(std::move(src.array_)),
  size_(src.size_),
  capacity_(src.capacity_)
{}

talipova::CompositeShape& talipova::CompositeShape::operator=(const CompositeShape& src)
{
  if (this != &src)
  {
    array_ = std::make_unique<shape_ptr[]>(capacity_ = src.capacity_);
    size_ = src.size_;
    for (size_t i = 0; i < size_; i++)
    {
      array_[i] = src.array_[i];
    }
  }
  return *this;
}

talipova::CompositeShape& talipova::CompositeShape::operator=(CompositeShape&& src)
{
  if (this != &src)
  {
    array_ = std::move(src.array_);
    size_ = src.size_;
    capacity_ = src.capacity_;
  }
  return *this;
}

bool talipova::CompositeShape::operator==(const CompositeShape& src) const
{
  if (size_ != src.size_)
  {
    return false;
  }
  for (size_t i = 0; i < size_; i++)
  {
    if (array_[i] != src.array_[i])
    {
      return false;
    }
  }
  return true;
}

bool talipova::CompositeShape::operator!=(const CompositeShape& src) const
{
  return !(*this == src);
}

talipova::CompositeShape::shape_ptr& talipova::CompositeShape::operator[](const size_t index)
{
  if (index >= size_)
  {
    throw std::out_of_range("Error! Index out of range.");
  }
  return array_[index];
}

void talipova::CompositeShape::addShape(const std::shared_ptr<Shape>& shape)
{
  addShape(shape, size_);
}

void talipova::CompositeShape::addShape(const std::shared_ptr<Shape>& shape, const size_t index)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Error! Pointer can not be null");
  }
  if (index > size_)
  {
    throw std::out_of_range("Error! Index out of range.");
  }
  if (shape.get() == this)
  {
    throw std::logic_error("Error! Trying to add a composite shape to itself.");
  }
  if (size_ >= capacity_)
  {
    if (capacity_ == 0)
    {
      capacity_ = 1;
    }
    capacity_ *= 2;
    shape_array tempArray(std::make_unique<shape_ptr[]>(capacity_));
    for (size_t i = 0; i < size_; i++)
    {
      tempArray[i] = array_[i];
    }
    array_.swap(tempArray);
  }
  if (index < size_)
  {
    for (size_t i = size_; i > index; i--)
    {
      array_[i] = array_[i - 1];
    }
  }
  array_[index] = shape;
  size_++;
}

void talipova::CompositeShape::deleteShape(const size_t index)
{
  if (size_ == 0)
  {
    throw std::logic_error("Error! Composite shape is empty.");
  }
  if (index >= size_)
  {
    throw std::out_of_range("Error! Index out of range");
  }
  array_[index].reset();
  for (size_t i = index; i < size_ - 1; i++)
  {
    array_[i] = array_[i + 1];
  }
  size_--;
}

void talipova::CompositeShape::deleteShape(const std::shared_ptr<Shape>& shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Error! Pointer can not be null");
  }
  size_t index = 0;
  for (; index < size_; index++)
  {
    if (array_[index] == shape)
    {
      break;
    }
  }
  if (index < size_)
  {
    deleteShape(index);
  }
}

size_t talipova::CompositeShape::getSize() const
{
  return size_;
}

double talipova::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; i++)
  {
    area += array_[i]->getArea();
  }
  return area;
}

talipova::rectangle_t talipova::CompositeShape::getFrameRect() const
{
  if (size_ == 0)
  {
    throw std::logic_error("Error! Composite shape is empty.");
  }
  talipova::rectangle_t tempFrameRect = array_[0]->getFrameRect();
  double infX = tempFrameRect.pos.x - tempFrameRect.width / 2;
  double supX = tempFrameRect.pos.x + tempFrameRect.width / 2;
  double infY = tempFrameRect.pos.y - tempFrameRect.height / 2;
  double supY = tempFrameRect.pos.y + tempFrameRect.height / 2;

  for (size_t i = 1; i < size_; i++)
  {
    tempFrameRect = array_[i]->getFrameRect();
    double temp = tempFrameRect.pos.x - tempFrameRect.width / 2;
    infX = temp < infX ? temp : infX;
    temp = tempFrameRect.pos.x + tempFrameRect.width / 2;
    supX = temp > supX ? temp : supX;
    temp = tempFrameRect.pos.y - tempFrameRect.height / 2;
    infY = temp < infY ? temp : infY;
    temp = tempFrameRect.pos.y + tempFrameRect.height / 2;
    supY = temp > supY ? temp : supY;
  }
  return { { infX + (supX - infX) / 2, infY + (supY - infY) / 2 }, supX - infX, supY - infY };
}

void talipova::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

void talipova::CompositeShape::move(const point_t& point)
{
  talipova::point_t posBefore = getFrameRect().pos;
  move(point.x - posBefore.x, point.y - posBefore.y);
}

talipova::point_t talipova::CompositeShape::getPosition() const
{
  return getFrameRect().pos;
}

void talipova::CompositeShape::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error! Invalid coeeficient.");
  }
  talipova::point_t posFrameRect = getFrameRect().pos;
  talipova::point_t posShapeBefore = {};
  for (size_t i = 0; i < size_; i++)
  {
    posShapeBefore = array_[i]->getPosition();
    array_[i]->move({ posFrameRect.x + (posShapeBefore.x - posFrameRect.x) * k,
      posFrameRect.y + (posShapeBefore.y - posFrameRect.y) * k });
    array_[i]->scale(k);
  }
}
