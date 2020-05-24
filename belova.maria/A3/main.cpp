#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

int main()
{
  belova::Rectangle rect({ 4, 4 }, 5, 2);
  belova::Circle circ({ 5.25, 6.26 }, 28.0);

  belova::Shape* shapes[2] = { &rect, &circ };
  for (belova::Shape* shape : shapes)
  {
    std::cout << "Shape data\n";
    shape->showData(std::cout);
    std::cout << "\n";
    std::cout << "Moving shape to a specific point\n";
    shape->move({ 17.962, 63.7 });
    shape->showData(std::cout);
    std::cout << "Moving shape along the abscissas and ordinates\n";
    shape->move(-55.32, 9.4);
    shape->showData(std::cout);
    std::cout << "\n";
    std::cout << "Calculating the bounding box data of the shape\n";
    std::cout << "Width: " << shape->getFrameRect().width << "\tHeight: " << shape->getFrameRect().height
      << "\tPosition: (" << shape->getFrameRect().pos.x << ", " << shape->getFrameRect().pos.y << ")\n";
    std::cout << "Calculating the area of the shape\n";
    std::cout << "Area: " << shape->getArea() << "\n";
    shape->scale(2.5);
    std::cout << "After scaling by 2.5\n";
    shape->showData(std::cout);
    std::cout << "Area: " << shape->getArea() << "\n";
    std::cout << "\n";
  }

  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(6.7, 2.3, 3.2, 5.2);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Circle>(0.0, 1.3, 10.3);
  std::shared_ptr<belova::Shape> third = std::make_shared<belova::Rectangle>(1.3, 0.0, 9.1, 9.1);
  std::shared_ptr<belova::Shape> toDelete = std::make_shared<belova::Circle>(30.0, 20.3, 30.3);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second, 1);
  compositeShape.addShape(third, 0);
  compositeShape.addShape(toDelete);
  compositeShape.showData(std::cout);

  std::cout << "\nAfter deleting the first circle\n";
  compositeShape.deleteShape();
  compositeShape.showData(std::cout);

  std::cout << "\nMoving composite shape to a specific point\n";
  compositeShape.move({ 5.0, -4.0 });
  compositeShape.showData(std::cout);
  std::cout << "\nMoving composite shape along the abscissas and ordinates\n";
  compositeShape.move(9.3, 9.3);
  compositeShape.showData(std::cout);
  std::cout << "\nCalculating the bounding box data of the composite shape\n";
  std::cout << "Width: " << compositeShape.getFrameRect().width << "\tHeight: " << compositeShape.getFrameRect().height
    << "\tPosition: (" << compositeShape.getFrameRect().pos.x << ", " << compositeShape.getFrameRect().pos.y << ")\n";
  std::cout << "\nCalculating the area of the composite shape\n";
  std::cout << "Area: " << compositeShape.getArea() << "\n";
  compositeShape.scale(2.0);
  std::cout << "\nAfter scaling by 2.0\n";
  compositeShape.showData(std::cout);
  std::cout << "Area: " << compositeShape.getArea() << "\n";
  std::cout << "\nAfter deleting shape with index 1\n";
  compositeShape.deleteShape(1);
  compositeShape.showData(std::cout);

  return 0;
}
