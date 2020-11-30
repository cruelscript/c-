#ifndef B7_SHAPES_HPP
#define B7_SHAPES_HPP

#include <iostream>
#include <memory>

struct Point
{
  int x;
  int y;
};

class Shape
{
public:
  explicit Shape(const Point&);
  virtual ~Shape() = default;

  bool isMoreLeft(Shape&) const;
  bool isUpper(Shape&) const;

  virtual void draw(std::ostream&) const = 0;

protected:
  Point center_;
};

std::istream& operator >>(std::istream&, Point&);
std::istream& operator >>(std::istream&, std::shared_ptr<Shape>&);
std::ostream& operator <<(std::ostream&, const std::shared_ptr<Shape>&);

typedef std::shared_ptr<Shape> shapePtr;

class Circle: public Shape
{
public:
  explicit Circle(const Point&);
  void draw(std::ostream&) const override;
};

class Triangle: public Shape
{
public:
  void draw(std::ostream&) const override;
  explicit Triangle(const Point&);
};

class Square: public Shape
{
public:
  explicit Square(const Point&);
  void draw(std::ostream&) const override;
};

#endif //B7_SHAPES_HPP
