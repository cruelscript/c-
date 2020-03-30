#include "circle.hpp"

//#define _USE_MATH_DEFINES
//#include <cmath>

#define M_PI       3.14159265358979323846

#include <cassert>
#include <ostream>

Circle::Circle(const point_t& position, double radius) :
	Shape(position),
	radius_(radius)
{
	assert(radius > 0.0);
}

Circle::Circle(const double x, const double y, double radius) :
	Circle({ x,y }, radius)
{
}

double Circle::getRadius() const
{
	return radius_;
}

void Circle::setRadius(double radius)
{
	radius_ = radius;
}

double Circle::getArea() const
{
	return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
	return { radius_ * 2.0, radius_ * 2.0, pos_ };
}
