#include <iostream>
#include <typeinfo>
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Rectangle rectangle(point_t{2, 1.5}, 2, 5);
  Circle circle(point_t{1, 1}, 1);
  Shape *figures[] = {&rectangle, &circle};
  for (int i = 0; i < 2; i++) {
    std::string nameObj = typeid(*figures[i]).name();
    nameObj = nameObj.substr(1);
    std::cout << "Area of " << nameObj << " is " << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of " << nameObj << " is (" << figures[i]->getFrameRect().pos.x << "; "
              << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Width frame Rectangle of " << nameObj << " is " << figures[i]->getFrameRect().width
              << " and height is " << figures[i]->getFrameRect().height << "\n\n";
    figures[i]->move({1, 2});
    figures[i]->move(1, 2);
    std::cout << "Position " << std::string(typeid(*figures[i]).name()).substr(1) << "after moving in (1, 2) is ("
              << figures[i]->getFrameRect().pos.x << "; " << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Position " << std::string(typeid(*figures[i]).name()).substr(1) << "after moving to offset (1, 2) is ("
              << figures[i]->getFrameRect().pos.x << "; " << figures[i]->getFrameRect().pos.y << ")\n\n";
  }
  return 0;
}
