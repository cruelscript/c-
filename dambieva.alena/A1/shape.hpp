#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <iosfwd>

class Shape
{
public:
	virtual ~Shape() = default;
	Shape(const point_t & pos);

	virtual double getArea() const = 0;
	virtual rectangle_t getFrameRect() const = 0;
	virtual void move(const point_t & newPos);
	virtual void move(double deltaX, double deltaY);

	virtual void print(std::ostream & out) const = 0;
	void printFrame(std::ostream & out, rectangle_t rect) const;
	void outPoint(std::ostream & out) const;

protected:
	point_t pos_;
};

#endif
