#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"


void printInfoAboutFrameRect(Shape *figure)
{
  std::cout << "\nFrame rectangle\n";
  std::cout << "Height = " << figure->getFrameRect().height << "\nWidth = " << figure->getFrameRect().width << "\n";
  std::cout << "Center: " << "(" << figure->getFrameRect().pos.x << ", "
            << figure->getFrameRect().pos.y << ")\n\n";
}

int main()
{
  point_t center = {1.1, 1.5};

  Shape *figure = new Circle(center, 1.0);
  figure->print();

  std::cout << "Area = " << figure->getArea() << std::endl;
  printInfoAboutFrameRect(figure);

  std::cout << "Move circle to (3.0, 4.0)" << std::endl;
  point_t positionNew = {3.0, 4.0};
  figure->move(positionNew);

  figure->print();
  printInfoAboutFrameRect(figure);

  delete figure;

  figure = new Rectangle(center, 3.0, 4.0);
  figure->print();

  std::cout << "Area = " << figure->getArea() << std::endl;
  printInfoAboutFrameRect(figure);

  std::cout << "Move rectangle on x: +5.1, y: -2.3\n" << std::endl;
  figure->move(5.1, -2.3);

  figure->print();
  printInfoAboutFrameRect(figure);

  delete figure;

  return 0;
}


