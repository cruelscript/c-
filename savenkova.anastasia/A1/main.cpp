#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle({ -1.1, 3.2 }, 2.3);
  Rectangle rectangle({ 0.3, 0.7 }, 3.12, 2.45);
  Shape *figures[] = { &rectangle, &circle };

  for (Shape *figure : figures)
  {
    std::cout << "Frame position (x, y): (" << figure->getFrameRect().pos.x
      << ", " << figure->getFrameRect().pos.y << ")\n"
      << "Frame width of figure is " << figure->getFrameRect().width << "\n"
      << "Frame height of figure is " << figure->getFrameRect().height << "\n\n";

    std::cout << "The figure's area is " << figure->getArea() << "\n\n";

    figure->move(3.4, 6.0);

    std::cout << "Frame position after moving figure along\
 abscissa and ordinates (x, y): (" << figure->getFrameRect().pos.x
      << ", " << figure->getFrameRect().pos.y << ")\n";

    figure->move({ 2.4, -5.5 });

    std::cout << "Frame position after moving figure to a new point (x, y): ("
      << figure->getFrameRect().pos.x << ", " << figure->getFrameRect().pos.y
      << ")\n\n\n\n";
  }

  return 0;
}
