#include <iostream>
#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  golovin::Rectangle rectangle(golovin::point_t{2, 1.5}, 2, 5);
  golovin::Circle circle(golovin::point_t{1, 1}, 1);
  golovin::Shape *figures[] = {&rectangle, &circle};
  std::string names[] = {"Rectangle", "Circle"};
  for (int i = 0; i < 2; i++)
  {
    std::cout << names[i] << ": \n";
    std::cout << "Area of " << names[i] << " is " << figures[i]->getArea() << "\n";
    figures[i]->scale(2);
    std::cout << "Area of " << names[i] << " after scalability 2x is " << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of " << names[i] << " is (" << figures[i]->getFrameRect().pos.x << "; "
              << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Width frame Rectangle of " << names[i] << " is " << figures[i]->getFrameRect().width
              << " and height is " << figures[i]->getFrameRect().height << "\n";
    figures[i]->move({1, 2});
    std::cout << "Position " << names[i] << " after moving in {1, 2} is (" << figures[i]->getFrameRect().pos.x << "; "
              << figures[i]->getFrameRect().pos.y << ")\n";
    figures[i]->move(1, 2);
    std::cout << "Position " << names[i] << " after moving to offset (1, 2) is (" << figures[i]->getFrameRect().pos.x
              << "; " << figures[i]->getFrameRect().pos.y << ")\n\n";
  }
  return 0;
}
