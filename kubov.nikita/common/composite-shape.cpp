#include "composite-shape.hpp"

#include <ostream>
#include <stdexcept>

kubov::CompositeShape::CompositeShape():
  shapes_()
{
}

kubov::CompositeShape::CompositeShape(const std::shared_ptr<Shape> &shape):
  shapes_()
{
  if (!shape) {
    throw std::invalid_argument("Object doesn't exist, because a null pointer was received.");
  }
  shapes_.add(shape);
}

kubov::CompositeShape::CompositeShape(const kubov::CompositeShape &compositeShape):
  shapes_(compositeShape.shapes_)
{
}

void kubov::CompositeShape::addElement(const std::shared_ptr<Shape> &element)
{
  if (!element) {
    throw std::invalid_argument("Object doesn't exist");
  }

  shapes_.add(element);
}

void kubov::CompositeShape::deleteElement(const unsigned int index)
{
  if (index >= shapes_.getSize() || !shapes_.getSize()) {
    throw std::out_of_range("Index out of range or composite shape is empty");
  }

  shapes_.deleteElement(index);
}

size_t kubov::CompositeShape::getSize() const noexcept
{
  return shapes_.getSize();
}

double kubov::CompositeShape::getArea() const noexcept
{
  double allArea = 0;
  for (size_t i = 0; i < shapes_.getSize(); ++i) {
    allArea += shapes_[i]->getArea();
  }

  return allArea;
}

kubov::rectangle_t kubov::CompositeShape::getFrameRect() const
{
  if (!shapes_.getSize()) {
    throw std::out_of_range("Composite shape is empty");
  } else {
    rectangle_t shapeFrameRect = shapes_[0]->getFrameRect();
    double coordinateTopRect = shapeFrameRect.pos.y + shapeFrameRect.height / 2;
    double coordinateButtonRect = shapeFrameRect.pos.y - shapeFrameRect.height / 2;
    double coordinateLeftSideRect = shapeFrameRect.pos.x - shapeFrameRect.width / 2;
    double coordinateRightSideRect = shapeFrameRect.pos.x + shapeFrameRect.width / 2;

    for (size_t i = 1; i < shapes_.getSize(); ++i) {
      shapeFrameRect = shapes_[i]->getFrameRect();

      double currentCoordinateTopRect = shapeFrameRect.pos.y + shapeFrameRect.height / 2;
      double currentCoordinateButtonRect = shapeFrameRect.pos.y - shapeFrameRect.height / 2;
      double currentCoordinateLeftSideRect = shapeFrameRect.pos.x - shapeFrameRect.width / 2;
      double currentCoordinateRightSideRect = shapeFrameRect.pos.x + shapeFrameRect.width / 2;

      if (coordinateTopRect < currentCoordinateTopRect) {
        coordinateTopRect = currentCoordinateTopRect;
      }
      if (coordinateButtonRect > currentCoordinateButtonRect) {
        coordinateButtonRect = currentCoordinateButtonRect;
      }
      if (coordinateLeftSideRect > currentCoordinateLeftSideRect) {
        coordinateLeftSideRect = currentCoordinateLeftSideRect;
      }
      if (coordinateRightSideRect < currentCoordinateRightSideRect) {
        coordinateRightSideRect = currentCoordinateRightSideRect;
      }
    }

    return {coordinateRightSideRect - coordinateLeftSideRect, coordinateTopRect -coordinateButtonRect,
            {(coordinateLeftSideRect + coordinateRightSideRect) / 2,  (coordinateButtonRect + coordinateTopRect) / 2}};
  }
}

kubov::point_t kubov::CompositeShape::getCenter() const noexcept
{
  return getFrameRect().pos;
}

std::shared_ptr<kubov::Shape> &kubov::CompositeShape::operator[](const unsigned int index) const
{
  if (index >= shapes_.getSize()) {
    throw std::out_of_range("Out of range");
  }

  return shapes_[index];
}


void kubov::CompositeShape::move(const kubov::point_t &positionNew) noexcept
{
  const point_t center = getCenter();
  move(positionNew.x - center.x, positionNew.y - center.y);
}

void kubov::CompositeShape::move(const double deltaX, const double deltaY) noexcept
{
  for (size_t i = 0; i < shapes_.getSize(); ++i) {
    shapes_[i]->move(deltaX, deltaY);
  }
}

void kubov::CompositeShape::print(std::ostream &out) const
{
  out << "This is composite shape\n";
  out << "Size: " << getSize() << "\n";
  out << "Area: " << getArea() << "\n";
  out << "Width: " << getFrameRect().width << "\n";
  out << "Height: " << getFrameRect().height << "\n";
  out << "Center: (" << getCenter().x << ", " << getCenter().y << ")\n";

  out << "Composite shape is consist of this figures:\n";

  for (size_t i = 0; i < shapes_.getSize(); ++i) {
    shapes_[i]->print(out);
  }
}


void kubov::CompositeShape::scale(const double coefficient)
{
  if (coefficient <= 0.0) {
    throw std::invalid_argument("Coefficient <= 0");
  }

  const point_t centerCompositeShape = getCenter();
  for (size_t i = 0; i < shapes_.getSize(); ++i) {
    point_t centerShape = shapes_[i]->getCenter();

    shapes_[i]->move({centerCompositeShape.x + coefficient * (centerShape.x - centerCompositeShape.x),
        centerCompositeShape.y + coefficient * (centerShape.y - centerCompositeShape.y)});
    shapes_[i]->scale(coefficient);
  }
}

void kubov::CompositeShape::clear()
{
  shapes_.clear();
}
