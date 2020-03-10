#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

int main()
{
  point_t dot = { 1.1, 1.1 };
  Shape* rectangle = new Rectangle(dot, 12.345, 14.21);
  Shape* circle = new Circle(dot, 13.2);

  circle->print();
  rectangle->print();

  std::cout << "\nArea of the rectangle is " << rectangle->getArea();
  std::cout << "\nArea of the circle is " << circle->getArea();

  std::cout << "\nFrame width of the circle is " << circle->getFrameRect().width << ", position x is " << circle->getFrameRect().pos.x;

  circle->move(21.4, 43.5);
  circle->print();

  return 0;
};
