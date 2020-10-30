#include <algorithm>

#include "factorial.hpp"

void task2(std::ostream& out)
{
  std::copy(Factorial::begin(), Factorial::end(), std::ostream_iterator<size_t>(out, " "));
  out << "\n";
  std::reverse_copy(Factorial::begin(), Factorial::end(), std::ostream_iterator<size_t>(out, " "));
  out << "\n";
}
