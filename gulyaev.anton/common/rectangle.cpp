#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"

namespace gulyaev
{
  Rectangle::Rectangle(double width, double height, double x, double y) :
    Rectangle(width, height, {x, y})
  {}
  
  Rectangle::Rectangle(double width, double height, const point_t &center)
  {
    if (width <= 0.0)
    {
      throw std::invalid_argument("Oops. Width can't be <= 0.0");
    }
    if (height <= 0.0)
    {
      throw std::invalid_argument("Oops. Height can't be <= 0.0");
    }
    top_[0] = {center.x - width / 2, center.y + height / 2};
    top_[1] = {center.x + width / 2, center.y + height / 2};
    top_[2] = {center.x + width / 2, center.y - height / 2};
    top_[3] = {center.x - width / 2, center.y - height / 2};
  }
  
  double Rectangle::getArea() const noexcept
  {
    return getWidth() * getHeight();
  }
  
  rectangle_t Rectangle::getFrameRect() const
  {
    double leftSideRect = top_[0].x;
    double topSideRect = top_[0].y;
    double rightSideRect = top_[0].x;
    double bottomSideRect = top_[0].y;
    
    for (int i = 1; i < 4; ++i)
    {
      leftSideRect = (top_[i].x < leftSideRect) ? top_[i].x : leftSideRect;
      topSideRect = (top_[i].y > topSideRect) ? top_[i].y : topSideRect;
      rightSideRect = (top_[i].x > rightSideRect) ? top_[i].x : rightSideRect;
      bottomSideRect = (top_[i].y < bottomSideRect) ? top_[i].y : bottomSideRect;
    }
    return {rightSideRect - leftSideRect, topSideRect - bottomSideRect, {(rightSideRect + leftSideRect) / 2,
(topSideRect + bottomSideRect) / 2}};
  }
  
  void Rectangle::move(const point_t &point) noexcept
  {
    point_t center = getCenter();
    move(point.x - center.x, point.y - center.y);
  }
  
  void Rectangle::move(double deltaX, double deltaY) noexcept
  {
    for (point_t &i : top_)
    {
      i.x += deltaX;
      i.y += deltaY;
    }
  }
  
  void Rectangle::scale(const double coefficient)
  {
    if (coefficient <= 0.0)
    {
      throw std::invalid_argument("Oops. Height can't be <= 0.0");
    }
    if (coefficient == 1)
    {
      return;
    }
    point_t center = getCenter();
    for (point_t &i : top_)
    {
      i = {center.y + (i.x - center.x) * coefficient, center.x + (i.y - center.y) * coefficient};
    }
  }
  
  double Rectangle::getHeight() const noexcept
  {
    return (std::sqrt(std::pow((top_[0].y - top_[3].y), 2.) + std::pow((top_[0].x - top_[3].x), 2.)));
  }
  
  double Rectangle::getWidth() const noexcept
  {
    return (std::sqrt(std::pow((top_[0].y - top_[1].y), 2.) + std::pow((top_[0].x - top_[1].x), 2.)));
  }
  
  point_t Rectangle::getCenter() const noexcept
  {
    return getFrameRect().pos;
  }
}
