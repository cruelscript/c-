#include <iterator>
#include <algorithm>

#include "shape.hpp"

void task2(std::istream& in, std::ostream& out)
{
  std::vector<Shape> shapes((std::istream_iterator<Shape>(in)), std::istream_iterator<Shape>());

  if(!in.eof() && in.fail())
  {
    throw std::ios_base::failure("task2: Error. Failed to read data");
  }

  out << "Vertices: " << countVertices(shapes);
  out << "\nTriangles: " << countTriangles(shapes);
  out << "\nSquares: " << countSquares(shapes);
  out << "\nRectangle: " << countRectangles(shapes);

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
                              [] (const Shape& shape)
                              {
                                return shape.size() ==  vertexNum::PENTAGON;
                              }),
               shapes.end());

  std::vector<Point> points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points),
                 [] (const Shape& shape)
                 {
                    return shape.front();
                 });

  out << "\nPoints: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(out, " "));

  auto triangles = std::partition(shapes.begin(), shapes.end(), isTriangle);
  auto squares = std::partition(triangles, shapes.end(), isSquare);
  std::partition(squares, shapes.end(), isRectangle);

  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>(out, "\n"));

};
