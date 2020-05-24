#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace belova
{
  class CompositeShape :
    public Shape
  {
  public:
    using shape_ptr = std::shared_ptr<Shape>;
    using shape_array = std::unique_ptr<shape_ptr[]>;

    CompositeShape();
    CompositeShape(const CompositeShape& obj);
    CompositeShape(CompositeShape&& obj) noexcept;
    ~CompositeShape() override = default;

    CompositeShape& operator=(const CompositeShape& obj);
    CompositeShape& operator=(CompositeShape&& obj) noexcept;
    shape_ptr& operator[](const size_t index);
    bool operator==(const CompositeShape& obj) const noexcept;
    bool operator!=(const CompositeShape& obj) const noexcept;

    size_t getSize() const noexcept;
    size_t getAmount() const noexcept;
    void addShape(const shape_ptr& obj);
    void addShape(const shape_ptr& obj, const size_t index);
    void deleteShape();
    void deleteShape(const size_t index);

    rectangle_t getFrameRect() const override;
    void move(const point_t& center) override;
    void move(const double dx, const double dy) noexcept override;
    double getArea() const noexcept override;
    void showData(std::ostream& out) const override;
    void scale(const double coeff) override;
  private:
    shape_array array_;
    size_t size_;
    size_t amount_;
  };
}

#endif
