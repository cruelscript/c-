#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void test(Shape &shape);

int main()
{
  std::srand(std::time(0));
  std::cout << "Testing a correct rectangle with width = 3 and height = 4\n\n";
  Rectangle testCorrectRect(1, 2, 3, 4);
  test(testCorrectRect);
  std::cout << "\n__________\n";
  std::cout << "Testing a correct circle with radius = 2\n\n";
  Circle testCorrectCircle(0, 1, 2);
  test(testCorrectCircle);
  std::cout << "\n__________\n";
  std::cout << "Testing a correct rectangle with width = 3.3 and height = 4.1\n\n";
  Rectangle testCorrectRect2({ 0.1, 2.2 }, 3.3, 4.1);
  test(testCorrectRect2);
  std::cout << "\n__________\n";
  std::cout << "Testing a correct circle with radius = 3.14\n\n";
  Circle testCorrectCircle2({ -2.35, 30 }, 3.14);
  test(testCorrectCircle2);
  std::cout << "\n__________\n";
  return 0;
}

void test(Shape &ob)
{
  std::cout << "Position: x = " << ob.getPosition().x << ", y = " << ob.getPosition().y << '\n';
  std::cout << "Frame rectangle's position: x = " << ob.getFrameRect().pos.x << ", y = " << ob.getFrameRect().pos.y << '\n';
  std::cout << "Frame rectangle's width: " << ob.getFrameRect().width << '\n';
  std::cout << "Frame rectangle's height: " << ob.getFrameRect().height << '\n';
  point_t point = { 0, 0 };
  std::cout << "Moving the object to a point: x = " << point.x << ", y = " << point.y << '\n';
  ob.move(point);
  std::cout << "Position: x = " << ob.getPosition().x << ", y = " << ob.getPosition().y << '\n';
  double dx = std::rand() % 10;
  double dy = -(std::rand() % 10);
  std::cout << "Moving the object along the abscissa by: " << dx << '\n';
  std::cout << "Moving the object along the ordinate by: " << dy << '\n';
  ob.move(dx, dy);
  std::cout << "Position: x = " << ob.getPosition().x << ", y = " << ob.getPosition().y << '\n';
  std::cout << "Shape's area: " << ob.getArea() << '\n';
}
