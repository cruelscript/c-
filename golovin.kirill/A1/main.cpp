#include <iostream>
#include <typeinfo>
#include "circle.hpp"
#include "rectangle.hpp"


int main() {
  Rectangle rectangle(point_t{2, 1.5}, 2, 5);
  Circle circle(point_t{1, 1}, 1);


  Shape *figures[] = {&rectangle, &circle};

  for (int i = 0; i < 2; i++) {
    std::string nameObj = typeid(*figures[i]).name();
    nameObj = nameObj.substr(1);
    std::cout << "Area of " << nameObj << " is " << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of " << nameObj << " is (" << figures[i]->getFrameRect().pos.x_ << "; "
              << figures[i]->getFrameRect().pos.y_ << ")\n";
    std::cout << "Width frame Rectangle of " << nameObj << " is " << figures[i]->getFrameRect().width_
              << " and height is " << figures[i]->getFrameRect().height_ << "\n\n";
  }

  std::cout << "Position of circle is (" << figures[0]->getPos().x_ << "; " << figures[0]->getPos().y_ << ")\n";

  figures[0]->move({1, 2});
  figures[1]->move(1, 2);
  std::cout << "Position " << std::string(typeid(*figures[0]).name()).substr(1) << "after moving in (2, 3) is ("
            << figures[0]->getPos().x_ << "; " << figures[0]->getPos().y_ << ")\n\n";

  std::cout << "Position of rectangle is (" << figures[1]->getPos().x_ << "; " << figures[1]->getPos().y_ << ")\n";
  std::cout << "Moving the sides of first rectangle by 2 in width and 3 in height" << "\n";

  std::cout << "Position " << std::string(typeid(*figures[1]).name()).substr(1) << "after moving to offset (2, 3) is ("
            << figures[1]->getPos().x_ << "; " << figures[1]->getPos().y_ << ")\n";

  return 0;
}
