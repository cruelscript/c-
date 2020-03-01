#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Shape *figures[2];
  figures[0] = new Rectangle(20., 10., 0., 0.);
  figures[1] = new Circle(5., 30., 30.);
  const char *myShapeType;

  for (int i = 0; i < 2; i++)
  {
    myShapeType = (i == 0 ? "rectangle" : "circle");
    std::cout << "Area of " << myShapeType << " " << figures[i]->getArea() << "\n";

    std::cout << "First position of " << myShapeType << " (" << figures[i]->getPoint().x << "; "
              << figures[i]->getPoint().y << ") \n";

    figures[i]->move({2., 2.});
    std::cout << "Move " << myShapeType << " to position (2; 2)\n";


    std::cout << "Second position of " << myShapeType << " (" << figures[i]->getPoint().x << "; "
              << figures[i]->getPoint().y << ") \n";

    figures[i]->move(2., 2.);
    std::cout << "Move " << myShapeType << " by x: 2 and y: 2\n";

    std::cout << "Third position of " << myShapeType << " (" << figures[i]->getPoint().x << "; "
              << figures[i]->getPoint().y << ") \n";

    std::cout << "Get frame rectangle: \nWidth: " << myShapeType << " " << figures[i]->getFrameRect().width
              << ", height: " << figures[i]->getFrameRect().height << ", position of x: "
              << figures[i]->getFrameRect().pos.x << ", position of y: " << figures[i]->getFrameRect().pos.x << "\n";
    delete figures[i];
  }
  return 0;
}
