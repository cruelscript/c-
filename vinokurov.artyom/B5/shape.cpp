#include <iterator>
#include <sstream>
#include <cmath>
#include <numeric>
#include <algorithm>

#include "shape.hpp"

double getDistance(const Point& lhs, const Point& rhs)
{
  return std::sqrt(std::pow((rhs.x - lhs.x), 2) + std::pow((rhs.y - lhs.y), 2));
}

bool isTriangle(const Shape& shape)
{
  return shape.size() == vertexNum::TRIANGLE &&
  (shape[2].x - shape[0].x) * (shape[1].y - shape[0].y) != (shape[1].x - shape[0].x) * (shape[2].y - shape[0].y);
}

bool isRectangle(const Shape& shape)
{
  return shape.size() == vertexNum::RECTANGLE &&
    getDistance(shape[1], shape[2]) == getDistance(shape[0], shape[3]) &&
    getDistance(shape[0], shape[1]) == getDistance(shape[2], shape[3]) &&
    getDistance(shape[0], shape[2]) == getDistance(shape[1], shape[3]);
}

bool isSquare(const Shape& shape)
{
  return isRectangle(shape) &&
    getDistance(shape[0], shape[1]) == getDistance(shape[1], shape[2]);
}

int countVertices(const std::vector<Shape>& vector)
{
  return std::accumulate(vector.begin(), vector.end(), 0,
                         [] (int vertexNum, const Shape& shape)
                         {
                            return vertexNum + shape.size();
                         });
}

int countTriangles(const std::vector<Shape>& vector)
{
  return std::count_if(vector.begin(), vector.end(), isTriangle);
}

int countRectangles(const std::vector<Shape>& vector)
{
  return std::count_if(vector.begin(), vector.end(), isRectangle);
}

int countSquares(const std::vector<Shape>& vector)
{
  return std::count_if(vector.begin(), vector.end(), isSquare);
}

std::istream& operator>>(std::istream& in, Point& point)
{
  char leftP;
  char rightP;
  char semicolon;

  in >> std::ws;
  if(!in)
  {
    return in;
  }

  in >> leftP >> point.x >> semicolon >> point.y >> rightP;

  if(leftP != '(' || rightP != ')' || semicolon != ';')
  {
    in.setstate(std::ios::failbit);
  }

  return in;
}

std::istream& operator>>(std::istream& in, Shape& shape)
{
  size_t size = 0;
  in >> size;

  if(!in)
  {
    return in;
  }

  if(size < vertexNum::TRIANGLE)
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  std::string input;
  std::getline(in >> std::ws, input);
  std::stringstream sin(input);

  Shape temp;
  temp.reserve(size);

  std::copy(std::istream_iterator<Point>(sin), std::istream_iterator<Point>(), std::back_inserter(temp));

  if(!sin.eof() || temp.size() != size || !sin)
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  shape.swap(temp);

  return in;
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
  return out << '(' << point.x << ';' << point.y << ')';
}

std::ostream& operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));

  return out;
}
