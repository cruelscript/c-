#include <iostream>
#include <memory>
#include "composite-shape.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printCompisiteShapeInfo(const talipova::CompositeShape& shapes);
void printShapeInfo(const std::shared_ptr<talipova::Shape>& shape);

int main()
{
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(3, -8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -7, 3);
  talipova::CompositeShape shapes1(1);
  shapes1.addShape(rectangle1);
  std::cout << "Size of the Composite shape(first) after adding one shape: " << shapes1.getSize() << '\n';
  talipova::CompositeShape shapes2(shapes1);
  shapes2.addShape(rectangle2);
  shapes2.addShape(circle1);
  std::cout << "Size of the Composite shape(second) after using copy const and adding two shapes: " << shapes2.getSize() << '\n';
  std::cout << "Further, all actions will be performed with the second Composite Shape\n";
  printCompisiteShapeInfo(shapes2);
  std::cout << "\nMove the comp. shape to point (4, -1)\n";
  shapes2.move({ 4, -1 });
  printCompisiteShapeInfo(shapes2);
  std::cout << "\nMove the comp. shape to dx = -1, dy = -2\n";
  shapes2.move(-1, -2);
  printCompisiteShapeInfo(shapes2);
  std::cout << "\nScale the comp. shape by factor = 3\n";
  shapes2.scale(3);
  printCompisiteShapeInfo(shapes2);
  std::cout << "\nDelete shape by index 1\n";
  shapes2.deleteShape(1);
  printCompisiteShapeInfo(shapes2);
  for (size_t i = 0; i < shapes2.getSize(); i++)
  {
    std::cout << "\nChange the shape by index " << i << ".\n";
    printShapeInfo(shapes2[i]);
    std::cout << "Move the shape to point (4, -1)\n";
    shapes2[i]->move({ 4, -1 });
    std::cout << "Move the shape to dx = -1, dy = -2\n";
    shapes2[i]->move(-1, -2);
    std::cout << "Scale the shape by factor = 3\n";
    shapes2[i]->scale(3);
    printShapeInfo(shapes2[i]);
  }
  std::cout << "\nComposite Shape after changing shapes: \n";
  printCompisiteShapeInfo(shapes2);
  return 0;
}

void printCompisiteShapeInfo(const talipova::CompositeShape& shapes)
{
  std::cout << "Info: \n";
  std::cout << "Size of the Composite shape = " << shapes.getSize() << '\n';
  std::cout << "Frame rectangle's width = " << shapes.getFrameRect().width << '\n';
  std::cout << "Frame rectangle's height = " << shapes.getFrameRect().height << '\n';
  std::cout << "Frame rectangle's position = (" << shapes.getFrameRect().pos.x << "; " << shapes.getFrameRect().pos.y << ")\n";
  std::cout << "Area = " << shapes.getArea() << '\n';
}

void printShapeInfo(const std::shared_ptr<talipova::Shape>& shape)
{
  std::cout << "Info: \n";
  std::cout << "Frame rectangle's width = " << shape->getFrameRect().width << '\n';
  std::cout << "Frame rectangle's height = " << shape->getFrameRect().height << '\n';
  std::cout << "Frame rectangle's position = (" << shape->getFrameRect().pos.x << "; " << shape->getFrameRect().pos.y << ")\n";
  std::cout << "Area = " << shape->getArea() << '\n';
}
