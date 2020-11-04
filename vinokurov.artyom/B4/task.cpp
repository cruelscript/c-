#include <algorithm>
#include <iostream>
#include <sstream>

#include "task.hpp"

void task(std::istream& in, std::ostream& out)
{
  std::vector<DataStruct> vector = getVector(in);
  std::sort(vector.begin(), vector.end(), comparator);

  for(auto& i: vector)
  {
    out << i.key1 << ", " << i.key2 << ", " << i.str << "\n";
  }
}

std::vector<DataStruct> getVector(std::istream& in)
{
  std::vector<DataStruct> vector;

  std::string input;
  while(std::getline(in, input))
  {
    std::stringstream sin(input);

    int key1 = getKey(sin);
    int key2 = getKey(sin);

    std::string str = getStr(sin);

    vector.push_back({key1, key2, str});
  }

  if(in.fail() && !in.eof())
  {
    throw std::ios_base::failure("B4: Error. Failed to read data");
  }

  return vector;
}

int getKey(std::istream& in)
{
  int key = MIN_KEY - 1;
  in >> key;

  if(in.get() != ',')
  {
    throw std::invalid_argument("B4: Error. Invalid input format.");
  }
  if(key < MIN_KEY || key > MAX_KEY)
  {
    throw std::invalid_argument("B4: Error. Invalid key.");
  }
  return key;
}

std::string getStr(std::istream& in)
{
  std::string str;
  std::getline(in >> std::ws, str);

  if(str.empty())
  {
    throw std::invalid_argument("B4: Error. Invalid string.");
  }
  return str;
}

bool comparator(const DataStruct& lhs, const DataStruct& rhs)
{
  if(lhs.key1 != rhs.key1)
  {
    return lhs.key1 < rhs.key1;
  }
  if(lhs.key2 != rhs.key2)
  {
    return lhs.key2 < rhs.key2;
  }
  return lhs.str.size() < rhs.str.size();
}
