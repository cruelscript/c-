#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  Circle circle1(point_t{2.4, -1}, 3);
  Circle circle2(1.6, 3, 2.5);
  Rectangle rectangle1(point_t{1.5, 2}, 3.1, 5.7);
  Rectangle rectangle2(4, 2.9, 5.6, 9.1);

  Shape* figures[] = {&circle1, &circle2, &rectangle1, &rectangle2};
  
  for (int i = 0; i < 4; i++)
  {
    std::cout << "Area of figure number " << i + 1 << 
      " is " << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of figure number " << i + 1 << 
      " is (" << figures[i]->getFrameRect().pos.x << "; " 
      << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Frame Rectangle size of figure number " << i + 1 << " is " 
      << figures[i]->getFrameRect().width << "x" 
      << figures[i]->getFrameRect().height << "\n";
  }

  std::cout << "The position of the first circle is ("
    << figures[0]->getPos().x << "; "
    << figures[0]->getPos().y << ")\n";
  std::cout << "Moving the first circle to a point with coordinates (2;3)" << "\n";
  figures[0]->move({2, 3});
  std::cout << "Now the position of the first circle is ("
    << figures[0]->getPos().x << "; "
    << figures[0]->getPos().y << ")\n";

  std::cout << "The position of the first rectangle is ("
    << figures[2]->getPos().x << "; "
    << figures[2]->getPos().y << ")\n";
  std::cout << "Moving the sides of first rectangle by 2 in width and 3 in height" << "\n";
  figures[2]->move(2, 3);
  std::cout << "Now the position of the first rectangle is ("
    << figures[2]->getPos().x << "; "
    << figures[2]->getPos().y << ")\n";

  return 0;
}
