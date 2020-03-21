#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "circle.hpp"

void print(const Shape* shape)
{
  assert(shape != nullptr);

  std::cout << "Name of shape: " << shape->getName() << '\n';
  std::cout << " - Area: " << shape->getArea() << '\n';

  rectangle_t term = shape->getFrameRect();

  std::cout << " - Center of frame rectangle: (" << term.pos.x << "; " << term.pos.y << ")\n";
}

int main()
{
  Rectangle rectangleOne(4.33, 2, {-1.4, 1.33});
  Circle circleOne(1.1, {1.0, 1.9});
  Circle circleTwo(2.9, {-3.5, 2.1});

  Shape* array[3] = {&rectangleOne, &circleOne, &circleTwo};

  point_t center{2, 3};

  for (int i = 0; i < 3; ++i)
  {
    print(array[i]);
    array[i]->move(center);
    print(array[i]);
  }

  return 0;
}
