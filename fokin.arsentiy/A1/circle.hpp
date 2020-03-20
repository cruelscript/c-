#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
    Circle(const point_t& center, const double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getCenter() const;
    double getRadius() const;
    void move(const point_t& newCenter) override;
    void move(const double dx, const double dy) override;
private:
    point_t center_;
    double radius_;
};

#endif