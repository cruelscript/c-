#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  setlocale(LC_ALL, "Russian");

  Shape* rectangle = new Rectangle(6.8, 4.2, { -3, -9 });
  Shape* circle = new Circle(5.7, { 2.5, 8 });

  std::cout << "Прощадь прямоугольника: " << rectangle->getArea() << "\n";
  std::cout << "Площадь круга: " << circle->getArea() << "\n\n";

  std::cout << "Параметры прямоугольника, ограничивающего прямоугольник:\nДлина: " << rectangle->getFrameRect().height
      << "\nШирина: " << rectangle->getFrameRect().width << "\nЦентр в точке: ("
          << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Параметры прямоугольника, ограничивающего круга:\nДлина: " << circle->getFrameRect().height
      << "\nШирина: " << circle->getFrameRect().width << "\nЦентр в точке: ("
          << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Перемещение прямоугольника в точку (2; 6,3)\n";
  rectangle->move({ 2, 6.3 });
  std::cout << "Центр в точке: (" << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Перемещение круга в точку (-5,9; 2)\n";
  circle->move({ -5.9, 2 });
  std::cout << "Центр в точке: (" << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Перемещение прямоугольника по оси X на 3 и по оси Y на -4\n";
  rectangle->move(3, -4);
  std::cout << "Центр в точке: (" << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "Перемещение круга по оси X на -2 и по оси Y на 6,7\n";
  circle->move(-2, 6.7);
  std::cout << "Центр в точке: (" << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  delete rectangle;
  delete circle;

  return 0;
}
