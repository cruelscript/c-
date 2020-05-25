#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  fokin::Circle testCircle({ 5.2, -7.5 }, 4.0);

  const int NUMBER_OF_SHAPES = 2;
  fokin::Shape* shapes[NUMBER_OF_SHAPES] = { &testRectangle, &testCircle };
  for (int i = 0; i < NUMBER_OF_SHAPES; i++)
  {
    std::cout << "Area of " << i + 1 << " figure: " << shapes[i]->getArea() << "\n";
    std::cout << "Center of " << i + 1 << " figure's frame rectangle: (" << shapes[i]->getFrameRect().pos.x << ", "
      << shapes[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Width and height of " << i + 1 << " figure's frame rectangle: " << shapes[i]->getFrameRect().width 
      << ", " << shapes[i]->getFrameRect().height << "\n";

    shapes[i]->move({ -5.1, 9.7 });
    shapes[i]->move(5.1, -9.7);
    std::cout << "Center of " << i + 1 << " figure's frame rectangle after moving to (0; 0): (" 
      << shapes[i]->getFrameRect().pos.x << ", " << shapes[i]->getFrameRect().pos.y << ")\n";

    shapes[i]->scale(3);
    std::cout << "Width and height of " << i + 1 << " figure's frame rectangle after scaling by coefficient = 3: " 
      << shapes[i]->getFrameRect().width << ", " << shapes[i]->getFrameRect().height << "\n";
    std::cout << "Area of " << i + 1 << " figure after scaling: " << shapes[i]->getArea()
      << "\n--------------------------------------------\n";
  }

  return 0;
}
