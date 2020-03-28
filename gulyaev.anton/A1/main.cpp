#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectangle(20., 10., 0., 0.);
  Circle circle(5., 35., 30.);
  Shape *figures[2] = {&rectangle, &circle};

  for (int i = 0; i < 2; i++)
  {
    const char *myShapeType = (i == 0 ? "rectangle" : "circle");
    std::cout << "Area of " << myShapeType << " " << figures[i]->getArea() << "\n";

    std::cout << "First position of " << myShapeType << " (" << figures[i]->getFrameRect().pos.x << "; "
              << figures[i]->getFrameRect().pos.y << ") \n";

    figures[i]->move({2., 2.});
    std::cout << "Move " << myShapeType << " to position (2; 2)\n";

    std::cout << "Second position of " << myShapeType << " (" << figures[i]->getFrameRect().pos.x << "; "
              << figures[i]->getFrameRect().pos.y << ") \n";

    figures[i]->move(2., 2.);
    std::cout << "Move " << myShapeType << " by x: 2 and y: 2\n";

    std::cout << "Third position of " << myShapeType << " (" << figures[i]->getFrameRect().pos.x << "; "
              << figures[i]->getFrameRect().pos.y << ") \n";

    std::cout << "Get frame rectangle: \nWidth: " << myShapeType << " " << figures[i]->getFrameRect().width
              << ", height: " << figures[i]->getFrameRect().height << ", position of x: "
              << figures[i]->getFrameRect().pos.x << ", position of y: " << figures[i]->getFrameRect().pos.x << "\n";
  }
  return 0;
}
