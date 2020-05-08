#ifndef DETAIL_DYNAMIC_ARRAY_HPP
#define DETAIL_DYNAMIC_ARRAY_HPP

#include <stdexcept>
#include <memory>

namespace kubov
{
  namespace detail
  {
    template<class T>
    class DynamicArray
    {
    public:
      DynamicArray();
      DynamicArray(const size_t size);
      DynamicArray(const DynamicArray<T> &array);
      DynamicArray(DynamicArray<T> &&array);
      ~DynamicArray() = default;

      DynamicArray<T> &operator=(const DynamicArray<T> &array);
      DynamicArray<T> &operator=(DynamicArray<T> &&array);
      T &operator[](const unsigned int index) const;

      void add(const T &element);
      void deleteElement(const unsigned int index);
      void clear();
      size_t getSize() const;

    private:
      size_t size_;
      size_t capacity_;
      std::unique_ptr<T[]> elements_;

      void expandArray();
      void compressArray();
    };
  }
}

template<class T>
void kubov::detail::DynamicArray<T>::expandArray()
{
  capacity_ *= 2;
  std::unique_ptr<T[]> tmpArray = std::make_unique<T[]>(capacity_);

  for (size_t i = 0; i < size_; ++i) {
    tmpArray[i] = elements_[i];
  }

  elements_.swap(tmpArray);
}

template<class T>
void kubov::detail::DynamicArray<T>::compressArray()
{
  if (capacity_ != 1) {
    capacity_ /= 2;
  }

  std::unique_ptr<T[]> tmpArray = std::make_unique<T[]>(capacity_);

  for (size_t i = 0; i < size_; ++i) {
    tmpArray[i] = elements_[i];
  }

  elements_.swap(tmpArray);
}

template<class T>
kubov::detail::DynamicArray<T>::DynamicArray():
  size_(0),
  capacity_(1),
  elements_(nullptr)
{
}

template<class T>
kubov::detail::DynamicArray<T>::DynamicArray(const size_t size):
  size_(size),
  capacity_(size_ == 0 ? 1 : size_ * 2),
  elements_(size_ == 0 ? nullptr : std::make_unique<T[]>(capacity_))
{
}

template<class T>
kubov::detail::DynamicArray<T>::DynamicArray(const DynamicArray<T> &array):
  size_(array.size_),
  capacity_(array.capacity_),
  elements_(std::make_unique<T[]>(capacity_))
{
  for (size_t i = 0; i < size_; ++i) {
    elements_[i] = array.elements_[i];
  }
}

template<class T>
kubov::detail::DynamicArray<T>::DynamicArray(DynamicArray<T> &&array):
  size_(array.size_),
  capacity_(array.capacity_)
{
  elements_.swap(array.elements_);
}

template<class T>
kubov::detail::DynamicArray<T> &kubov::detail::DynamicArray<T>::operator=(const DynamicArray<T> &array)
{
  if (this != &array) {
    size_ = array.size_;
    capacity_ = array.capacity_;
    elements_ = std::make_unique<T[]>(capacity_);

    for (int i = 0; i < size_; ++i) {
      elements_[i] = array.elements_[i];
    }
  }

  return *this;
}

template<class T>
kubov::detail::DynamicArray<T> &kubov::detail::DynamicArray<T>::operator=(DynamicArray<T> &&array)
{
  if (this != &array) {
    size_ = array.size_;
    capacity_ = array.capacity_;
    elements_.swap(array.elements_);
  }

  return *this;
}

template<class T>
T &kubov::detail::DynamicArray<T>::operator[](const unsigned int index) const
{
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }

  return elements_[index];
}

template<class T>
void kubov::detail::DynamicArray<T>::add(const T &element)
{
  if (size_ + 1 == capacity_) {
    expandArray();
  }

  elements_[size_] = element;
  ++size_;
}

template<class T>
void kubov::detail::DynamicArray<T>::deleteElement(const unsigned int index)
{
  if (size_ <= 0 || index >= size_) {
    throw std::out_of_range("Out of range");
  }

  for (size_t i = index; i < size_ - 1; ++i) {
    elements_[i] = elements_[i + 1];
  }
  --size_;

  if (size_ * 2 <= capacity_) {
    compressArray();
  }
}

template<class T>
void kubov::detail::DynamicArray<T>::clear()
{
  size_ = 0;
  elements_.reset();
}

template<class T>
size_t kubov::detail::DynamicArray<T>::getSize() const
{
  return size_;
}

#endif
