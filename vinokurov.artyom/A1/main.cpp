#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t dot = {1.1, 1.1};

  Rectangle rectangle(dot, 12.345, 14.21);
  Circle circle(dot, 13.2);

  Shape* figures[2] = {&rectangle, &circle};

  for (Shape* shape : figures)
  {
    shape->print();
    std::cout << "\nArea of the figure is " << shape->getArea();
    std::cout << "\nFrame width of the figure is " << shape->getFrameRect().width 
      << ", position is at x: " << shape->getFrameRect().pos.x;
    shape->move(21.4, 43.6);
    shape->print();
    shape->move({ -1.6, -70.6567 });
    shape->print();
  }
  
  return 0;
};
