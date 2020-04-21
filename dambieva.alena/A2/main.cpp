#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

void printFrame(const dambieva::rectangle_t & object)
{
  std::cout << "Frame width = " << object.width;
  std::cout << ", height = " << object.height << "\n";
  std::cout << "\tPosition: (" << object.pos.x << ";" << object.pos.y << ")";
}

void printInfo(const dambieva::Shape & object)
{
  std::cout << "\n\t";
  object.print(std::cout);
  std::cout << "\n\tShape's Area: " << object.getArea();
  std::cout << "\n\t";
  printFrame(object.getFrameRect());
  std::cout << "\n\n";
}

int main()
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
  dambieva::Circle circle(10.0, 10.0, 5.5);

  std::cout << "Rectangle Information:";
  printInfo(rectangle);
  std::cout << "Circle Information:";
  printInfo(circle);

  std::cout << "Increase the center of the rectangle to (3, 3)...\n";
  rectangle.move(3.0, 3.0);
  std::cout << "Change the height of the rectangle to 5, the width to 40...";
  rectangle.setHeight(5.0);
  rectangle.setWidth(40.0);
  std::cout << "\n\nUpdated Information:";
  printInfo(rectangle);
  std::cout << "Double the height and the width of the rectangle...";
  rectangle.scale(2.0);
  std::cout << "\n\nUpdated Information:";
  printInfo(rectangle);

  std::cout << "Decrease the center of the circle to (-2, -2)...\n";
  circle.move(-2.0, -2.0);
  std::cout << "Change the radius of the circle to 6...";
  circle.setRadius(6.0);
  std::cout << "\n\nUpdated Information:";
  printInfo(circle);
  std::cout << "Increase by four the radius of the circle...";
  circle.scale(4.0);
  std::cout << "\n\nUpdated Information:";
  printInfo(circle);

  dambieva::point_t centerRect {7.0, 2.0};
  std::cout << "Move the center of the rectangle to the point (7, 2)...\n";
  rectangle.move(centerRect);
  rectangle.print(std::cout);

  dambieva::point_t centerCircle {4.0, 5.0};
  std::cout << "\n\nMove the center of the circle to the point (4, 5)...\n";
  circle.move(centerCircle);
  circle.print(std::cout);
  std::cout << "\n\n";

  return 0;
}
