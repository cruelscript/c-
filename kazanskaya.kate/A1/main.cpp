#include<iostream>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Rectangle rectangle(4.7, 5.3, {2.5, 2.5});
  Circle circle(2.5, {-1.5, -3.0});
  Shape* figures[2] = {&rectangle, &circle};

  for (int i = 0; i < 2; i++)
  {
    std::cout << "Figure " << i + 1 << ":\n\n";

    std::cout << "Start position: ( " << figures[i]->getFrameRect().pos.x << ", "
      << figures[i]->getFrameRect().pos.y << " )\n";

    if (i == 0)
    {
      std::cout << "Width of figure: " << figures[0]->getFrameRect().width
        << "\nHeight of figure: " << figures[0]->getFrameRect().height << "\n";
    }

    std::cout << "\nArea of figure = " << figures[i]->getArea() << "\n\n";

    std::cout << "Move figure along coordinate axis by X and Y: \n";
    figures[i]->move(1.2, 7.3);
    std::cout << "New position (after move along axis): (" << figures[i]->getFrameRect().pos.x << ", "
      << figures[i]->getFrameRect().pos.y << " )\n\n";

    std::cout << "Move figure to a new center (X, Y): \n";
    figures[i]->move({5.5, 3.0});
    std::cout << "New position (new center): (" << figures[i]->getFrameRect().pos.x << ", "
      << figures[i]->getFrameRect().pos.y << " )\n\n\n";
  }
  return 0;
};
