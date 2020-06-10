#include <iostream>
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix-shape.hpp"

int main()
{
  vinokurov::point_t dot = {3, 1};
  vinokurov::Rectangle rectangle(12.345, 14.21, dot);
  vinokurov::Circle circle(13.2, dot);

  vinokurov::CompositeShape::shapePtr part1 = std::make_shared<vinokurov::Rectangle>(6, 4, dot);
  dot = {7, 4};
  vinokurov::CompositeShape::shapePtr part2 = std::make_shared<vinokurov::Circle>(2, dot);
  dot = {2, 5};
  vinokurov::CompositeShape::shapePtr part3 = std::make_shared<vinokurov::Rectangle>(4, 2, dot);

  vinokurov::CompositeShape compShape;
  compShape.add(part1);
  compShape.add(part2);
  compShape.add(part3);

  vinokurov::Shape* figures[3] = {&rectangle, &circle, &compShape};

  for (vinokurov::Shape* shape : figures)
  {
    shape->print(std::cout);

    std::cout << "\nArea of the figure is " << shape->getArea() << "\n";
    std::cout << "\nFrame width of the figure is " << shape->getFrameRect().width
      << ", frame height is " << shape->getFrameRect().height
      << ", position is at x: " << shape->getFrameRect().pos.x
      << ", at y: " << shape->getFrameRect().pos.y << "\n";

    shape->move(21.4, 43.6);
    shape->print(std::cout);
    shape->move({-1.6, -70.6567});
    shape->print(std::cout);
    shape->scale(100.02);
    shape->print(std::cout);
    shape->rotate(15);
    shape->print(std::cout);
  }
  vinokurov::MatrixShape matrix(compShape);
  matrix.print(std::cout);

  std::cout << "\nRemoving the last element...\n";
  compShape.remove();
  compShape.print(std::cout);

  return 0;
};
