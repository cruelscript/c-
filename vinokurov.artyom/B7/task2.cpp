#include <vector>
#include <iterator>
#include <algorithm>

#include "shapes.hpp"

void task2(std::istream& in, std::ostream& out)
{
  std::vector<shapePtr> shapes((std::istream_iterator<shapePtr>(in)), std::istream_iterator<shapePtr>());

  if (!in.eof() && in.fail())
  {
    throw std::ios_base::failure("task2: Error. Failed to read data");
  }

  out << "Original:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<shapePtr>(out));

  out << "Left-Right:\n";
  std::sort(shapes.begin(), shapes.end(), [](shapePtr& lhs, shapePtr& rhs)
                                          {
                                            return lhs->isMoreLeft(*rhs);
                                          });
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<shapePtr>(out));

  out << "Right-Left:\n";
  std::copy(shapes.rbegin(), shapes.rend(), std::ostream_iterator<shapePtr>(out));

  out << "Top-Bottom:\n";
  std::sort(shapes.begin(), shapes.end(), [](shapePtr& lhs, shapePtr& rhs)
                                          {
                                            return lhs->isUpper(*rhs);
                                          });
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<shapePtr>(out));

  out << "Bottom-Top:\n";
  std::copy(shapes.rbegin(), shapes.rend(), std::ostream_iterator<shapePtr>(out));
}
