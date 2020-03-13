#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printInfoAboutFrameRect(kubov::Shape *figure)
{
  std::cout << "\nFrame rectangle\n";
  std::cout << "Height = " << figure->getFrameRect().height << "\nWidth = " << figure->getFrameRect().width << "\n";
  std::cout << "Center: " << "(" << figure->getFrameRect().pos.x << ", "
            << figure->getFrameRect().pos.y << ")\n\n";
}

int main()
{
  kubov::point_t center = {1.1, 1.5};

  kubov::Shape *figure = new kubov::Circle(center, 1.0);
  figure->print();

  std::cout << "Area = " << figure->getArea() << "\n";
  printInfoAboutFrameRect(figure);

  std::cout << "Move circle to (3.0, 4.0)" << "\n";
  kubov::point_t positionNew = {3.0, 4.0};
  figure->move(positionNew);

  figure->print();
  printInfoAboutFrameRect(figure);

  std::cout << "Circle area before using method scale: " << figure->getArea() << "\n";
  figure->scale(2.0);
  std::cout << "Circle area after using method scale with coefficient 2.0: " << figure->getArea() << "\n\n";

  delete figure;


  figure = new kubov::Rectangle(center, 3.0, 4.0);
  figure->print();

  std::cout << "Area = " << figure->getArea() << "\n";
  printInfoAboutFrameRect(figure);

  std::cout << "Move rectangle on x: +5.1, y: -2.3\n" << "\n";
  figure->move(5.1, -2.3);

  figure->print();
  printInfoAboutFrameRect(figure);

  std::cout << "Rectangle area before using method scale is " << figure->getArea() << "\n";
  figure->scale(2.0);
  std::cout << "Rectangle area after using method scale with coefficient 2.0 is : " << figure->getArea() << "\n";

  delete figure;
  
  return 0;
}


