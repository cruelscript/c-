#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include "shape.hpp"
#include "detail/dynamic-array.hpp"
#include "base-types.hpp"

namespace kubov
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    CompositeShape(const std::shared_ptr<Shape> &shape);
    CompositeShape(const CompositeShape &compositeShape);

    void addElement(const std::shared_ptr<Shape> &element);
    void deleteElement(const unsigned int index);

    size_t getSize() const noexcept;
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const noexcept override;

    std::shared_ptr<Shape>& operator[](const unsigned int index) const;

    void move(const point_t &positionNew) noexcept override;
    void move(const double deltaX, const double deltaY) noexcept override;
    void print(std::ostream &out) const override;
    void scale(const double coefficient) override;
    void clear();

  private:
    detail::DynamicArray<std::shared_ptr<Shape>> shapes_;
  };
}
#endif
