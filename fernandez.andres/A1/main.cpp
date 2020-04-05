#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

int main()
{
  point_t point = { 32, 25 };
  Rectangle rect(point, 30, 40);
  Circle circle({ 100, 150 }, 50);
  Shape* array[2] = { &rect, &circle };

  point = { 25, 25 };

  for (int i = 0; i < 2; i++)
  {
    array[i]->print(std::cout);
    std::cout << "Area = " << array[i]->getArea() << '\n';

    std::cout << "Frame Rects" << '\n';
    std::cout << " center (" << array[i]->getFrameRect().pos.x << ", " << array[i]->getFrameRect().pos.y
      << ") width = " << array[i]->getFrameRect().width << " height = " << array[i]->getFrameRect().height << '\n';

    std::cout << "Move to (25, 25)" << '\n';
    array[i]->move(point);
    array[i]->print(std::cout);
    std::cout << "Area = " << array[i]->getArea() << '\n';
    std::cout << "Frame rect " << " center (" << array[i]->getFrameRect().pos.x << ", "
      << array[i]->getFrameRect().pos.y << ") width = " << array[0]->getFrameRect().width
      << " height = " << array[i]->getFrameRect().height << '\n';

    std::cout << "Move +5, -7" << '\n';
    array[i]->move(5, -7);
    array[i]->print(std::cout);
    std::cout << "Area = " << array[i]->getArea() << '\n';
    std::cout << "Frame rect " << " center (" << array[i]->getFrameRect().pos.x << ", "
      << array[i]->getFrameRect().pos.y << ") width = " << array[i]->getFrameRect().width
      << " height = " << array[i]->getFrameRect().height << '\n';

    std::cout << "    --------   *   ---------" << '\n';
  }

  return 0;
}
