#include <iostream>
#include "circle.hpp"
#include "shape.hpp"
#include "rectangle.hpp"

int main()
{
  point_t point = { 32, 25 };
  Rectangle rect(point, 30, 40);
  Circle circle({ 100, 150 }, 50);
  Shape* array[2] = { &rect, &circle };
  array[0]->print();
  std::cout << "Area = " << array[0]->getArea() << '\n';
  array[1]->print();
  std::cout << "Area = " << array[1]->getArea() << '\n';

  std::cout << "Frame Rects" << '\n';
  std::cout << "for rect" << " center (" << array[0]->getFrameRect().pos.x << ", " << array[0]->getFrameRect().pos.y
      << ") width = " << array[0]->getFrameRect().width << " height = " << array[0]->getFrameRect().height << '\n';
  std::cout << "for circle" << " center (" << array[1]->getFrameRect().pos.x << ", " << array[1]->getFrameRect().pos.y
      << ") width = " << array[1]->getFrameRect().width << " height = " << array[1]->getFrameRect().height << '\n';

  std::cout << "Move rect to (25, 25)" << '\n';
  point = { 25, 25 };
  array[0]->move(point);
  array[0]->print();
  std::cout << "Area = " << array[0]->getArea() << '\n';
  std::cout << "Frame rect of rect" << " center (" << array[0]->getFrameRect().pos.x << ", "
      << array[0]->getFrameRect().pos.y << ") width = " << array[0]->getFrameRect().width
          << " height = " << array[0]->getFrameRect().height << '\n';

  std::cout << "Move circle +5, -7" << '\n';
  array[1]->move(5, -7);
  array[1]->print();
  std::cout << "Area = " << array[1]->getArea() << '\n';
  std::cout << "Frame rect of  circle" << " center (" << array[1]->getFrameRect().pos.x << ", "
      << array[1]->getFrameRect().pos.y << ") width = " << array[1]->getFrameRect().width
          << " height = " << array[1]->getFrameRect().height << '\n';
  return 0;
}
