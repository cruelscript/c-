#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace vinokurov
{
  class CompositeShape : public Shape
  {
  public:
    typedef std::shared_ptr<Shape> shapePtr;
    typedef std::unique_ptr<shapePtr[]> shapeArray;

    CompositeShape();
    CompositeShape(const CompositeShape& shape);
    CompositeShape(CompositeShape&& shape);
    ~CompositeShape() = default;

    CompositeShape& operator=(const CompositeShape& copyShape);
    CompositeShape& operator=(CompositeShape&& moveShape);
    shapePtr operator[](unsigned int index) const;

    void add(const shapePtr& element);
    void remove();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(double deltaX, double deltaY) override;
    void print(std::ostream& out) const override;
    void scale(double coefficient) override;
    void rotate(double angle) override;
    const shapeArray& asArray() const;
    size_t size();

  private:
    size_t size_;
    size_t capacity_;
    shapeArray array_;
  };
}

#endif
