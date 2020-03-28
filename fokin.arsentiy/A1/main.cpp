#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Rectangle testRectangle{ 4.0, 5.0, { 2.6, -1.4 } };
  std::cout << "Rectangle's area: " << testRectangle.getArea() << "\n";
  rectangle_t frameRectangle = testRectangle.getFrameRect();
  std::cout << "Height of test and frame rectangle: " << frameRectangle.height << "\n";
  std::cout << "Width of test and frame rectangle: " << frameRectangle.width << "n";
  std::cout << "Center of test and frame rectangle: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n";
  testRectangle.move({ -5.1, 9.7 });
  testRectangle.move(5.1, -9.7);
  frameRectangle = testRectangle.getFrameRect();
  std::cout << "New center of test and frame rectangle: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n\n";

  Circle testCircle{ { 5.2, -7.5 }, 4.0 };
  std::cout << "Circle's area: " << testCircle.getArea() << "\n";
  frameRectangle = testCircle.getFrameRect();
  std::cout << "Height of frame rectangle: " << frameRectangle.height << "\n";
  std::cout << "Width of frame rectangle: " << frameRectangle.width << "\n";
  std::cout << "Center of circle and frame rectangle: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n";
  testCircle.move({ 6.0, -1.6 });
  testCircle.move(-6.0, 1.6);
  frameRectangle = testCircle.getFrameRect();
  std::cout << "New center of test circle and frame rectangle: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n\n";

  Shape* shapes[2] = { &testRectangle, &testCircle };
  for (int i = 0; i < 2; i++)
  {
    std::cout << "Area of " << i + 1 << " figure: " << shapes[i]->getArea() << "\n";
    std::cout << "Center of " << i + 1 << " figure's frame rectangle: (" << shapes[i]->getFrameRect().pos.x << ", "
      << shapes[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Height of " << i + 1 << " figure's frame rectangle: " << shapes[i]->getFrameRect().height << "\n";
    std::cout << "Width of " << i + 1 << " figure's frame rectangle: " << shapes[i]->getFrameRect().width 
      << "\n--------------------------------------------\n";
  }

  return 0;
}
