#include <iostream>
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
  std::cout << "\n";

  Shape* shapes[2] = { &rect, &circ };
  for (int i = 0; i < 2; i++)
  {
    std::cout << "Calculating the bounding box data of the " << i + 1 << " shape\n";
    std::cout << "Width: " << shapes[i]->getFrameRect().width << "\tHeight: " << shapes[i]->getFrameRect().height
        << "\tPosition: (" << shapes[i]->getFrameRect().pos.x << ", " << shapes[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Calculating the area of the " << i + 1 << " shape\n";
    std::cout << "Area: " << shapes[i]->getArea() << "\n\n";
  }

  return 0;
}
