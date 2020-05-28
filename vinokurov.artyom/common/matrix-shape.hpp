#ifndef MATRIX_SHAPE_HPP
#define MATRIX_SHAPE_HPP

#include <memory>
#include "shape.hpp"

namespace vinokurov
{
  class MatrixShape
  {
  public:
    typedef std::shared_ptr<Shape> shapePtr;
    typedef std::unique_ptr<shapePtr[]> shapeArray;

    MatrixShape();
    MatrixShape(const MatrixShape& matrix);
    MatrixShape(MatrixShape&& matrix) noexcept;
    ~MatrixShape() = default;

    MatrixShape& operator=(const MatrixShape& matrix);
    MatrixShape& operator=(MatrixShape&& matrix) noexcept;

    void add(const shapePtr& shape);
    void add(const shapeArray& array, size_t size);
    void print(std::ostream& out) const;

  private:
    size_t rows_;
    size_t cols_;
    shapeArray array_;

    bool isOverlapped(const shapePtr& shape1, const shapePtr& shape2) const noexcept;
  };
}

#endif
