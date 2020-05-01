#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "base-types.hpp"

void test(talipova::Shape& shape);

int main()
{
  std::srand(std::time(0));
  talipova::Rectangle testCorrectRect(1, 2, 3, 4);
  talipova::Circle testCorrectCircle(0, 1, 2);
  talipova::Rectangle testCorrectRect2({ 0.1, 2.2 }, 3.3, 4.1);
  talipova::Circle testCorrectCircle2({ -2.35, 30 }, 3.14);
  std::cout << "Testing a correct rectangle with width = 3 and height = 4\n\n";
  test(testCorrectRect);
  std::cout << "\n__________\n";
  std::cout << "Testing a correct circle with radius = 2\n\n";
  test(testCorrectCircle);
  std::cout << "\n__________\n";
  std::cout << "Testing a correct rectangle with width = 3.3 and height = 4.1\n\n";
  test(testCorrectRect2);
  std::cout << "\n__________\n";
  std::cout << "Testing a correct circle with radius = 3.14\n\n";
  test(testCorrectCircle2);
  std::cout << "\n__________\n";
   
  return 0;
}

void test(talipova::Shape& ob)
{
  std::cout << "Position: x = " << ob.getPosition().x << ", y = " << ob.getPosition().y << '\n';
  std::cout << "Frame rectangle's position: x = " << ob.getFrameRect().pos.x << ", y = " << ob.getFrameRect().pos.y << '\n';
  std::cout << "Frame rectangle's width: " << ob.getFrameRect().width << '\n';
  std::cout << "Frame rectangle's height: " << ob.getFrameRect().height << '\n';
  talipova::point_t point = { 1, 1 };
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
  double coeff = 5.09;
  std::cout << "Scaling a shape with a coefficient " << coeff << '\n';
  ob.scale(coeff);
  std::cout << "Shape's area after scale: " << ob.getArea() << '\n';
}
