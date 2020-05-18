#include "composite-shape.hpp"

#include <ostream>
#include <stdexcept>
#include <utility>
#include "base-types.hpp"

gabdullina::CompositeShape::CompositeShape():
  count_(0),
  capacity_(0)
{}

gabdullina::CompositeShape::CompositeShape(const CompositeShape& resource):
  count_(resource.count_),
  capacity_(resource.capacity_),
  arrayOfShapes_(std::make_unique<shape_ptr[]>(resource.capacity_))
{
  for (size_t i = 0; i < count_; i++)
  {
    arrayOfShapes_[i] = resource.arrayOfShapes_[i];
  }
}

gabdullina::CompositeShape::CompositeShape(CompositeShape&& resource):
  count_(resource.count_),
  capacity_(resource.capacity_),
  arrayOfShapes_(std::move(resource.arrayOfShapes_))
{}

gabdullina::CompositeShape& gabdullina::CompositeShape::operator=(const CompositeShape& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    capacity_ = rhs.capacity_;
    shape_array tempArray(std::make_unique<shape_ptr[]>(rhs.capacity_));
    for (size_t i = 0; i < count_; i++)
    {
      tempArray[i] = rhs.arrayOfShapes_[i];
    }
    arrayOfShapes_.swap(tempArray);
  }
  return *this;
}

gabdullina::CompositeShape& gabdullina::CompositeShape::operator=(CompositeShape&& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    capacity_ = rhs.capacity_;
    arrayOfShapes_ = std::move(rhs.arrayOfShapes_);
  }
  return *this;
}

gabdullina::CompositeShape::shape_ptr& gabdullina::CompositeShape::operator[](size_t index) const
{
  if (index >= count_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return arrayOfShapes_[index];
}

bool gabdullina::CompositeShape::operator==(const CompositeShape& rhs) const
{
  if (count_ != rhs.count_)
  {
    return false;
  }
  for (size_t i = 0; i < count_; i++)
  {
    if(arrayOfShapes_[i] != rhs.arrayOfShapes_[i])
    {
      return false;
    }
  }
  return true;
}

bool gabdullina::CompositeShape::operator!=(const CompositeShape& rhs) const
{
  return !(*this == rhs);
}

double gabdullina::CompositeShape::getArea() const
{
  double totalArea = 0;
  for (size_t i = 0; i < count_; i++)
  {
    totalArea += arrayOfShapes_[i]->getArea();
  }
  return totalArea;
}

gabdullina::rectangle_t gabdullina::CompositeShape::getFrameRect() const
{
  if (count_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }

  rectangle_t tempFrameRect = arrayOfShapes_[0]->getFrameRect();
  double leftX = tempFrameRect.pos.x - tempFrameRect.width / 2;
  double rightX = tempFrameRect.pos.x + tempFrameRect.width / 2;
  double bottomY = tempFrameRect.pos.y - tempFrameRect.height / 2;
  double topY = tempFrameRect.pos.y + tempFrameRect.height / 2;

  for (size_t i = 1; i < count_; i++)
  {
    tempFrameRect = arrayOfShapes_[i]->getFrameRect();

    double tempValue = tempFrameRect.pos.x - tempFrameRect.width / 2;
    leftX = (tempValue < leftX) ? tempValue : leftX;

    tempValue = tempFrameRect.pos.x + tempFrameRect.width / 2;
    rightX = (tempValue < rightX) ? rightX : tempValue;

    tempValue = tempFrameRect.pos.y - tempFrameRect.height / 2;
    bottomY = (tempValue < bottomY) ? tempValue : bottomY;

    tempValue = tempFrameRect.pos.y + tempFrameRect.height / 2;
    topY = (tempValue < topY) ? topY : tempValue;
  }
  return {rightX - leftX, topY - bottomY, {(leftX + rightX) / 2, (bottomY + topY) / 2}};
}

gabdullina::point_t gabdullina::CompositeShape::getPos() const
{
  return getFrameRect().pos;
}

void gabdullina::CompositeShape::showParameters(std::ostream& out) const
{
  out << "\nFrame rectangle size of the composite shape is "
    << getFrameRect().width << "x" << getFrameRect().height << "\n";
  out << "Area of the composite shape is " << getArea() << "\n";
  out << "The position of the composite shape is ("
    << getPos().x << "; " << getPos().y << ")\n";
  for (size_t i = 0; i < count_; i++)
  {
    out << "\nParameters of composite shape part number " << i + 1 << " are:";
    arrayOfShapes_[i]->showParameters(out);
  }
}

void gabdullina::CompositeShape::move(const point_t& center)
{
  const double deltaX = center.x - getFrameRect().pos.x;
  const double deltaY = center.y - getFrameRect().pos.y;
  move(deltaX, deltaY);
}

void gabdullina::CompositeShape::move(double deltaX, double deltaY)
{
  for (size_t i = 0; i < count_; i++)
  {
    arrayOfShapes_[i]->move(deltaX, deltaY);
  }
}

void gabdullina::CompositeShape::scale(double scalingFactor)
{
  if (scalingFactor <= 0.0)
  {
    throw std::invalid_argument("Composite shape scaling factor must be positive number");
  }
  const point_t center = getFrameRect().pos;
  for (size_t i = 0; i < count_; i++)
  {
    const double deltaX = arrayOfShapes_[i]->getFrameRect().pos.x - center.x;
    const double deltaY = arrayOfShapes_[i]->getFrameRect().pos.y - center.y;
    arrayOfShapes_[i]->move({center.x + deltaX * scalingFactor, center.y + deltaY * scalingFactor});
    arrayOfShapes_[i]->scale(scalingFactor);
  }
}

void gabdullina::CompositeShape::updateCapacity()
{
  const double scalingFactor = 2;
  capacity_ *= scalingFactor;
  shape_array tempArray(std::make_unique<shape_ptr[]>(capacity_));
  for(size_t i = 0; i < count_; i++)
  {
    tempArray[i] = arrayOfShapes_[i];
  }
  arrayOfShapes_.swap(tempArray);
}

void gabdullina::CompositeShape::add(const shape_ptr& shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Shape pointer can not be null");
  }
  if(count_ >= capacity_)
  {
    if(capacity_ == 0)
    {
      capacity_++;
    }
    updateCapacity();
  }
  arrayOfShapes_[count_++] = shape;
}

void gabdullina::CompositeShape::remove()
{
  if (count_ == 0)
  {
    throw std::logic_error("Composite shape is empty");
  }
  count_--;
  arrayOfShapes_[count_].reset();
}

size_t gabdullina::CompositeShape::getSize() const
{
  return count_;
}

gabdullina::CompositeShape::shape_array gabdullina::CompositeShape::list() const
{
  shape_array tempArray(std::make_unique<shape_ptr[]>(count_));
  for(size_t i = 0; i < count_; i++)
  {
    tempArray[i] = arrayOfShapes_[i];
  }
  return tempArray;
}
