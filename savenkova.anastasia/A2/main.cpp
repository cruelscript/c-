#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  savenkova::Circle circle({ -1.1, 3.2 }, 2.3);
  savenkova::Rectangle rectangle({ 0.3, 0.7 }, 3.12, 2.45);
  savenkova::Shape* figures[] = { &rectangle, &circle };

  for (savenkova::Shape* figure : figures)
  {
    std::cout << "Frame position (x, y): (" << figure->getFrameRect().pos.x
      << ", " << figure->getFrameRect().pos.y << ")\n"
      << "Frame width of figure is " << figure->getFrameRect().width << "\n"
      << "Frame height of figure is " << figure->getFrameRect().height << "\n\n";

    std::cout << "The figure's area is " << figure->getArea() << "\n\n";

    figure->move(3.4, 6.0);

    std::cout << "Frame position after moving figure along\
 abscissa(3.4) and ordinates(6)  (x, y): (" << figure->getFrameRect().pos.x
      << ", " << figure->getFrameRect().pos.y << ")\n";

    figure->move({ 2.4, -5.5 });

    std::cout << "Frame position after moving figure to a new point (x, y): ("
      << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y
      << ")\n\n";

    figure->scale(3.5);
    std::cout << "The figure's area after scaling with a 3.5 coefficient is "
      << figure->getArea() << "\n" << "Frame width of figure after scaling is: "
      << figure->getFrameRect().width << "\n" << "Frame height of figure after\
 scaling is " << figure->getFrameRect().height << "\n\n\n";
  }

  return 0;
}
