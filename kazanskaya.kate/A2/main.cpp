#include <iostream>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  kazanskaya::Rectangle rectangle(4.7, 5.3, { 2.5, 2.5 });
  kazanskaya::Circle circle(2.5, { -1.5, -3.0 });
  kazanskaya::Shape* figures[] = { &rectangle, &circle };

  for (kazanskaya::Shape* figure : figures)
  {
    std::cout << "Figure:\n";

    std::cout << "Start position: ( " << figure->getFrameRect().pos.x << ", "
      << figure->getFrameRect().pos.y << " )\n";

    std::cout << "Width of figure: " << figure->getFrameRect().width
      << "\nHeight of figure: " << figure->getFrameRect().height << "\n\n";

    std::cout << "Move figure along coordinate axis by X and Y: \n";
    figure->move(1.2, 7.3);
    std::cout << "New position (after move along axis): (" << figure->getFrameRect().pos.x << ", "
      << figure->getFrameRect().pos.y << " )\n\n";

    std::cout << "Move figure to a new center (X, Y): \n";
    figure->move({ 5.5, 3.0 });
    std::cout << "New position (new center): (" << figure->getFrameRect().pos.x << ", "
      << figure->getFrameRect().pos.y << " )\n\n";

    std::cout << "Figure scaling with a coefficient 5.1: \n";
    figure->scale(5.1);
    std::cout << "Area of figyre after scaling = " << figure->getArea();
    std::cout << "\nWidth of figure: " << figure->getFrameRect().width
      << "\nHeight of figure: " << figure->getFrameRect().height << "\n\n\n";
  }
  return 0;
};
