#include <iostream>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

void printStatus(const double& area, const rectangle_t& rect)
{
  std::cout << "Area = " << area << '\n';
  std::cout << "Frame Rects" << '\n';
  std::cout << "center (" << rect.pos.x << ", " << rect.pos.y
    << ") width = " << rect.width << " height = " << rect.height << '\n';
}

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
    printStatus(array[i]->getArea(), array[i]->getFrameRect());

    std::cout << "Move to (25, 25)" << '\n';
    array[i]->move(point);
    array[i]->print(std::cout);
    printStatus(array[i]->getArea(), array[i]->getFrameRect());

    std::cout << "Move +5, -7" << '\n';
    array[i]->move(5, -7);
    array[i]->print(std::cout);
    printStatus(array[i]->getArea(), array[i]->getFrameRect());

    std::cout << "    --------   *   ---------" << '\n';
  }

  return 0;
}
