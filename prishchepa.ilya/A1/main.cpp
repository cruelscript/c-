#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

void printPoint(const point_t & point)
{
  std::cout << "(" << point.x << "; " << point.y << ")";
}

void printFrameRectangle(const rectangle_t & rect)
{
  std::cout << "Frame rectangle " << rect.width << "x" << rect.height << " at ";
  printPoint(rect.pos);
  std::cout << "\n";
}

int main()
{
  Circle circle({10.0, 10.0}, 5.5);
  Rectangle rectangle({55.5, 55.5}, 10.0, 20.0);

  circle.print(std::cout);
  std::cout << "\n  Position: ";
  printPoint(circle.getPosition());
  std::cout << "\n  Radius: " << circle.getRadius();
  std::cout << "\n  Area: " << circle.getArea();
  std::cout << "\n  ";
  printFrameRectangle(circle.getFrameRect());

  std::cout << "\n";

  rectangle.print(std::cout);
  std::cout << "\n  Position: ";
  printPoint(rectangle.getPosition());
  std::cout << "\n  Width: " << rectangle.getWidth();
  std::cout << "\n  Height: " << rectangle.getHeight();
  std::cout << "\n  Area: " << rectangle.getArea();
  std::cout << "\n  ";
  printFrameRectangle(rectangle.getFrameRect());

  std::cout << "\n";

  Shape * shapes[] = {&circle, &rectangle};

  for (int i = 0; i < 2; i++)
  {
    std::cout << "Figure #" << i << ": ";
    shapes[i]->print(std::cout);
    std::cout << "\n  ";
    printFrameRectangle(shapes[i]->getFrameRect());
    std::cout << "  Area: " << shapes[i]->getArea() << "\n";
    std::cout << "  Position: ";
    printPoint(shapes[i]->getPosition());
    std::cout << "\n";
    point_t newPosition{2.1 * (i + 1), 2.0 * (2 - i)};
    std::cout << "Moving to point ";
    printPoint(newPosition);
    std::cout << "...\n";
    shapes[i]->move(newPosition);
    std::cout << "  Position: ";
    printPoint(shapes[i]->getPosition());
    std::cout << "\n";
    std::cout << "Increasing x coordinate by 0.8 and decreasing y coordinate by 0.4...\n";
    shapes[i]->move(0.8, -0.4);
    std::cout << "  Position: ";
    printPoint(shapes[i]->getPosition());
    std::cout << "\n\n";
  }


  return 0;
}
