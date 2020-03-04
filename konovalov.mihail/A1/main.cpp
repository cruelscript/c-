#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

inline void print(const Shape *shape)
{
  std::cout << "Shape: " << typeid(*shape).name() << "!!!" << "\n";
  std::cout << "Frame rectangle(width, height): (" << shape->getFrameRect().width_
            << ", " << shape->getFrameRect().height_ << ")" << "\n";
  std::cout << "Frame rectangle position(x, y) : (" << shape->getFrameRect().pos_.x_ << ", "
            << shape->getFrameRect().pos_.y_ << ")" << "\n";
  std::cout << "Area of shape: " << shape->getArea() << "\n";
}

int main()
{
  Rectangle rectangle({2.28, 3.32, {0.1, 0.0}});
  Circle circle(8.9, {1.1, 3.2});
  Shape *shapes[2] = {&rectangle, &circle};

  for (Shape *shape: shapes)
  {
    print(shape);
    std::cout << "\n";
    shape->move(1.1, 2.28);
    print(shape);
    std::cout << "\n";
    shape->move({1.0, 1.0});
    print(shape);
    std::cout << "---------------\n";
  }
  return 0;
}
