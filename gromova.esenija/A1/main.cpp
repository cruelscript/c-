#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Shape* rectangle = new Rectangle(6.8, 4.2, { -3, -9 });
  Shape* circle = new Circle(5.7, { 2.5, 8 });

  std::cout << "Rectangle area: " << rectangle->getArea() << "\n";
  std::cout << "Circle area: " << circle->getArea() << "\n\n";

  std::cout << "Frame rectangle parameters for rectangle:\nHeight: " << rectangle->getFrameRect().height
      << "\nWidth: " << rectangle->getFrameRect().width << "\nCenter at the point: ("
          << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Frame rectangle parameters for circle:\nHeight: " << circle->getFrameRect().height
      << "\nWidth: " << circle->getFrameRect().width << "\nCenter at the point: ("
          << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move a rectangle to the point (2; 6.3)\n";
  rectangle->move({ 2, 6.3 });
  std::cout << "Center at the point: (" << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move a circle to the point (-5.9; 2)\n";
  circle->move({ -5.9, 2 });
  std::cout << "Center at the point: (" << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move the rectangle along the X axis by 3 and along the Y axis by -4\n";
  rectangle->move(3, -4);
  std::cout << "Center at the point: (" << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move the circle along the X axis by -2 and the Y axis by 6.7\n";
  circle->move(-2, 6.7);
  std::cout << "Center at the point: (" << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  delete rectangle;
  delete circle;

  return 0;
}
