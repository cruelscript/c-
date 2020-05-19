#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  potykanenko::Rectangle rectangle(10., 5., 0., 0.);
  potykanenko::Circle circle(10., 0., 0.);
  potykanenko::Shape *figures[2] = { &rectangle, &circle };

  for (int i = 0; i < 2; i++)
  {
    const char *figure = (i == 0 ? "rectangle" : "circle");
    std::cout << "Tests for " << figure << ":" << "\n";

    std::cout << "First locate of " << figure << " is "
      << "(" << figures[i]->getFrameRect().pos.x << ", " << figures[i]->getFrameRect().pos.y << ")" << "\n";

    std::cout << "Moving " << figure << " to x = 7, y = 4.5" << "\n";
    figures[i]->move(7., 4.5);

    std::cout << "Second locate of " << figure << " is "
      << "(" << figures[i]->getFrameRect().pos.x << ", " << figures[i]->getFrameRect().pos.y << ")" << "\n";

    std::cout << "Moving " << figure << " to point (3, 2)" << "\n";
    figures[i]->move({ 3., 2. });

    std::cout << "Third locate of " << figure << " is "
      << "(" << figures[i]->getFrameRect().pos.x << ", " << figures[i]->getFrameRect().pos.y << ")" << "\n";

    std::cout << "Moving " << figure << " to x = -1, y = 3" << "\n";
    figures[i]->move(-1., 3.);

    std::cout << "Fourth locate of " << figure << " is "
      << "(" << figures[i]->getFrameRect().pos.x << ", " << figures[i]->getFrameRect().pos.y << ")" << "\n";

    std::cout << "For " << figure << " area is " << figures[i]->getArea() << "\n";

    std::cout << "Frame of " << figure << ": "
      << "width = " << figures[i]->getFrameRect().width
      << ", height = " << figures[i]->getFrameRect().height << "\n";

    std::cout << "Scale of " << figure << " in 0.5 times" << "\n";
    figures[i]->scale(0.5);

    std::cout << "Frame of " << figure << ": "
      << "width = " << figures[i]->getFrameRect().width
      << ", height = " << figures[i]->getFrameRect().height << "\n";

    std::cout << "\n\n";
  }
  return 0;
}
