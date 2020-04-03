#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

void printInfo(Shape & object)
{
	std::cout << /*"\nShape Information:*/"\n";
	object.print(std::cout);
	std::cout << "\n";
	object.outPoint(std::cout);
	std::cout << "\nShape's Area: " << object.getArea();
	std::cout << "\n\n";
	object.printFrame(std::cout, object.getFrameRect());
	std::cout << "\n\n\n";
}

int main()
{
	Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
	Circle circle(10.0, 10.0, 5.5);

	std::cout << "Rectangle Information:";
	printInfo(rectangle);
	std::cout << "Circle Information:";
	printInfo(circle);

	std::cout << "Move the center of the circle to (-2,-2)...\n";
	circle.move(-2.0, -2.0);
	std::cout << "Change the radius of the circle to 6...\n\nUpdated Information:";
	circle.setRadius(6.0);
	printInfo(circle);

	std::cout << "Move the center of the rectangle to (3,3)...\n";
	rectangle.move(3.0, 3.0);
	std::cout << "Change the height of the rectangle to 5, the width to 40...\n\nUpdated Information:";
	rectangle.setHeight(5.0);
	rectangle.setWidth(40.0);
	printInfo(rectangle);
}
