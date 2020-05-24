#include "composite-shape.hpp"
#include <stdexcept>
#include <ostream>
#include <algorithm>
#include "base-types.hpp"

belova::CompositeShape::CompositeShape() :
  array_(std::make_unique<shape_ptr[]>(1)),
  size_(1),
  amount_(0)
{}

belova::CompositeShape::CompositeShape(const CompositeShape& obj) :
  array_(std::make_unique<shape_ptr[]>(obj.getSize())),
  size_(obj.getSize()),
  amount_(obj.getAmount())
{
  for (size_t i = 0; i < obj.getAmount(); i++)
  {
    array_[i] = obj.array_[i];
  }
}

belova::CompositeShape::CompositeShape(CompositeShape&& obj) noexcept :
  array_(std::move(obj.array_)),
  size_(obj.getSize()),
  amount_(obj.getAmount())
{
  obj.size_ = 0;
  obj.amount_ = 0;
}

belova::CompositeShape& belova::CompositeShape::operator=(const CompositeShape& obj)
{
  if (this != &obj)
  {
    size_ = obj.getSize();
    amount_ = obj.getAmount();
    shape_array tempArray(std::make_unique<shape_ptr[]>(obj.getSize()));
    for (size_t i = 0; i < obj.getAmount(); i++)
    {
      tempArray[i] = obj.array_[i];
    }
    array_.swap(tempArray);
  }
  return *this;
}

belova::CompositeShape& belova::CompositeShape::operator=(CompositeShape&& obj) noexcept
{
  if (this != &obj)
  {
    size_ = obj.getSize();
    amount_ = obj.getAmount();
    array_ = std::move(obj.array_);
    obj.size_ = 0;
    obj.amount_ = 0;
  }
  return *this;
}

belova::CompositeShape::shape_ptr& belova::CompositeShape::operator[](const size_t index)
{
  if (index >= amount_)
  {
    throw std::out_of_range("Error: index is out of range");
  }
  return array_[index];
}

bool belova::CompositeShape::operator==(const CompositeShape& obj) const noexcept
{
  if (amount_ != obj.getAmount())
  {
    return false;
  }
  for (size_t i = 0; i < amount_; i++)
  {
    if (array_[i] != obj.array_[i])
    {
      return false;
    }
  }
  return true;
}

bool belova::CompositeShape::operator!=(const CompositeShape& obj) const noexcept
{
  return !(*this == obj);
}

size_t belova::CompositeShape::getSize() const noexcept
{
  return size_;
}

size_t belova::CompositeShape::getAmount() const noexcept
{
  return amount_;
}

void belova::CompositeShape::addShape(const shape_ptr& obj)
{
  addShape(obj, amount_);
}

void belova::CompositeShape::addShape(const shape_ptr& obj, const size_t index)
{
  if (obj == nullptr)
  {
    throw std::invalid_argument("Error: invalid input value");
  }
  if (index > amount_)
  {
    throw std::out_of_range("Error: index is out of range");
  }
  if (amount_ >= size_)
  {
    shape_array tempArray(std::make_unique<shape_ptr[]>(size_ * 2));
    size_ = size_ * 2;
    for (size_t i = 0; i < amount_; i++)
    {
      tempArray[i] = array_[i];
    }
    array_.swap(tempArray);
  }
  if (index < amount_)
  {
    for (size_t i = amount_; i > index; i--)
    {
      array_[i] = array_[i - 1];
    }
  }
  array_[index] = obj;
  amount_++;
}

void belova::CompositeShape::deleteShape()
{
  if (amount_ == 0)
  {
    throw std::logic_error("Error: composite shape is empty");
  }
  deleteShape(amount_ - 1);
}

void belova::CompositeShape::deleteShape(const size_t index)
{
  if (amount_ == 0)
  {
    throw std::logic_error("Error: composite shape is empty");
  }
  if (index >= amount_)
  {
    throw std::out_of_range("Error: index is out of range");
  }
  for (size_t i = index; i < amount_ - 1; i++) 
  {
    array_[i] = array_[i + 1];
  }
  array_[--amount_] = nullptr;
}

belova::rectangle_t belova::CompositeShape::getFrameRect() const
{
  if (amount_ == 0)
  {
    throw std::logic_error("Error: composite shape is empty");
  }
  rectangle_t rect = array_[0]->getFrameRect();
  double minX = rect.pos.x - rect.width / 2;
  double maxX = rect.pos.x + rect.width / 2;
  double minY = rect.pos.y - rect.height / 2;
  double maxY = rect.pos.y + rect.height / 2;
  for (size_t i = 1; i < amount_; i++)
  {
    rect = array_[i]->getFrameRect();
    minX = std::min(minX, rect.pos.x - rect.width / 2);
    maxX = std::max(maxX, rect.pos.x + rect.width / 2);
    minY = std::min(minY, rect.pos.y - rect.height / 2);
    maxY = std::max(maxY, rect.pos.y + rect.height / 2);
  }
  return { { maxX - (maxX - minX) / 2, maxY - (maxY - minY) / 2 }, maxX - minX, maxY - minY };
}

void belova::CompositeShape::move(const point_t& center)
{
  point_t tempCenter = getFrameRect().pos;
  for (size_t i = 0; i < amount_; i++)
  {
    array_[i]->move(center.x - tempCenter.x, center.y - tempCenter.y);
  }
}

void belova::CompositeShape::move(const double dx, const double dy) noexcept
{
  for (size_t i = 0; i < amount_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

double belova::CompositeShape::getArea() const noexcept
{
  double area = 0;
  for (size_t i = 0; i < amount_; i++)
  {
    area += array_[i]->getArea();
  }
  return area;
}

void belova::CompositeShape::showData(std::ostream& out) const
{
  out << "Composite shape includes " << amount_ << " shapes\nComposite Shape data\n";
  for (size_t i = 0; i < amount_; i++)
  {
    array_[i]->showData(out);
  }
}

void belova::CompositeShape::scale(const double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("Error: invalid value of scale coefficient");
  }
  point_t compositeCenter = getFrameRect().pos;
  for (size_t i = 0; i < amount_; i++)
  {
    array_[i]->move({ compositeCenter.x + (array_[i]->getFrameRect().pos.x - compositeCenter.x) * coeff,
      compositeCenter.y + (array_[0]->getFrameRect().pos.y - compositeCenter.y) * coeff });
    array_[i]->scale(coeff);
  }
}
