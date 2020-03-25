#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle(const double width, const double height, const point_t& pos);
	double getArea() const;
	rectangle_t getFrameRect() const;
	void print() const;
	void move(const double dx, const double dy);
	void move(const point_t& position);
private:
	double height_;
	double width_;
	point_t pos_;
};
#endif // !RECTANGLE_HPP_
