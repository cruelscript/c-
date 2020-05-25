#ifndef SECOND_GIT_COMMON_DETAIL_DYNAMICARRAY_HPP_
#define SECOND_GIT_COMMON_DETAIL_DYNAMICARRAY_HPP_

#include <stdexcept>
#include <memory>

namespace gulyaev
{
  namespace detail
  {
    template<class T>
    class DynamicArray
    {
    public:
      DynamicArray();
      explicit DynamicArray(size_t size);
      DynamicArray(const DynamicArray<T> &dynamicArray);
      DynamicArray(DynamicArray<T> &&dynamicArray) noexcept;
      ~DynamicArray() = default;
      
      T &operator[](size_t index);
      const T &operator[](size_t index) const;
      DynamicArray<T> &operator=(const DynamicArray<T> &dynamicArray);
      DynamicArray<T> &operator=(DynamicArray<T> &&dynamicArray) noexcept;
      
      size_t getAmount() const noexcept;
      size_t getSize() const noexcept;
      void add(const T &element);
      void remove();
      void clear() noexcept;
    
    private:
      std::unique_ptr<T[]> dynamicArray_;
      size_t size_;
      size_t amountOfElements_;
    };
  }
}

template<class T>
gulyaev::detail::DynamicArray<T>::DynamicArray() :
  dynamicArray_(nullptr),
  size_(0),
  amountOfElements_(0)
{}

template<class T>
gulyaev::detail::DynamicArray<T>::DynamicArray(const size_t size) :
  dynamicArray_(std::make_unique<T[]>(size)),
  size_(size),
  amountOfElements_(0)
{}

template<class T>
gulyaev::detail::DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamicArray) :
  dynamicArray_(std::make_unique<T[]>(dynamicArray.getSize())),
  size_(dynamicArray.getSize()),
  amountOfElements_(dynamicArray.getAmount())
{
  for (size_t i = 0; i < size_; ++i)
  {
    dynamicArray_[i] = dynamicArray[i];
  }
}

template<class T>
gulyaev::detail::DynamicArray<T>::DynamicArray(DynamicArray<T> &&dynamicArray) noexcept :
  dynamicArray_(std::move(dynamicArray.dynamicArray_)),
  size_(dynamicArray.size_),
  amountOfElements_(dynamicArray.getAmount())
  
{}

template<class T>
T &gulyaev::detail::DynamicArray<T>::operator[](const size_t index)
{
  if (index >= size_)
  {
    throw std::out_of_range("Out of range");
  }
  return dynamicArray_[index];
}

template<class T>
const T &gulyaev::detail::DynamicArray<T>::operator[](const size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("Out of range");
  }
  return dynamicArray_[index];
}

template<class T>
gulyaev::detail::DynamicArray<T> &gulyaev::detail::DynamicArray<T>::operator=(const DynamicArray<T> &dynamicArray)
{
  if (this != &dynamicArray)
  {
    dynamicArray_.reset = std::make_unique<T[]>(size_);
    size_ = dynamicArray.getSize();
    amountOfElements_ = dynamicArray.amountOfElements_;
    
    for (size_t i = 0; i < size_; ++i)
    {
      dynamicArray_[i] = dynamicArray[i];
    }
  }
  return *this;
}
template<class T>
gulyaev::detail::DynamicArray<T> &gulyaev::detail::DynamicArray<T>::operator=(DynamicArray<T> &&dynamicArray) noexcept
{
  if (this != &dynamicArray)
  {
    dynamicArray_.reset(dynamicArray.array_);
    size_ = dynamicArray.getSize();
    amountOfElements_ = dynamicArray.amountOfElements_;
    dynamicArray.array_.reset();
    dynamicArray.size_ = 0;
  }
  return *this;
}

template<class T>
void gulyaev::detail::DynamicArray<T>::add(const T &element)
{
  if (amountOfElements_ == size_)
  {
    const size_t PREVIOUSLY_SIZE_OF_ARRAY = size_;
    size_ = (size_ + 1) * 2;
    std::unique_ptr<T[]> temp = std::make_unique<T[]>((PREVIOUSLY_SIZE_OF_ARRAY + 1) * 2);
    for (size_t i = 0; i < PREVIOUSLY_SIZE_OF_ARRAY; ++i)
    {
      temp[i] = dynamicArray_[i];
    }
    temp[PREVIOUSLY_SIZE_OF_ARRAY] = element;
    amountOfElements_++;
    
    dynamicArray_.swap(temp);
  } else
  {
    dynamicArray_[amountOfElements_] = element;
    ++amountOfElements_;
  }
}

template<class T>
void gulyaev::detail::DynamicArray<T>::remove()
{
  if(amountOfElements_ == 0)
  {
    throw std::out_of_range("Dynamic array is empty");
  }
  --amountOfElements_;
}

template<class T>
size_t gulyaev::detail::DynamicArray<T>::getSize() const noexcept
{
  return size_;
}

template<class T>
void gulyaev::detail::DynamicArray<T>::clear() noexcept
{
  dynamicArray_.reset();
  size_ = 0;
  amountOfElements_ = 0;
}
template<class T>
size_t gulyaev::detail::DynamicArray<T>::getAmount() const noexcept
{
  return amountOfElements_;
}


#endif //SECOND_GIT_DYNAMICARRAY_HPP_
