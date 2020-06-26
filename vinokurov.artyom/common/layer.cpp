#include "layer.hpp"

#include <stdexcept>

vinokurov::Layer::Layer(const shapeArray& array, size_t size) :
  size_(size),
  array_(std::make_unique<shapePtr[]>(size))
{
  for (size_t i = 0; i < size_; i++)
  {
    if (array[i])
    {
      array_[i] = array[i];
    }
  }
}

vinokurov::Layer::Layer(const Layer& rhs) :
  size_(rhs.size_),
  array_(std::make_unique<shapePtr[]>(rhs.size_))
{
  for (size_t i = 0; i < size_; i++)
  {
    array_[i] = rhs.array_[i];
  }
}

vinokurov::Layer::Layer(Layer&& rhs) noexcept :
  size_(rhs.size_),
  array_(std::move(rhs.array_))
{
  rhs.size_ = 0;
}

vinokurov::Layer& vinokurov::Layer::operator=(const Layer& rhs)
{
  if (this != &rhs)
  {
    shapeArray temp(std::make_unique<shapePtr[]>(rhs.size_));

    for(size_t i = 0; i < rhs.size_; i++)
    {
      temp[i] = rhs.array_[i];
    }
    array_.swap(temp);

    size_ = rhs.size_;
  }
  return *this;
}

vinokurov::Layer& vinokurov::Layer::operator=(Layer&& rhs) noexcept
{
  if (this != &rhs)
  {
    size_ = rhs.size_;
    array_ = std::move(rhs.array_);
    rhs.size_ = 0;
  }
  return *this;
}

vinokurov::Layer::shapePtr vinokurov::Layer::operator[](unsigned int index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("Layer: Error. Index is out of range.");
  }
  return array_[index];
}

size_t vinokurov::Layer::size() const noexcept
{
  return size_;
}
