#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main() 
{
  Circle circle({-23.5, 21}, 4.0);
  Rectangle rectangle({2.5, 0.9}, 3.15, 3.40);
  Shape* figure[] = {&rectangle, &circle};

  for (size_t i = 0; i < 2; i++)
  {
    const char* shapeType = (i == 0 ? "rectangle" : "circle");
    std::cout << shapeType << '\n';

    std::cout << "Frame position (x, y): (" << figure[i]->getFrameRect().pos.x
    << ", " << figure[i]->getFrameRect().pos.y << ")\n"
    << "Frame width of figure is " << figure[i]->getFrameRect().width << "\n"
    << "Frame height of figure is " << figure[i]->getFrameRect().height << "\n\n";

    std::cout << "The figure's area is " << figure[i]->getArea() << "\n\n";

    figure[i]->move(3.4, 6.0);

    std::cout << "Frame position after moving figure along: (" << figure[i]->getFrameRect().pos.x
    << ", " << figure[i]->getFrameRect().pos.y << ")\n";

    figure[i]->move({2.4, -5.5});

    std::cout << "Frame position after moving figure to a new point: ("
    << figure[i]->getFrameRect().pos.x << ", " << figure[i]->getFrameRect().pos.y
    << ")\n\n";
  }
  return 0;
}
