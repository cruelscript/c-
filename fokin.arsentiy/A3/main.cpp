#include <iostream>
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

int main()
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 5.2, -7.5 }, 4.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape tempCompositeShape;
  tempCompositeShape.addShape(testCircle);
  tempCompositeShape.addShape(testRectangle);

  std::shared_ptr<fokin::Shape> testCompositeShape =
    std::make_shared<fokin::CompositeShape>(tempCompositeShape);

  const int NUMBER_OF_SHAPES = 3;
  std::unique_ptr<std::shared_ptr<fokin::Shape>[]> shape =
    std::make_unique<std::shared_ptr<fokin::Shape>[]>(NUMBER_OF_SHAPES);

  shape[0] = testRectangle;
  shape[1] = testCircle;
  shape[2] = testCompositeShape;

  for (unsigned int i = 0; i < NUMBER_OF_SHAPES; i++)
  {
    std::cout << "Area of " << i + 1 << " figure: " << shape[i]->getArea() << "\n";
    std::cout << "Center of " << i + 1 << " figure's frame rectangle: (" << shape[i]->getFrameRect().pos.x << ", "
      << shape[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Width and height of " << i + 1 << " figure's frame rectangle: " << shape[i]->getFrameRect().width
      << ", " << shape[i]->getFrameRect().height << "\n";

    shape[i]->move({ -5.1, 9.7 });
    shape[i]->move(5.1, -9.7);
    std::cout << "Center of " << i + 1 << " figure's frame rectangle after moving to (0, 0): ("
      << shape[i]->getFrameRect().pos.x << ", " << shape[i]->getFrameRect().pos.y << ")\n";

    shape[i]->scale(3);
    std::cout << "Width and height of " << i + 1 << " figure's frame rectangle after scaling by coefficient = 3: "
      << shape[i]->getFrameRect().width << ", " << shape[i]->getFrameRect().height << "\n";
    std::cout << "Area of " << i + 1 << " figure after scaling: " << shape[i]->getArea()
      << "\n--------------------------------------------\n";
  }

  return 0;
}
