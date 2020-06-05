#ifndef MATRIX_SHAPE_HPP
#define MATRIX_SHAPE_HPP

#include <memory>
#include "shape.hpp"
#include "composite-shape.hpp"

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
    explicit MatrixShape(CompositeShape& compositeShape);
    ~MatrixShape() = default;

    MatrixShape& operator=(const MatrixShape& matrix);
    MatrixShape& operator=(MatrixShape&& matrix) noexcept;
    shapePtr operator()(size_t row, size_t col) const;

    void add(const shapePtr& shape);
    void print(std::ostream& out) const;
    size_t getCols() const noexcept;
    size_t getRows() const noexcept;

  private:
    size_t rows_;
    size_t cols_;
    shapeArray array_;

    bool isOverlapped(const shapePtr& shape1, const shapePtr& shape2) const noexcept;
  };
}

#endif
