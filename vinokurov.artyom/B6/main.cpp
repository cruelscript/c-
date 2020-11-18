#include <iostream>
#include <iterator>

#include "statistics.hpp"

int main()
{
  try
  {
    Statistics<long long> stats(std::for_each(std::istream_iterator<long long>(std::cin),
      std::istream_iterator<long long>(), Statistics<long long>()));

    if(!std::cin.eof() && std::cin.fail())
    {
      throw std::ios_base::failure("B6: Error. Failed to read data");
    }
    stats.print(std::cout);

    return 0;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return -1;
  }
}
