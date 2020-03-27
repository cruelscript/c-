#ifndef SHAPE_HPP
#define SHAPE_HPP

#include  "base-types.hpp"

class  Shape
{
public:
	virtual ~Shape() = default;
	virtual double getArea() const = 0;
	virtual rectangle_t getFrameRect() const = 0;
	virtual void move(const double dx, const double dy) = 0;
	virtual void move(const point_t& point) = 0;
	virtual point_t getCentre() const = 0;
	virtual void show_frame(Shape *figure) const = 0;
	virtual void show_position(Shape* figure) const = 0;
};
#endif
