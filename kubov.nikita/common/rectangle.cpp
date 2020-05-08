#include "rectangle.hpp"

#include <stdexcept>
#include <cmath>

#include "base-types.hpp"

kubov::Rectangle::Rectangle(const point_t &center, const double width, const double height)
{
  if (width <= 0.0) {
    throw std::invalid_argument("Error. Width can't be <= 0");
  }
  if (height <= 0.0) {
    throw std::invalid_argument("Error. Height can't be <= 0");
  }

  peaks_[0] = {center.x - width / 2, center.y - height / 2};
  peaks_[1] = {center.x + width / 2, center.y - height / 2};
  peaks_[2] = {center.x + width / 2, center.y + height / 2};
  peaks_[3] = {center.x - width / 2, center.y + height / 2};
}
 
double kubov::Rectangle::getArea() const noexcept
{
  return getHeight() * getWidth();
}

kubov::rectangle_t kubov::Rectangle::getFrameRect() const
{
  double coordinateTopRect = peaks_[0].y;
  double coordinateButtomRect = peaks_[0].y;
  double coordinateLeftSideRect = peaks_[0].x;
  double coordinateRightSideRect = peaks_[0].x;

  for (int i = 1; i < 4; ++i) {
    if (peaks_[i].x < coordinateLeftSideRect) {
      coordinateLeftSideRect = peaks_[i].x;
    }
    if (peaks_[i].x > coordinateRightSideRect) {
      coordinateRightSideRect = peaks_[i].x;
    }
    if (peaks_[i].y < coordinateButtomRect) {
      coordinateButtomRect = peaks_[i].y;
    }
    if (peaks_[i].y > coordinateTopRect) {
      coordinateTopRect = peaks_[i].y;
    }
  }

  return {coordinateRightSideRect - coordinateLeftSideRect, coordinateTopRect - coordinateButtomRect,
           {coordinateLeftSideRect + (coordinateRightSideRect - coordinateLeftSideRect) / 2,
             coordinateButtomRect + (coordinateTopRect - coordinateButtomRect) / 2}};
}

kubov::point_t kubov::Rectangle::getCenter() const noexcept
{
  return getFrameRect().pos;
}

double kubov::Rectangle::getHeight() const noexcept
{
  return std::sqrt(std::pow(peaks_[0].x - peaks_[3].x, 2.0) + std::pow(peaks_[3].y - peaks_[0].y, 2.0));
}

double kubov::Rectangle::getWidth() const noexcept
{
  return (std::sqrt(std::pow(peaks_[1].x - peaks_[0].x, 2.0) + std::pow(peaks_[1].y - peaks_[0].y, 2.0)));
}

void kubov::Rectangle::move(const point_t &positionNew) noexcept
{
  point_t center = getCenter();
  move(positionNew.x - center.x, positionNew.y - center.y);
}

void kubov::Rectangle::move(const double deltaX, const double deltaY) noexcept
{
  for (int i = 0; i < 4; ++i) {
    peaks_[i].x += deltaX;
    peaks_[i].y += deltaY;
  }
}

void kubov::Rectangle::print(std::ostream &out) const
{
  out << "This is rectangle\n";
  out << "Width: " << getWidth() << "\n";
  out << "Height: " << getHeight() << "\n";
  out << "Center: (" << getCenter().x << ", " << getCenter().y << ")\n";
}

void kubov::Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0.0) {
    throw std::invalid_argument("Invalid coefficient");
  }

  if (coefficient == 1.0) {
    return;
  }

  point_t center = getCenter();

  for (point_t &peak : peaks_) {
      peak = {center.x + (peak.x - center.x) * coefficient, center.y + (peak.y - center.y) * coefficient};
  }
}
