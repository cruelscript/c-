#ifndef MATRIX_SHAPE_HPP
#define MATRIX_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace vinokurov
{
  class Layer;
  class CompositeShape;

  class MatrixShape
  {
  public:
    typedef std::shared_ptr<Shape> shapePtr;
    typedef std::unique_ptr<shapePtr[]> shapeArray;

    MatrixShape();
    MatrixShape(const MatrixShape& rhs);
    MatrixShape(MatrixShape&& rhs) noexcept;
    explicit MatrixShape(CompositeShape& compositeShape);
    ~MatrixShape() = default;

    MatrixShape& operator=(const MatrixShape& rhs);
    MatrixShape& operator=(MatrixShape&& rhs) noexcept;
    Layer operator[](unsigned int index) const;

    void add(const shapePtr& shape);
    void print(std::ostream& out) const;
    size_t getCols() const noexcept;
    size_t getRows() const noexcept;

  private:
    size_t rows_;
    size_t cols_;
    shapeArray array_;

    static bool isOverlapped(const shapePtr& shape1, const shapePtr& shape2);
  };
}

#endif
