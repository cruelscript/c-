#include <iostream>

#include "task.hpp"

int main()
{
  try
  {
    task(std::cin, std::cout);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
