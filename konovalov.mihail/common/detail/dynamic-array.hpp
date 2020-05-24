#ifndef SPBSPU_LABS_2020_202_1_DYNAMIC_ARRAY_HPP
#define SPBSPU_LABS_2020_202_1_DYNAMIC_ARRAY_HPP

#include <memory>

namespace konovalov
{
  namespace detail
  {
    template<typename T>
    class DynamicArray
    {
    public:
      explicit DynamicArray();

      DynamicArray(const DynamicArray<T> &dynamicArray);

      ~DynamicArray() = default;

      DynamicArray<T> &operator=(const DynamicArray<T> &dynamicArray);

      T &operator[](unsigned int i);

      const T &operator[](unsigned int i) const;

      void pushBack(const T &element);

      void addElement(unsigned int index, const T &element);

      void deleteBack();

      void deleteElement(unsigned int index);

      bool isEmpty() const noexcept;

      size_t getSize() const noexcept;

    private:
      std::unique_ptr<T[]> array_;
      size_t size_;
      size_t capacity_;

      void expandArray();
    };

    template<typename T>
    DynamicArray<T>::DynamicArray() :
      array_(std::make_unique<T[]>(1)),
      size_(0),
      capacity_(1) {}

    template<typename T>
    DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamicArray)
    {
      this->operator=(dynamicArray);
    }

    template<typename T>
    DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &dynamicArray)
    {
      if (this != &dynamicArray)
      {
        size_ = dynamicArray.size_;
        capacity_ = dynamicArray.capacity_;
        array_ = std::make_unique<T[]>(capacity_);

        for (size_t i = 0; i < size_; ++i)
        {
          array_[i] = dynamicArray.array_[i];
        }
      }
      return *this;
    }

    template<typename T>
    T &DynamicArray<T>::operator[](unsigned int i)
    {
      if (i >= size_)
      {
        throw std::out_of_range("Index out of range!!!");
      }

      return array_[i];
    }

    template<typename T>
    const T &DynamicArray<T>::operator[](unsigned int i) const
    {
      if (i >= size_)
      {
        throw std::out_of_range("Index out of range!!!");
      }

      return array_[i];
    }

    template<typename T>
    void DynamicArray<T>::pushBack(const T &element)
    {
      if (size_ == capacity_)
      {
        expandArray();
      }
      array_[size_] = element;
      ++size_;
    }

    template<typename T>
    void DynamicArray<T>::addElement(unsigned int index, const T &element)
    {
      if (index > size_)
      {
        throw std::out_of_range("Index out of range!!!");
      }
      if (size_ == capacity_)
      {
        expandArray();
      }
      for (size_t i = size_; i > index; i--)
      {
        array_[i] = std::move(array_[i - 1]);
      }
      size_++;
      array_[index] = element;
    }

    template<typename T>
    void DynamicArray<T>::deleteBack()
    {
      if (size_ == 0)
      {
        throw std::out_of_range("Index out of range!!!");
      }
      --size_;
    }

    template<typename T>
    void DynamicArray<T>::deleteElement(unsigned int index)
    {
      if (size_ == 0 || index >= size_)
      {
        throw std::out_of_range("Index out of range!!!");
      }

      for (size_t i = index; i < size_ - 1; ++i)
      {
        array_[i] = std::move(array_[i + 1]);
      }
      --size_;
    }

    template<typename T>
    bool DynamicArray<T>::isEmpty() const noexcept
    {
      return size_ == 0;
    }

    template<typename T>
    size_t DynamicArray<T>::getSize() const noexcept
    {
      return size_;
    }

    template<typename T>
    void DynamicArray<T>::expandArray()
    {
      std::unique_ptr<T[]> newArray = std::make_unique<T[]>(capacity_ *= 2);

      for (size_t i = 0; i < size_; ++i)
      {
        newArray[i] = std::move(array_[i]);
      }
      array_.swap(newArray);
    }
  }
}
#endif
