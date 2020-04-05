#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rect({ 4, 4 }, 5, 2);
  Circle circ({ 5.25, 6.26 }, 28.0);

  std::cout << "Shapes data\n";
  rect.showData(std::cout);
  circ.showData(std::cout);

  Shape* rectangle = &rect;
  Shape* circle = &circ;

  std::cout << "Moving shapes to a specific point\n";
  rectangle->move({ 35, 159 });
  circle->move({ 17.962, 63.7 });
  rectangle->showData(std::cout);
  circle->showData(std::cout);

  std::cout << "Moving shapes along the abscissas and ordinates\n";
  rectangle->move(-34.8, -80);
  circle->move(-55.32, 9.4);
  rectangle->showData(std::cout);
  circle->showData(std::cout);

  std::cout << "Calculating the bounding box data of a rectangle\n";
  rectangle_t boundingBoxForRect = rectangle->getFrameRect();
  std::cout << "Width: " << boundingBoxForRect.width << "\tHeight: " << boundingBoxForRect.height
      << "\tPosition: " << '(' << boundingBoxForRect.pos.x << ", " << boundingBoxForRect.pos.y << ')' << "\n\n";
  std::cout << "Calculating the bounding box data of a circle\n";
  rectangle_t boundingBoxForCirc = circle->getFrameRect();
  std::cout << "Width: " << boundingBoxForCirc.width << "\tHeight: " << boundingBoxForCirc.height
      << "\tPosition: " << '(' << boundingBoxForCirc.pos.x << ", " << boundingBoxForCirc.pos.y << ')' << "\n\n";

  std::cout << "Calculating the area of a rectangle\n";
  std::cout << "Rectangle area: " << rectangle->getArea() << "\n\n";
  std::cout << "Calculating the area of a circle\n";
  std::cout << "Circle area: " << circle->getArea() << "\n";

  return 0;
}
