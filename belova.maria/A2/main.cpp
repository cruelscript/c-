#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  belova::Rectangle rect({ 4, 4 }, 5, 2);
  belova::Circle circ({ 5.25, 6.26 }, 28.0);

  std::cout << "Shapes data\n";
  rect.showData(std::cout);
  circ.showData(std::cout);
  std::cout << "\n";

  belova::Shape* shapes[2] = { &rect, &circ };
  for (int i = 0; i < 2; i++)
  {
    std::cout << "Moving " << i + 1 << " shape to a specific point\n";
    shapes[i]->move({ 17.962, 63.7 });
    shapes[i]->showData(std::cout);
    std::cout << "Moving " << i + 1 << " shape along the abscissas and ordinates\n";
    shapes[i]->move(-55.32, 9.4);
    shapes[i]->showData(std::cout);
    std::cout << "\n";
    std::cout << "Calculating the bounding box data of the " << i + 1 << " shape\n";
    std::cout << "Width: " << shapes[i]->getFrameRect().width << "\tHeight: " << shapes[i]->getFrameRect().height
      << "\tPosition: (" << shapes[i]->getFrameRect().pos.x << ", " << shapes[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Calculating the area of the " << i + 1 << " shape\n";
    std::cout << "Area: " << shapes[i]->getArea() << "\n";
    shapes[i]->scale(2.5);
    std::cout << "After scaling by 2.5\n";
    shapes[i]->showData(std::cout);
    std::cout << "Area: " << shapes[i]->getArea() << "\n";
    std::cout << "\n";
  }

  return 0;
}
