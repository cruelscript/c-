#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 4.0);
  std::cout << "Rectangle area before using method scale is " << rectangle.getArea() << "\n";
  rectangle.scale(2.0);
  std::cout << "Rectangle area after using method scale with coefficient 2.0 is : " << rectangle.getArea() << "\n\n";

  kubov::Circle circle({0.0, 0.0}, 10.0);
  std::cout << "Circle area before using method scale: " << circle.getArea() << "\n";
  circle.scale(2.0);
  std::cout << "Circle area after using method scale with coefficient 2.0: " << circle.getArea() << "\n";

  return 0;
}


