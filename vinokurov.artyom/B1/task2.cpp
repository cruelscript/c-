#include <fstream>
#include <memory>
#include <vector>

#include "utilities.hpp"

typedef std::unique_ptr<char[], decltype(&free)> c_unique_ptr;

const size_t CHUNK_SIZE = 1024;

void task2(const char* filename, std::ostream& out)
{
  std::ifstream fin(filename);
  if(!fin.is_open())
  {
    throw std::ios_base::failure("task2: Error. Cannot open file");
  }

  c_unique_ptr data(static_cast<char*>(malloc(CHUNK_SIZE)), &free);
  if(!data)
  {
    throw std::runtime_error("task1: Error. Bad allocation.");
  }

  size_t currentSize = 0;
  size_t arraySize = CHUNK_SIZE;

  while(fin)
  {
    fin.read(data.get() + currentSize, CHUNK_SIZE);
    currentSize += fin.gcount();

    if(fin.gcount() == CHUNK_SIZE)
    {
      c_unique_ptr temp(static_cast<char*>(realloc(data.get(), arraySize * 2)), &free);
      if(!temp)
      {
        throw std::runtime_error("task2: Error. Bad reallocation.");
      }

      arraySize *= 2;
      data.release();
      std::swap(temp, data);
    }
  }
  if(!fin.eof())
  {
    throw std::ios_base::failure("task2: Error. Failed to read data.");
  }

  fin.close();
  if(fin.is_open())
  {
    throw std::ios_base::failure("task2: Error. Cannot close file.");
  }

  std::vector<char> outData(&data[0], &data[currentSize]);
  print(out, outData, "", "");
}
