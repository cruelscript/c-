#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameInfo(const sviridov::Shape *figure)
{
  std::cout << "Frame height: " << figure->getFrameRect().height << "\n"
    << "Frame width: " << figure->getFrameRect().width << "\n"
    << "Frame centre: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";
}

int main()
{
  sviridov::Rectangle rectangleTest({ 6.7, 2.4 }, 10.6, 5.1);
  sviridov::Shape* figure = &rectangleTest;
  sviridov::Circle circleTest({ 1.7, 12.3 }, 6.7);

  for (int i = 0; i < 2; i++)
  {
    const char* figureType = (i == 0 ? "rectangle" : "circle");
    if (i == 1) figure = &circleTest;

    std::cout << figureType << "'s area: " << figure->getArea() << "\n\n";
    printFrameInfo(figure);

    figure->move(4.6, -6.7);
    std::cout << "Moving " << figureType << " along axis abscissa and ordinate\n"
      << "new " << figureType << " centre is: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";

    figure->move({ -7.4, 5.9 });
    std::cout << "Moving " << figureType << " to a new point\n"
      << "new " << figureType << " centre is: (" << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y << ")\n";

    figure->scale(3.6);
    if (i == 1)
    {
      std::cout << "Scaling circle\n"
        << "New circle radius: " << figure->getFrameRect().width << "\n";
    }
    else
    {
      std::cout << "Scaling rectangle\n"
        << "New rectangle width: " << figure->getFrameRect().width << " New height: " << figure->getFrameRect().height << "\n\n";
    }
  }
  return 0;
}
