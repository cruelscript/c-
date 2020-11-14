#include <iostream>
#include <set>
#include <iterator>

void task1(std::istream& in, std::ostream& out)
{
 std::set<std::string> wordSet((std::istream_iterator<std::string>(in)), std::istream_iterator<std::string>());

 if(in.fail() && !in.eof())
 {
   throw std::ios_base::failure("task1: Error. Failed to read data.");
 }

 std::copy(wordSet.begin(), wordSet.end(), std::ostream_iterator<std::string>(out, "\n"));
}
