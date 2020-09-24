#include <vector>
#include <iostream>
#include <forward_list>

#include "utilities.hpp"
#include "sort.hpp"
#include "access.hpp"

void task1(const char* order, std::istream& in, std::ostream& out)
{
  auto comparator = getComparator<int>(order);

  std::vector<int> operatorVector {};

  int i = 0;
  while(in >> i && !in.eof())
  {
    operatorVector.push_back(i);
  }

  if(!in.eof() || !in.fail())
  {
    throw std::ios_base::failure("task1: Error. Failed to read data");
  }

  if(operatorVector.empty())
  {
    return;
  }

  std::vector<int> atVector(operatorVector);
  std::forward_list<int> list(operatorVector.begin(), operatorVector.end());

  bubbleSort<OperatorAccess>(operatorVector, comparator);
  bubbleSort<AtAccess>(atVector, comparator);
  bubbleSort<IteratorAccess>(list, comparator);

  print(out, operatorVector);
  print(out, atVector);
  print(out, list);
}
