#include <iostream>
#include <vector>

#include "utilities.hpp"

void task3(std::istream& in, std::ostream& out)
{
  std::vector<int> vector {};

  int num = 0;
  while(in >> num && !in.eof())
  {
    if(num == 0)
    {
      break;
    }
    vector.push_back(num);
  }

  if(in.fail() && !in.eof())
  {
    throw std::ios_base::failure("task3: Error. Failed to read data");
  }

  if(num != 0)
  {
    throw std::invalid_argument("task3: Error. Sequence did not end with zero.");
  }

  if(vector.empty())
  {
    return;
  }

  switch(vector.back())
  {
    case 1:
      for(auto i = vector.begin(); i != vector.end();)
      {
        i = (*i % 2 == 0) ? vector.erase(i) : ++i;
      }
      break;
    case 2:
      for(auto i = vector.begin(); i != vector.end();)
      {
        i = (*i % 3 == 0) ? vector.insert(++i, 3, 1) + 3 : ++i;
      }
      break;
  default:
    break;
  }
  print(out, vector);
}
