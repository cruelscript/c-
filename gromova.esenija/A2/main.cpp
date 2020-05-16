#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  gromova::Rectangle rectangle(6.8, 4.2, { -3, -9 });
  gromova::Circle circle(5.7, { 2.5, 8 });
  const int SIZE = 2;
  gromova::Shape* shapes[SIZE] = { &rectangle, &circle };

  for (int i = 0; i < SIZE; ++i)
  {
    (i == 0) ? std::cout << "-Rectangle-\n\n" : std::cout << "-Circle-\n\n";
    std::cout << "Area: " << shapes[i]->getArea() << "\n";
    std::cout << "Frame rectangle parameters for circle:\nHeight: " << shapes[i]->getFrameRect().height
      << "\nWidth: " << shapes[i]->getFrameRect().width << "\nCenter at the point: (" << shapes[i]->getFrameRect().pos.x
      << "; " << shapes[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Move this shape to the point (4.7; 6.3)\nAfter moving ";
    shapes[i]->move({ 4.7, 6.3 });
    std::cout << "center at the point: (" << shapes[i]->getFrameRect().pos.x << "; " << shapes[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Move this shape along the X axis by 3 and along the Y axis by -4\nAfter moving ";
    shapes[i]->move(3, -4);
    std::cout << "center at the point: (" << shapes[i]->getFrameRect().pos.x << "; " << shapes[i]->getFrameRect().pos.y << ")\n";
    shapes[i]->scale(3);
    std::cout << "Area of this shape after scaling: " << shapes[i]->getArea() << "\n";
    std::cout << "\n";
  }

  return 0;
}
