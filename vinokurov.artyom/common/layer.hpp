#ifndef LAYER_HPP
#define LAYER_HPP

#include <memory>
#include "shape.hpp"

namespace vinokurov
{
  class Layer
  {
  public:
    typedef std::shared_ptr<Shape> shapePtr;
    typedef std::unique_ptr<shapePtr[]> shapeArray;

    Layer(const shapeArray& array, size_t size);
    Layer(const Layer& rhs);
    Layer(Layer&& rhs) noexcept;
    ~Layer() = default;

    Layer& operator=(const Layer& rhs);
    Layer& operator=(Layer&& rhs) noexcept;
    shapePtr operator[](unsigned int index) const;

    size_t size() const noexcept;

  private:
    size_t size_;
    shapeArray array_;
  };
}

#endif
