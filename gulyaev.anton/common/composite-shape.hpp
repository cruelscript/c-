#ifndef SECOND_GIT__COMPOSITE_SHAPE_HPP_
#define SECOND_GIT__COMPOSITE_SHAPE_HPP_

#include <stdexcept>
#include "shape.hpp"
#include "detail/dynamic-array.hpp"
#include "base-types.hpp"

namespace gulyaev
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    explicit CompositeShape(const std::shared_ptr<Shape> &shape);
    CompositeShape(const CompositeShape &compositeShape);
    CompositeShape(const CompositeShape &&compositeShape) noexcept;
  
    std::shared_ptr<Shape> &operator[](size_t index);
    
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double deltaX, double deltaY) noexcept override;
    void scale(const double coefficient) override;
    
    point_t getCenter() const;
    size_t getSize() const noexcept;
    void add(const std::shared_ptr<Shape> &shape);
    void remove();
    void clear() noexcept;
  
  private:
    detail::DynamicArray<std::shared_ptr<Shape>> array_;
  };
}

#endif //SECOND_GIT_COMPOSITE_SHAPE_HPP_
