#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void demonstrate(Shape *shape, const char *shapeType)
{
  std::cout << "\nShape: " << shapeType << '\n';
  std::cout << "Shape's area: " << shape->getArea() << '\n';
  std::cout << "Frame rectangle position: (" << shape->getFrameRect().pos.x << " ; "
            << shape->getFrameRect().pos.y << ')' << '\n';
  std::cout << "Frame rectangle sizes (w ; h): (" << shape->getFrameRect().width << " ; "
            << shape->getFrameRect().height << ')' << '\n';
  std::cout << shapeType << "'s pos: (" << shape->getFrameRect().pos.x << " ; " << shape->getFrameRect().pos.y << ')' << '\n';

  shape->move({2.28, 3.22});

  std::cout << "Move " << shapeType << "pos to (2.28; 3.22) and now " << shapeType << "'s pos is ("
            << shape->getFrameRect().pos.x << " ; " << shape->getFrameRect().pos.y << ')' << '\n';

  shape->move(0.94, -0.94);
  std::cout << "Move" << shapeType << "'s pos on (0.94, -0.94) and now " << shapeType << "'s pos is ("
            << shape->getFrameRect().pos.x << " ; " << shape->getFrameRect().pos.y << ')' << '\n';
}

int main()
{
  Circle circle = Circle(5.7, 0.0, 0.0);
  Rectangle rectangle = Rectangle(5.5, 7.5, 5.0, 5.0);
  
  Shape *shapes[] = {&circle, &rectangle};

  const char *shapeType = nullptr;
  for (int i = 0; i < 2; i++) {
    shapeType = (i == 0 ? "circle" : "rectangle");
    demonstrate(shapes[i], shapeType);
  }

  return 0;
}
