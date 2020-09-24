#include <iostream>

void task1(const char*, std::istream&, std::ostream&);
void task2(const char*, std::ostream&);
void task3(std::istream&, std::ostream&);
void task4(const char*, size_t, std::ostream&);

int main(int argc, char* argv[])
{
  try
  {
    if(argc < 2 || argc > 4)
    {
      throw std::invalid_argument("Console Input: Error. Invalid number of arguments.");
    }

    switch(std::stoi(argv[1]))
    {
      case 1:
        task1(argv[2], std::cin, std::cout);
        break;
      case 2:
        task2(argv[2], std::cout);
        break;
      case 3:
        task3(std::cin, std::cout);
        break;
      case 4:
        task4(argv[2], std::stoi(argv[3]), std::cout);
        break;
      default:
        throw std::invalid_argument("Console Input: Error. Invalid task number.");
    }
  }
  catch(std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
