#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

int main()
{
  gulyaev::Rectangle rectangle(20., 10., 5., 5.);
  gulyaev::Circle circle(5., 35., 30.);
  
  std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 35, 30);
  std::shared_ptr<gulyaev::Shape> circle3 = std::make_shared<gulyaev::Circle>(5, 350, 300);
  std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(20, 10, 5, 5);
  gulyaev::CompositeShape compositeShape(circle3);
  compositeShape.remove();
  compositeShape.add(circle2);
  compositeShape.add(rectangle2);
  
  const int AMOUNT_OF_FIGURES = 3;
  gulyaev::Shape *figures[AMOUNT_OF_FIGURES] = {&rectangle, &circle, &compositeShape};
  
  for (int i = 0; i < AMOUNT_OF_FIGURES; ++i)
  {
    const char *myShapeType = nullptr;
    switch (i)
    {
      case 0:
        myShapeType = "rectangle";
        break;
      case 1:
        myShapeType = "circle";
        break;
      default:
        myShapeType = "composite shape";
    }
    std::cout << "Now with " << myShapeType << "\n\n";
    std::cout << "Area of " << myShapeType << " " << figures[i]->getArea() << "\n";
    
    std::cout << "Scale the figure 5 times\n";
    
    figures[i]->scale(5);
    
    std::cout << "Area of " << myShapeType << " " << figures[i]->getArea() << "\n";
    
    std::cout << "First position of " << myShapeType << " (" << figures[i]->getFrameRect().pos.x << "; "
      << figures[i]->getFrameRect().pos.y << ") \n";
    
    figures[i]->move({2., 2.});
    std::cout << "Move " << myShapeType << " to position (2; 2)\n";
    
    std::cout << "Second position of " << myShapeType << " (" << figures[i]->getFrameRect().pos.x << "; "
      << figures[i]->getFrameRect().pos.y << ") \n";
    
    figures[i]->move(2., 2.);
    std::cout << "Move " << myShapeType << " by x: 2 and y: 2\n";
    
    std::cout << "Third position of " << myShapeType << " (" << figures[i]->getFrameRect().pos.x << "; "
      << figures[i]->getFrameRect().pos.y << ") \n";
    
    std::cout << "Get frame rectangle: \nWidth: " << myShapeType << " " << figures[i]->getFrameRect().width
      << ", height: " << figures[i]->getFrameRect().height << " square: "
      << figures[i]->getFrameRect().width * figures[i]->getFrameRect().height << ", position of x: "
      << figures[i]->getFrameRect().pos.x << ", position of y: " << figures[i]->getFrameRect().pos.y << "\n\n\n";
    
  }
  return 0;
}
