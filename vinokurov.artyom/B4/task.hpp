#ifndef B4_TASK_HPP
#define B4_TASK_HPP

#include <string>
#include <vector>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

const int MIN_KEY = -5;
const int MAX_KEY = 5;

void task(std::istream&, std::ostream&);

std::vector<DataStruct> getVector(std::istream&);
int getKey(std::istream&);
std::string getStr(std::istream&);

bool comparator(const DataStruct&, const DataStruct&);

#endif //B4_TASK_HPP
