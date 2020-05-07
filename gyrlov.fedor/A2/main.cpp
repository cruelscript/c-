#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main() 
{
  gyrlov::Circle circle({-23.5, 21}, 4.0);
  gyrlov::Rectangle rectangle({2.5, 0.9}, 3.15, 3.40);
  gyrlov::Shape* figure[] = {&rectangle, &circle};

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
    
    std::cout << "Figure characteristics before scaling: \n";
    figure[i]->print(std::cout);

    std::cout << "Scaling figure by 2.0\n";
    figure[i]->scale(2.0);
    std::cout << '\n';

    std::cout << "Figure characteristics after scaling: \n";
    figure[i]->print(std::cout);

    std::cout << "Figure area after scaling is " << figure[i]->getArea() << "\n\n";

    std::cout << "Frame width of figure after scaling is " << figure[i]->getFrameRect().width << "\n"
      << "Frame height of figure after scaling is " << figure[i]->getFrameRect().height << "\n\n";
  }
  return 0;
}
