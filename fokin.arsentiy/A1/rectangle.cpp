#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t& center) :
    rect_{ width, height, center }
{
    assert(width > 0 && "Error! Width must be a positive value. Exiting...\n");
    assert(height > 0 && "Error! Height must be a positive value. Exiting...\n");
}

double Rectangle::getArea() const
{
    return rect_.height * rect_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
    return rect_;
}

void Rectangle::move(const point_t& newPos)
{
    rect_.pos = newPos;
}

void Rectangle::move(const double dx, const double dy)
{
    rect_.pos.x += dx;
    rect_.pos.y += dy;
}