#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  Shape* figure = nullptr;
  Rectangle rect_ob(point_t{ 6.7, 2.4 }, 10.63, 5.1);
  figure = &rect_ob;
  std::cout << "Rectangle area: " << figure->getArea() <<  "\n\n";

  figure->move(4.6, -6.7);
  figure->show_position(figure);

  figure->show_frame(figure);

  point_t rect_move;
  rect_move.x = 22;
  rect_move.y = -14;
  figure->move(rect_move);
  figure->show_position(figure);

  Circle circle_ob(point_t{ 1.4, 12.3 }, 6.7);
  figure = &circle_ob;
  std::cout << "Circle area: " << figure->getArea() <<  "\n\n";

  figure->show_frame(figure);

  figure->move(11.6, -20.4);
  figure->show_position(figure);

  point_t circle_move;
  circle_move.x = 35.6;
  circle_move.y = -5.765;
  figure->move(circle_move);
  figure->show_position(figure);
}
