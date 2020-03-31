#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameInfo(Shape* figure)
{
  std::cout << "Frame height: " << figure->getFrameRect().height << "\n"
    << "Frame width: " << figure->getFrameRect().width << "\n"
    << "Frame centre: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";
}

int main()
{
  Rectangle rectangleTest({6.7, 2.4}, 10.6, 5.1);
  Shape* figure = &rectangleTest;
  std::cout << "Rectangle's area: " << figure->getArea() <<  "\n\n";
  printFrameInfo(figure);
  figure->move(4.6, -6.7);
  figure->printCentre();
  figure->move({-7.4, 5.9});
  figure->printCentre();

  Circle circleTest({1.4, 12.3}, 6.7);
  figure = &circleTest;
  std::cout << "\nCircle area: " << figure->getArea() <<  "\n\n";
  printFrameInfo(figure);
  figure->move(11.6, -20.4);
  figure->printCentre();
  figure->move({35.6, -13.9});
  figure->printCentre();

  return 0;
}
