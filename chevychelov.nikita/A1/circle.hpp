#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const double radius, const point_t& pos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print(std::ostream& out) const override;
  void move(const double dx, const double dy) override;
  void move(const point_t& position) override;
private:
  double radius_;
  point_t pos_;
};
#endif // !CIRCLE_HPP_
