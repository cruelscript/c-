#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>

#include "shape.hpp"
#include "base-types.hpp"

namespace gabdullina
{
  class CompositeShape : public Shape 
  {
    public:
      using shape_ptr = std::shared_ptr<Shape>;
      using shape_array = std::unique_ptr<shape_ptr[]>;

      CompositeShape();
      CompositeShape(const CompositeShape& resource);
      CompositeShape(CompositeShape&& resource);
      ~CompositeShape() = default;

      CompositeShape& operator=(const CompositeShape& rhs);
      CompositeShape& operator=(CompositeShape&& rhs);

      shape_ptr& operator[](size_t index) const;
      bool operator==(const CompositeShape& rhs) const;
      bool operator!=(const CompositeShape& rhs) const;

      double getArea() const override;
      rectangle_t getFrameRect() const override;
      point_t getPos() const override;
      void showParameters(std::ostream& out) const override;
      void move(const point_t& center) override;
      void move(double deltaX, double deltaY) override;
      void scale(double scalingFactor) override;

      void add(const shape_ptr& shape);
      void remove();
      size_t getSize() const;
      shape_array list() const;

    private:
      size_t count_;
      size_t capacity_;
      shape_array arrayOfShapes_;
      void updateCapacity();
  };
}

#endif
