#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "shape.hpp"

class Circle : public Shape
{
public:
	Circle(const double radius, const point_t& pos);
	double getArea() const;
	rectangle_t getFrameRect() const;
	void print() const;
	void move(const double dx, const double dy);
	void move(const point_t& position);
private:
	double radius_;
	point_t pos_;
};
#endif // !CIRCLE_HPP_