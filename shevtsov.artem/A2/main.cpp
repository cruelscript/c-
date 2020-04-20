#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void print(const shevtsov::Shape* shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Null pointer in print()");
  }

  shape->printInfo(std::cout);
  std::cout << " - Area: " << shape->getArea() << '\n';

  shevtsov::rectangle_t term = shape->getFrameRect();

  std::cout << " - Frame rectangle:\n";
  std::cout << " -- Center (x, y): (" << term.pos.x << "; " << term.pos.y << ")\n";
  std::cout << " -- Width: " << term.width << '\n';
  std::cout << " -- Height: " << term.height << '\n';
}

int main()
{
  shevtsov::Rectangle rectangle(4.33, 2, {-1.4, 1.33});
  shevtsov::Circle circle(1.1, {1.0, 1.9});

  shevtsov::Shape* array[2] = {&rectangle, &circle};

  shevtsov::point_t center{2, 3};

  for (int i = 0; i < 2; ++i)
  {
    print(array[i]);

    array[i]->move(-1, -1);
    print(array[i]);

    array[i]->move(center);
    print(array[i]);

    array[i]->scale(2.5);
    print(array[i]);

    std::cout << '\n';
  }

  return 0;
}
