#include <iostream>
#include <typeinfo>
#include "../common/rectangle.hpp"
#include "../common/circle.hpp"
#include "../common/composite-shape.hpp"

inline void print(const std::shared_ptr<konovalov::Shape>& shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Not possible print nullptr shape!!!");
  }
  shape->getFrameRect();
  std::cout << "Shape: " << typeid(*shape).name() << "!!!" << "\n";
  std::cout << "Frame rectangle(width, height): (" << shape->getFrameRect().width
    << ", " << shape->getFrameRect().height << ")" << "\n";
  std::cout << "Frame rectangle position(x, y): (" << shape->getFrameRect().pos.x << ", "
    << shape->getFrameRect().pos.y << ")" << "\n";
  std::cout << "Area of shape: " << shape->getArea() << "\n";
}

int main()
{
  std::shared_ptr<konovalov::Shape> rectangle =
    std::make_shared<konovalov::Rectangle>(1.0, 2.2, konovalov::point_t{0.0, 0.0});
  std::shared_ptr<konovalov::Shape> circle =
    std::make_shared<konovalov::Circle>(5.1, konovalov::point_t{0.0, 0.0});
  std::shared_ptr<konovalov::Shape> rectangleForComposite =
    std::make_shared<konovalov::Rectangle>(1.0, 1.2, konovalov::point_t{0.0, 0.0});
  std::shared_ptr<konovalov::Shape> circleForComposite =
    std::make_shared<konovalov::Circle>(5.1, konovalov::point_t{0.0, 0.0});
  konovalov::CompositeShape tempCompositeShape = konovalov::CompositeShape();
  tempCompositeShape.pushShapeBack(rectangleForComposite);
  tempCompositeShape.pushShapeBack(circleForComposite);
  std::shared_ptr<konovalov::Shape> compositeShape =
    std::make_shared<konovalov::CompositeShape>(tempCompositeShape);

  std::unique_ptr<std::shared_ptr<konovalov::Shape>[]> shapes =
    std::make_unique<std::shared_ptr<konovalov::Shape>[]>(3);
  shapes[0] = rectangle;
  shapes[1] = circle;
  shapes[2] = compositeShape;

  for (int i = 0; i < 3; ++i)
  {
    print(shapes[i]);
    std::cout << "\n";
    shapes[i]->move(1.1, 2.28);
    print(shapes[i]);
    std::cout << "\n";
    shapes[i]->move({1.0, 1.0});
    print(shapes[i]);
    std::cout << "\n";
    shapes[i]->scale(2.0);
    print(shapes[i]);
    std::cout << "---------------\n";
  }

  return 0;
}
