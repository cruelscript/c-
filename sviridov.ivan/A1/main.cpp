#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameInfo(const Shape *figure)
{
  std::cout << "Frame height: " << figure->getFrameRect().height << "\n"
    << "Frame width: " << figure->getFrameRect().width << "\n"
    << "Frame centre: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";
}

int main()
{
  Rectangle rectangleTest({6.7, 2.4}, 10.6, 5.1);
  Shape *figure = &rectangleTest;
  std::cout << "Rectangle's area: " << figure->getArea() <<  "\n\n";
  printFrameInfo(figure);
  figure->move(4.6, -6.7);
  std::cout << "Moving rectangle along axis abscissa and ordinate\n"
    << "Rectangle centre is: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";
  figure->move({-7.4, 5.9});
  std::cout << "Moving rectangle to a new point\n"
    << "Rectangle centre is: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";

  Circle circleTest({1.4, 12.3}, 6.7);
  figure = &circleTest;
  std::cout << "\nCircle area: " << figure->getArea() <<  "\n\n";
  printFrameInfo(figure);
  figure->move(11.6, -20.4);
  std::cout << "Moving circle along axis abscissa and ordinate\n"
    << "Circle centre is: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";
  figure->move({35.6, -13.9});
  std::cout << "Moving circle to a new point\n"
    << "Circle centre is: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";

  return 0;
}
