#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  setlocale(LC_ALL, "Russian");

  Shape* rectangle = new Rectangle(6.8, 4.2, { -3, -9 });
  Shape* circle = new Circle(5.7, { 2.5, 8 });

  std::cout << "������� ��������������: " << rectangle->getArea() << "\n";
  std::cout << "������� �����: " << circle->getArea() << "\n\n";

  std::cout << "��������� ��������������, ��������������� �������������:\n�����: " << rectangle->getFrameRect().height
      << "\n������: " << rectangle->getFrameRect().width << "\n����� � �����: ("
          << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "��������� ��������������, ��������������� �����:\n�����: " << circle->getFrameRect().height
      << "\n������: " << circle->getFrameRect().width << "\n����� � �����: ("
          << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  std::cout << "����������� �������������� � ����� (2; 6,3)\n";
  rectangle->move({ 2, 6.3 });
  std::cout << "����� � �����: (" << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "����������� ����� � ����� (-5,9; 2)\n";
  circle->move({ -5.9, 2 });
  std::cout << "����� � �����: (" << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  std::cout << "����������� �������������� �� ��� X �� 3 � �� ��� Y �� -4\n";
  rectangle->move(3, -4);
  std::cout << "����� � �����: (" << rectangle->getFrameRect().pos.x << "; " << rectangle->getFrameRect().pos.y << ")\n\n";

  std::cout << "����������� ����� �� ��� X �� -2 � �� ��� Y �� 6,7\n";
  circle->move(-2, 6.7);
  std::cout << "����� � �����: (" << circle->getFrameRect().pos.x << "; " << circle->getFrameRect().pos.y << ")\n\n";

  delete rectangle;
  delete circle;

  return 0;
}
