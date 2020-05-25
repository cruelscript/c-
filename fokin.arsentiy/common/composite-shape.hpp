#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include "detail/dynamic-array.hpp"

namespace fokin
{
  class CompositeShape : public Shape
  {
  public:

    CompositeShape();

    CompositeShape(const std::shared_ptr<Shape>& shape);

    CompositeShape(const CompositeShape& compositeShape);

    CompositeShape(CompositeShape&& obj);

    ~CompositeShape() override = default;

    CompositeShape& operator=(const CompositeShape& compositeShape);

    CompositeShape& operator=(CompositeShape&& compositeShape);

    std::shared_ptr<Shape>& operator[](const unsigned int index);

    void addShape(const std::shared_ptr<Shape>& shape);

    void removeShape();

    void clear() noexcept;

    void move(const point_t& point) override;

    void move(const double dx, const double dy) noexcept override;

    void scale(const double coefficient) override;

    double getArea() const noexcept override;

    rectangle_t getFrameRect() const override;

    point_t getCenter() const override;

    bool isEmpty() const noexcept;

    size_t getLength() const noexcept;

    size_t getCapacity() const noexcept;

  private:

    detail::DynamicArray<std::shared_ptr<Shape>> shape_;
  };
}
#endif
