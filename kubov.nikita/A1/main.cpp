#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <iostream>

void printInfoAboutFrameRect(Shape *figure)
{
  std::cout << "\nFrame rectangle " << std::endl;
  std::cout << "Height = " << figure->getFrameRect().height << "\nWidth = " << figure->getFrameRect().width << "\n";
  std::cout << "Center: " << "(" << figure->getFrameRect().position.x << ", "
            << figure->getFrameRect().position.y << ")\n" << std::endl;
}

int main()
{
  point_t position = {1.1, 1.5};

  Shape* figure = new Circle(position, 1.5);
  figure->getInfo();

  std::cout << "\nArea = " << figure->getArea() << std::endl;

  printInfoAboutFrameRect(figure);

  std::cout << "\nMove circle to (3.0, 4.0)" << std::endl;
  point_t positionNew = { 3.0, 4.0 };
  figure->move(positionNew);
  figure->getInfo();

  printInfoAboutFrameRect(figure);

  figure = new Rectangle(position, 3.0, 4.0);
  figure->getInfo();

  std::cout << "\nArea = " << figure->getArea() << std::endl;

  printInfoAboutFrameRect(figure);

  std::cout << "Move rectangle on x: +5.1, y: -2.3\n" << std::endl;
  figure->move(5.1, -2.3);
  figure->getInfo();

  printInfoAboutFrameRect(figure);

  return 0;
}


