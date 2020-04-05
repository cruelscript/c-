#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle rectangle(6.8, 4.2, { -3, -9 });
  Circle circle(5.7, { 2.5, 8 });
  Shape* pRectangle = &rectangle;
  Shape* pCircle = &circle;

  std::cout << "Rectangle area: " << pRectangle->getArea() << "\n";
  std::cout << "Circle area: " << pCircle->getArea() << "\n\n";

  std::cout << "Frame rectangle parameters for rectangle:\nHeight: " << pRectangle->getFrameRect().height
      << "\nWidth: " << pRectangle->getFrameRect().width << "\nCenter at the point: ("
          << pRectangle->getFrameRect().pos.x << "; " << pRectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Frame rectangle parameters for circle:\nHeight: " << pCircle->getFrameRect().height
      << "\nWidth: " << pCircle->getFrameRect().width << "\nCenter at the point: ("
          << pCircle->getFrameRect().pos.x << "; " << pCircle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move a rectangle to the point (2; 6.3)\n";
  pRectangle->move({ 2, 6.3 });
  std::cout << "Center at the point: (" << pRectangle->getFrameRect().pos.x << "; " << pRectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move a circle to the point (-5.9; 2)\n";
  pCircle->move({ -5.9, 2 });
  std::cout << "Center at the point: (" << pCircle->getFrameRect().pos.x << "; " << pCircle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move the rectangle along the X axis by 3 and along the Y axis by -4\n";
  pRectangle->move(3, -4);
  std::cout << "Center at the point: (" << pRectangle->getFrameRect().pos.x << "; " << pRectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Move the circle along the X axis by -2 and the Y axis by 6.7\n";
  pCircle->move(-2, 6.7);
  std::cout << "Center at the point: (" << pCircle->getFrameRect().pos.x << "; " << pCircle->getFrameRect().pos.y << ")\n\n";

  return 0;
}
