#ifndef B1_UTILITIES_HPP
#define B1_UTILITIES_HPP

#include <functional>
#include <cstring>
#include <iostream>

template <typename T>
std::function<bool(const T&, const T&)> getComparator(const char* order)
{
  if(std::strcmp(order, "ascending") == 0)
  {
    return std::greater<T>();
  }
  if(std::strcmp(order, "descending") == 0)
  {
    return std::less<T>();
  }
  throw std::invalid_argument("getComparator: Error. Invalid sorting order.");
}

template <typename Container>
void print(std::ostream& out, const Container& container, const char* delim = " ", const char* lineDelim = "\n")
{
  for(const auto& element: container)
  {
    out << element << delim;
  }
  out << lineDelim;
}

#endif //B1_UTILITIES_HPP
