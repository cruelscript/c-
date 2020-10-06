#include <iostream>

void task1(std::istream&, std::ostream&);
void task2(std::istream&, std::ostream&);

int main(int argc, char* argv[])
{
  try
  {
    if(argc != 2)
    {
      throw std::invalid_argument("Console Input: Error. Invalid number of arguments.");
    }

    switch(std::stoi(argv[1]))
    {
      case 1:
        task1(std::cin, std::cout);
        break;

      case 2:
        task2(std::cin, std::cout);
        break;

      default:
        throw std::invalid_argument("Console Input: Error. Invalid task number.");
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}
