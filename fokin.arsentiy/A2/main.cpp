#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  fokin::Rectangle testRectangle{ 4.0, 5.0, { 2.6, -1.4 } };
  std::cout << "Rectangle's area: " << testRectangle.getArea() << "\n";
  fokin::rectangle_t frameRectangle = testRectangle.getFrameRect();
  std::cout << "Height and width of frame rectangle: " << frameRectangle.height << ", " << frameRectangle.width << "\n";
  std::cout << "Center of test and frame rectangle: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n";

  testRectangle.move({ -5.1, 9.7 });
  testRectangle.move(5.1, -9.7);
  frameRectangle = testRectangle.getFrameRect();
  std::cout << "Center of test and frame rectangle after moving: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n";

  testRectangle.scale(3);
  frameRectangle = testRectangle.getFrameRect();
  std::cout << "Height and width of test and frame rectangle after scaling by coefficient = 3: " << frameRectangle.height << ", " << frameRectangle.width << "\n";
  std::cout << "Rectangle's area after scaling: " << testRectangle.getArea() << "\n\n";


  fokin::Circle testCircle{ { 5.2, -7.5 }, 4.0 };
  std::cout << "Circle's area: " << testCircle.getArea() << "\n";
  frameRectangle = testCircle.getFrameRect();
  std::cout << "Height and width of frame rectangle: " << frameRectangle.height << ", " << frameRectangle.width << "\n";
  std::cout << "Center of circle and frame rectangle: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n";

  testCircle.move({ 6.0, -1.6 });
  testCircle.move(-6.0, 1.6);
  frameRectangle = testCircle.getFrameRect();
  std::cout << "Center of test circle and frame rectangle after moving: (" << frameRectangle.pos.x << ", " << frameRectangle.pos.y << ")\n";

  testCircle.scale(2);
  frameRectangle = testCircle.getFrameRect();
  std::cout << "Height and width of frame rectangle after scaling by coefficient = 2: " << frameRectangle.height << ", " << frameRectangle.width << "\n";
  std::cout << "Circle's area after scaling: " << testCircle.getArea() << "\n\n";


  fokin::Shape* shapes[2] = { &testRectangle, &testCircle };
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
