#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <memory>
#include <stdexcept>

namespace fokin
{
  namespace detail
  {
    template<typename T>
    class DynamicArray
    {
    public:

      DynamicArray();

      explicit DynamicArray(size_t length);

      DynamicArray(const DynamicArray<T>& src);

      DynamicArray(DynamicArray<T>&& src);

      ~DynamicArray() = default;

      T& operator[](const unsigned int index);

      const T& operator[](const unsigned int index) const;

      DynamicArray<T>& operator=(const DynamicArray<T>& src);

      DynamicArray<T>& operator=(DynamicArray<T>&& src);

      void add(const T& element);

      void clear() noexcept;

      void remove();

      size_t getLength() const noexcept;

      size_t getCapacity() const noexcept;

      bool isEmpty() const noexcept;

    private:

      std::unique_ptr<T[]> array_;

      size_t length_;

      size_t capacity_;
    };

    template<typename T>
    fokin::detail::DynamicArray<T>::DynamicArray() :
      array_(nullptr),
      length_(0),
      capacity_(0) {}

    template<typename T>
    fokin::detail::DynamicArray<T>::DynamicArray(const size_t length) :
      array_(std::make_unique<T[]>(length)),
      length_(length),
      capacity_(0) {}

    template<typename T>
    fokin::detail::DynamicArray<T>::DynamicArray(const fokin::detail::DynamicArray<T>& src) :
      array_(std::make_unique<T[]>(src.length_)),
      length_(src.length_),
      capacity_(src.capacity_)
    {
      for (size_t i = 0; i < length_; ++i)
      {
        array_[i] = src[i];
      }
    }

    template<typename T>
    fokin::detail::DynamicArray<T>::DynamicArray(fokin::detail::DynamicArray<T>&& src) :
      length_(src.length_),
      capacity_(src.capacity_)
    {
      array_.swap(src.array_);
    }

    template<typename T>
    T& fokin::detail::DynamicArray<T>::operator[](const unsigned int index)
    {
      if (index >= length_)
      {
        throw std::out_of_range("Index is out of range!");
      }

      return array_[index];
    }

    template<typename T>
    const T& fokin::detail::DynamicArray<T>::operator[](const unsigned int index) const
    {
      if (index >= length_)
      {
        throw std::out_of_range("Index is out of range!");
      }

      return array_[index];
    }

    template<typename T>
    fokin::detail::DynamicArray<T>& fokin::detail::DynamicArray<T>::operator=(const fokin::detail::DynamicArray<T>& src)
    {
      if (this != &src)
      {
        length_ = src.length_;
        capacity_ = src.capacity_;
        array_.reset(new T[src.length_]);

        for (size_t i = 0; i < length_; ++i)
        {
          array_[i] = src.array_[i];
        }
      }

      return *this;
    }

    template<typename T>
    fokin::detail::DynamicArray<T>& fokin::detail::DynamicArray<T>::operator=(fokin::detail::DynamicArray<T>&& src)
    {
      if (this != &src)
      {
        array_.reset(src.array_);
        length_ = src.length_;
        capacity_ = src.capacity_;
        src.array_.reset();
        src.length_ = 0;
      }

      return *this;
    }

    template<typename T>
    void fokin::detail::DynamicArray<T>::add(const T& element)
    {
      if (capacity_ == length_)
      {
        std::unique_ptr<T[]> array = std::make_unique<T[]>((length_ + 1) * 2);
        for (size_t i = 0; i < length_; ++i)
        {
          array[i] = array_[i];
        }
        array[length_] = element;
        capacity_++;
        length_ = (length_ + 1) * 2;
        array_.swap(array);
      }
      else
      {
        array_[capacity_] = element;
        ++capacity_;
      }
    }

    template<typename T>
    void fokin::detail::DynamicArray<T>::clear() noexcept
    {
      array_.reset();
      length_ = 0;
      capacity_ = 0;
    }

    template<typename T>
    void fokin::detail::DynamicArray<T>::remove()
    {
      if (capacity_ == 0)
      {
        throw std::out_of_range("Array is empty!");
      }
      --capacity_;
    }

    template<typename T>
    size_t fokin::detail::DynamicArray<T>::getLength() const noexcept
    {
      return length_;
    }

    template<typename T>
    size_t fokin::detail::DynamicArray<T>::getCapacity() const noexcept
    {
      return capacity_;
    }

    template<typename T>
    bool fokin::detail::DynamicArray<T>::isEmpty() const noexcept
    {
      return capacity_ == 0;
    }
  }
}

#endif
