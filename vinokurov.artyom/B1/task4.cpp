#include <vector>
#include <random>

#include "sort.hpp"
#include "access.hpp"
#include "utilities.hpp"

void fillRandom(double* array, int size)
{
  std::random_device seed;
  std::uniform_real_distribution<double> distribution(-1, 1);

  for(size_t i = 0; i < size; ++i)
  {
    array[i] = distribution(seed);
  }
}

void task4(const char* order, size_t size, std::ostream& out)
{
  if(size <= 0)
  {
    throw std::invalid_argument("task4: Error. Size must not be less than zero.");
  }

  auto comparator = getComparator<double>(order);

  std::vector<double> vector(size);

  fillRandom(&vector[0], size);

  print(out, vector);
  bubbleSort<OperatorAccess>(vector, comparator);
  print(out, vector);
}
