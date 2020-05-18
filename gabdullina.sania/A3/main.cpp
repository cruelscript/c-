#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

int main()
{
  gabdullina::Circle circle1(gabdullina::point_t{2.4, -1}, 3);
  gabdullina::Circle circle2(1.6, 3, 2.5);
  gabdullina::Rectangle rectangle1(gabdullina::point_t{1.5, 2}, 3.1, 5.7);
  gabdullina::Rectangle rectangle2(4, 2.9, 5.6, 9.1);

  gabdullina::Shape* figures[] = {&circle1, &circle2, &rectangle1, &rectangle2};

  for (int i = 0; i < 4; i++)
  {
    std::cout << "Area of figure number " << i + 1 << " is "
      << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of figure number " << i + 1 <<" is ("
      << figures[i]->getFrameRect().pos.x << "; "
      << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Frame Rectangle size of figure number " << i + 1 << " is "
      << figures[i]->getFrameRect().width << "x"
      << figures[i]->getFrameRect().height << "\n\n";
  }

  for (int i = 0; i < 4; i++)
  {
    std::cout << "The position of figure number " << i + 1 << " is ("
      << figures[i]->getPos().x << "; "
      << figures[i]->getPos().y << ")\n";
    std::cout << "Moving figure to a point with coordinates (2;3)" << "\n";
    figures[i]->move({2, 3});
    std::cout << "Now the position of figure is ("
      << figures[i]->getPos().x << "; "
      << figures[i]->getPos().y << ")\n";
    i++;
    
    figures[i]->showParameters(std::cout);
    std::cout << "Scaling figure number " << i + 1 << " with a coefficient 1.4";
    figures[i]->scale(1.4);
    figures[i]->showParameters(std::cout);

    std::cout << "\nThe position of figure number " << i + 1 << " is ("
      << figures[i]->getPos().x << "; "
      << figures[i]->getPos().y << ")\n";
    std::cout << "Moving the sides of figure by 4 in width and -1 in height" << "\n";
    figures[i]->move(4, -1);
    std::cout << "Now the position of figure is ("
      << figures[i]->getPos().x << "; "
      << figures[i]->getPos().y << ")\n\n";
  }

  gabdullina::CompositeShape::shape_ptr partOfCompositeShape1 = std::make_shared<gabdullina::Rectangle>(1, 2, 5, 5);
  gabdullina::CompositeShape::shape_ptr partOfCompositeShape2 = std::make_shared<gabdullina::Circle>(3, 4, 7);
  gabdullina::CompositeShape::shape_ptr partOfCompositeShape3 = std::make_shared<gabdullina::Rectangle>(-1, -2, 9, 7);

  gabdullina::CompositeShape compositeShape;
  compositeShape.add(partOfCompositeShape1);
  compositeShape.add(partOfCompositeShape2);
  compositeShape.add(partOfCompositeShape3);

  compositeShape.showParameters(std::cout);
  std::cout << "\nScaling the composite shape with a coefficient 0.3";
  compositeShape.scale(0.3);
  compositeShape.showParameters(std::cout);

  std::cout << "\nThe position of the composite shape is ("
    << compositeShape.getPos().x << "; "
    << compositeShape.getPos().y << ")";
  std::cout << "\nMoving the composite shape to a point (3;2)";
  compositeShape.move({3, 2,});
  std::cout << "\nNow the position of the composite shape is ("
    << compositeShape.getPos().x << "; "
    << compositeShape.getPos().y << ")\n";
  std::cout << "\nMoving the composite shape -5.6 along axis x and +3.2 along axis y";
  compositeShape.move(-5.6, 3.2);
  std::cout << "\nNow the position of the composite shape is ("
    << compositeShape.getPos().x << "; "
    << compositeShape.getPos().y << ")\n";

  std::cout << "\nDeleting a part of composite shape\n";
  compositeShape.remove();
  compositeShape.showParameters(std::cout);

  return 0;
}
