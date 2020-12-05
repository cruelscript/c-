#include <iostream>
#include "data-parser.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if(argc == 1)
    {
      DataParser parser(std::cin, std::cout);
    }
    else if(argc == 3)
    {
      if(std::string(argv[1]) != "--line-width")
      {
        throw std::invalid_argument("Console Input: Error. Invalid argument. Use '--line-width'");
      }
      DataParser parser(std::cin, std::cout, std::stoi(argv[2]));
    }
    else throw std::invalid_argument("Console Input: Error. Invalid number of arguments");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
