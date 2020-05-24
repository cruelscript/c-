#ifndef SPBSPU_LABS_2020_202_1_COMPOSITE_SHAPE_HPP
#define SPBSPU_LABS_2020_202_1_COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include "detail/dynamic-array.hpp"

namespace konovalov
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();

    CompositeShape(const CompositeShape &compositeShape);

    ~CompositeShape() override = default;

    CompositeShape &operator=(const CompositeShape &compositeShape);

    std::shared_ptr<Shape>& operator[](unsigned int index);

    double getArea() const noexcept override;

    point_t getCenterPoint() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t &point) override;

    void move(double dx, double dy) override;

    void scale(double coefficient) override;

    void pushShapeBack(const std::shared_ptr<Shape>& shape);

    void addShape(unsigned int index, const std::shared_ptr<Shape>& shape);

    void deleteShapeFromBack();

    void deleteShape(unsigned int index);

    bool isEmpty() const noexcept;

    size_t getSize() const noexcept;

  private:
    detail::DynamicArray<std::shared_ptr<Shape>> shapeArray_;
  };
}
#endif
