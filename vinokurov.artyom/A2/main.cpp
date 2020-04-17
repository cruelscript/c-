#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  vinokurov::point_t dot = {1.1, 1.1};

  vinokurov::Rectangle rectangle(dot, 12.345, 14.21);
  vinokurov::Circle circle(dot, 13.2);

  vinokurov::Shape* figures[2] = {&rectangle, &circle};

  for (vinokurov::Shape* shape : figures)
  {
    shape->print(std::cout);
    std::cout << "\nArea of the figure is " << shape->getArea();

    std::cout << "\nFrame width of the figure is " << shape->getFrameRect().width
      << ", frame height is " << shape->getFrameRect().height
      << ", position is at x: " << shape->getFrameRect().pos.x
      << ", at y: " << shape->getFrameRect().pos.y;

    shape->move(21.4, 43.6);
    shape->print(std::cout);
    shape->move({-1.6, -70.6567});
    shape->print(std::cout);
    shape->scale(100.02);
    shape->print(std::cout);
  }
  
  return 0;
};
