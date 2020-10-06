#include <iostream>
#include <list>

const int MAX_NUM = 20;
const int MIN_NUM = 1;

void task2(std::istream& in, std::ostream& out)
{
  std::list<int> list;

  int i = 0;
  int counter = 0;
  while(in >> i && counter != MAX_NUM)
  {
    if(i < MIN_NUM || i > MAX_NUM)
    {
      throw std::invalid_argument("task2: Error. Invalid argument. Value must be in range of 1 to 20.");
    }
    list.push_back(i);
    ++counter;
  }

  if(in.fail() && !in.eof())
  {
    throw std::ios_base::failure("task2: Error. Failed to read data");
  }

  auto begin = list.begin();
  auto end = list.rbegin();

  auto center = list.begin();
  std::advance(center, list.size() / 2);

  while (begin != center)
  {
    out << *begin++ << ' ' << *end++ << ' ';
  }

  if (list.size() % 2 == 1)
  {
    out << *center;
  }
}
