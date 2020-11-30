#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>

void task1(std::istream& in, std::ostream& out)
{
  std::vector<double> sequence((std::istream_iterator<double>(in)), std::istream_iterator<double>());

  if(in.fail() && !in.eof())
  {
    throw std::ios_base::failure("task1: Error. Failed to read data.");
  }

  std::transform(sequence.begin(), sequence.end(), std::ostream_iterator<double>(out, " "),
                 [](double num)
                 {
                    return num * M_PI;
                 });
}
