#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace talipova
{
  class CompositeShape :
    public Shape
  {
  public:
    using shape_ptr = std::shared_ptr<Shape>;
    using shape_array = std::unique_ptr<shape_ptr[]>;

    CompositeShape();
    CompositeShape(const size_t capacity);
    CompositeShape(const CompositeShape& src);
    CompositeShape(CompositeShape&& src);
    ~CompositeShape() = default;

    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src);
    bool operator==(const CompositeShape& src) const;
    bool operator!=(const CompositeShape& src) const;
    shape_ptr& operator[](const size_t index);
    void addShape(const std::shared_ptr<Shape>& shape);
    void addShape(const std::shared_ptr<Shape>& shape, const size_t index);
    void deleteShape(const std::shared_ptr<Shape>& shape);
    void deleteShape(const size_t index);
    size_t getSize() const;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const point_t& point) override;
    point_t getPosition() const override;
    void scale(const double k) override;
  private:
    shape_array array_;
    size_t size_;
    size_t capacity_;
  };
}

#endif
