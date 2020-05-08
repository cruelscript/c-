#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"


void printInfoAboutFrameRect(const std::shared_ptr<kubov::Shape> &figure)
{
  if(figure == nullptr)
  {
    throw std::invalid_argument("In function was passed nullptr");
  }

  std::cout << "\nFrame rectangle\n";
  std::cout << "Height = " << figure->getFrameRect().height << "\nWidth = " << figure->getFrameRect().width << "\n";
  std::cout << "Center: " << "(" << figure->getFrameRect().pos.x << ", "
            << figure->getFrameRect().pos.y << ")\n\n";
}

int main()
{
  kubov::point_t center = {1.1, 1.5};

  std::shared_ptr<kubov::Shape> figureCircle01 = std::make_shared<kubov::Circle>(kubov::Circle(center, 1.0));

  figureCircle01->print(std::cout);

  std::cout << "\nArea = " << figureCircle01->getArea() << "\n";
  printInfoAboutFrameRect(figureCircle01);

  std::cout << "Move circle to (3.0, 4.0)" << "\n\n";
  kubov::point_t positionNew = {3.0, 4.0};
  figureCircle01->move(positionNew);

  figureCircle01->print(std::cout);
  printInfoAboutFrameRect(figureCircle01);

  std::cout << "Circle area before using method scale: " << figureCircle01->getArea() << "\n";
  figureCircle01->scale(2.0);
  std::cout << "Circle area after using method scale with coefficient 2.0: " << figureCircle01->getArea() << "\n\n";


  std::shared_ptr<kubov::Shape> figureRectangle01 =
    std::make_shared<kubov::Rectangle>(kubov::Rectangle(center, 3.0, 4.0));

  figureRectangle01->print(std::cout);

  std::cout << "Area = " << figureRectangle01->getArea() << "\n";
  printInfoAboutFrameRect(figureRectangle01);

  std::cout << "Move rectangle on x: +5.1, y: -2.3\n" << "\n";
  figureRectangle01->move(5.1, -2.3);

  figureRectangle01->print(std::cout);
  printInfoAboutFrameRect(figureRectangle01);

  std::cout << "Rectangle area before using method scale is " << figureRectangle01->getArea() << "\n";
  figureRectangle01->scale(2.0);

  std::cout << "Rectangle area after using method scale with coefficient 2.0 is : "
            << figureRectangle01->getArea() << "\n\n";

  std::shared_ptr<kubov::Shape> figureRectangle02 =
    std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 1.0, 2.0));

  std::shared_ptr<kubov::Shape> figureRectangle03 =
    std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 2.0, 3.0));

  std::shared_ptr<kubov::Shape> figureCircle02 =
    std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 1.0));

  kubov::CompositeShape compositeShape(figureRectangle02);
  compositeShape.addElement(figureRectangle03);
  compositeShape.addElement(figureCircle02);

  std::cout << "Print information about current compositeShape" << "\n";
  std::cout << "Size of compositeShape is: " << compositeShape.getSize() << "\n";
  compositeShape.print(std::cout);

  compositeShape.deleteElement(0);
  std::cout << "Print information about current state of compositeShape" << "\n";
  std::cout << "Size of compositeShape is: " << compositeShape.getSize() << "\n";
  compositeShape.print(std::cout);

  kubov::CompositeShape compositeShape1(compositeShape);
  std::cout << "Print information about current state of compositeShape1" << "\n";
  compositeShape1.print(std::cout);

  std::cout << "Print information about area in compositeShape" << "\n";
  std::cout << compositeShape.getArea() << "\n";

  std::cout << "Print information about frame rectangle of compositeShape" << "\n";
  printInfoAboutFrameRect(std::make_shared<kubov::CompositeShape>(compositeShape));

  compositeShape.move({5.0, 5.0});
  std::cout << "Print information about current state of compositeShape after move in point {5.0, 5.0}" << "\n";
  compositeShape.print(std::cout);

  compositeShape.move(1.0, 1.0);
  std::cout << "Print information about current state of compositeShape after move in deltaX 1.0 deltaY 1.0" << "\n";
  compositeShape.print(std::cout);

  compositeShape.scale(2.0);
  std::cout << "Print information about current state of compositeShape after scale with coefficient 2.0" << "\n";
  compositeShape.print(std::cout);

  std::cout << "Print information about current compositeShape" << "\n";
  std::cout << "Size of compositeShape is: " << compositeShape.getSize() << "\n";
  std::cout << "Area of compositeShape is: " << compositeShape.getArea() << "\n";

  return 0;
}
