#ifndef B5_SHAPE_HPP
#define B5_SHAPE_HPP

#include <vector>
#include <iostream>

struct Point
{
  int x;
  int y;
};

using Shape = std::vector<Point>;

enum vertexNum
{
  TRIANGLE = 3,
  RECTANGLE = 4,
  PENTAGON = 5
};

bool isTriangle(const Shape& shape);
bool isRectangle(const Shape& shape);
bool isSquare(const Shape& shape);

int countVertices(const std::vector<Shape>&);
int countTriangles(const std::vector<Shape>&);
int countRectangles(const std::vector<Shape>&);
int countSquares(const std::vector<Shape>&);

std::istream& operator >>(std::istream&, Point&);
std::istream& operator >>(std::istream&, Shape&);
std::ostream& operator <<(std::ostream&, const Point&);
std::ostream& operator <<(std::ostream&, const Shape&);

#endif //B5_SHAPE_HPP
