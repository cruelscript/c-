#include <iostream>
#include <sstream>

#include "priority-queue.hpp"

void task1(std::istream& in, std::ostream& out)
{
  PriorityQueue<std::string> queue;
  typedef PriorityQueue<std::string>::Priority Priority;

  std::string input;

  while(std::getline(in, input))
  {
    if(in.fail() && !in.eof())
    {
      throw std::ios_base::failure("task1: Error. Failed to read data");
    }

    std::stringstream sin(input);

    std::string command;
    sin >> command;
    if(command.empty())
    {
      continue;
    }

    if(command == "add")
    {
      std::string priority;
      std::string data;

      sin >> priority;
      sin >> data;

      if(!sin.eof())
      {
        std::string temp;
        while(std::getline(sin, temp))
        {
          data += temp;
        }
      }

      if(data.empty())
      {
        out << "<INVALID COMMAND>\n";
        continue;
      }

      if(priority == "high")
      {
        queue.enqueue(data, Priority::HIGH);
      }
      else if(priority == "normal")
      {
        queue.enqueue(data, Priority::NORMAL);
      }
      else if(priority == "low")
      {
        queue.enqueue(data, Priority::LOW);
      }
      else
      {
        out << "<INVALID COMMAND>\n";
      }
    }

    else if(command == "get")
    {
      if(queue.isEmpty())
      {
        out << "<EMPTY>\n";
        continue;
      }
      out << queue.dequeue() << "\n";
    }

    else if(command == "accelerate")
    {
      queue.accelerate();
    }

    else
    {
      out << "<INVALID COMMAND>\n";
    }
  }
}
