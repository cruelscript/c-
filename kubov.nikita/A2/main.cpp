#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printInfoAboutFrameRect(const kubov::Shape *figure)
{
  if(figure == nullptr)
  {
    throw std::invalid_argument("In function was passed nullptr");
  }

  std::cout << "\nFrame rectangle\n";
  std::cout << "Height = " << figure->getFrameRect().height << "\nWidth = " << figure->getFrameRect().width << "\n";
  std::cout << "Center: " << "(" << figure->getFrameRect().pos.x << ", "
            << figure->getFrameRect().pos.y << ")\n\n";
}

int main()
{
  kubov::Shape *figure = nullptr;

  try
  {
    kubov::point_t center = {1.1, 1.5};

    figure = new kubov::Circle(center, 1.0);
    figure->print(std::cout);

    std::cout << "Area = " << figure->getArea() << "\n";
    printInfoAboutFrameRect(figure);

    std::cout << "Move circle to (3.0, 4.0)" << "\n";
    kubov::point_t positionNew = {3.0, 4.0};
    figure->move(positionNew);

    figure->print(std::cout);
    printInfoAboutFrameRect(figure);

    std::cout << "Circle area before using method scale: " << figure->getArea() << "\n";
    figure->scale(2.0);
    std::cout << "Circle area after using method scale with coefficient 2.0: " << figure->getArea() << "\n\n";

    delete figure;

    figure = new kubov::Rectangle(center, 3.0, 4.0);
    figure->print(std::cout);

    std::cout << "Area = " << figure->getArea() << "\n";
    printInfoAboutFrameRect(figure);

    std::cout << "Move rectangle on x: +5.1, y: -2.3\n" << "\n";
    figure->move(5.1, -2.3);

    figure->print(std::cout);
    printInfoAboutFrameRect(figure);

    std::cout << "Rectangle area before using method scale is " << figure->getArea() << "\n";
    figure->scale(2.0);
    std::cout << "Rectangle area after using method scale with coefficient 2.0 is : " << figure->getArea() << "\n";

    delete figure;
  }
  catch(std::invalid_argument &error)
  {
    std::cerr << error.what() << "\n";
    delete figure;
    return 1;
  }
  catch(std::bad_alloc &error)
  {
    std::cerr << error.what() << "\n";
    delete figure;
    return 2;
  }

  return 0;
}


