#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t mid = {0.0, 0.0};
  Rectangle rect(10.10, 12.12, mid);
  Circle circle(5.12, mid);
  Shape* figures[2] = {&rect, &circle};
  for (Shape* shape : figures)
  {
    std::cout << "Your figures: ";
    shape->print();
    std::cout << " Area of rectangle: " << shape->getArea();
    std::cout << " \n Frame rectangle: " << " Width: " << shape->getFrameRect().width
      << " Height: " << rect.getFrameRect().height << " X: " << shape->getFrameRect().pos.x
      << " Y: " << shape->getFrameRect().pos.y;
    shape->move(11.3, 7.0);
    std::cout << " \nYour rectangle after move: ";
    shape->print();
    shape->move(mid);
    std::cout << "Your rectangle after move back: ";
    shape->print();
  }
  return 0;
};
