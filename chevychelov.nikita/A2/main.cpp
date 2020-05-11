#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  chevychelov::point_t mid = {0.0, 0.0};
  chevychelov::Rectangle rect(10.10, 12.12, mid);
  chevychelov::Circle circle(5.12, mid);
  chevychelov::Shape* figures[2] = {&rect, &circle};
  for (chevychelov::Shape* shape : figures)
  {
    std::cout << "Your figures: ";
    shape->print(std::cout);
    std::cout << " Area of figure: " << shape->getArea();
    std::cout << " \n Frame rectangle: " << " Width: " << shape->getFrameRect().width
      << " Height: " << rect.getFrameRect().height << " X: " << shape->getFrameRect().pos.x
      << " Y: " << shape->getFrameRect().pos.y;
    shape->move(11.3, 7.0);
    std::cout << " \nYour figure after move: ";
    shape->print(std::cout);
    shape->move(mid);
    std::cout << "Your figure after move back: ";
    shape->print(std::cout);
    std::cout << "Your figure after scale: ";
    shape->scale(2.15);
    shape->print(std::cout);
  }
  return 0;
};
