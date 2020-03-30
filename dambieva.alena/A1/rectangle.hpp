#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"

class Rectangle : public Shape
{
private:
	double width_;
	double height_;

public:
	Rectangle(const point_t& pos, double width, double height);
	Rectangle(const double x, const double y, const double width, const double height);
	double getWidth() const;
	double getHeight() const;
	void setWidth(double width);
	void setHeight(double height);
	rectangle_t getFrameRect() const override;
	double getArea() const override;
};

#endif