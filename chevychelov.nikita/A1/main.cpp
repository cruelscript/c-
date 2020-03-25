#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
	point_t mid = {0.0, 0.0};
	Rectangle rect(10.10, 12.12, mid);
	std::cout << "Your rectangle: ";
	rect.print();
	std::cout << " Area of rectangle: " << rect.getArea();
	std::cout << " \n Frame rectangle: " << " Width: " << rect.getFrameRect().width
		<< " Height: " << rect.getFrameRect().height << " X: " << rect.getFrameRect().pos.x
		<< " Y: " << rect.getFrameRect().pos.y;
	rect.move(11.3, 7.0);
	std::cout << " \nYour rectangle after move: ";
	rect.print();
	Circle circle(5.12, mid);
	std::cout << "Your circle: ";
	circle.print();
	std::cout << " Area of circle: " << circle.getArea();
	std::cout << " \n Frame rectangle: " << " Width: " << circle.getFrameRect().width
		<< " Height: " << circle.getFrameRect().height << " X: " << circle.getFrameRect().pos.x
		<< " Y: " << circle.getFrameRect().pos.y;
	circle.move(11.3, 7.0);
	std::cout << " \nYour circle after move: ";
	circle.print();
	return 0;
};
