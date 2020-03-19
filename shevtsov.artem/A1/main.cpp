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
  point_t center {2, 3};
  Shape* array[3] = {new Rectangle(4.33, 2, {-1.4, 1.33}),
                     new Circle(1.1, {1.0, 1.9}),
                     new Circle(2.9, {-3.5, 2.1})};

  for (int i = 0; i < 3; ++i)
  {
    print(array[i]);
    array[i]->move(center);
    print(array[i]);
  }

  for (int i = 0; i < 3; ++i)
  {
    delete array[i];
  }

  return 0;
}
