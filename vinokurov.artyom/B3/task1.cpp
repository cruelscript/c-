#include <string>
#include <sstream>
#include <functional>
#include <iostream>
#include <algorithm>

#include "phone-book.hpp"

typedef std::function<void(PhoneBook&)> Command;

std::string getCorrectNumber(std::istream& in);
std::string getCorrectName(std::istream& in);
std::string getCorrectBookmark(std::istream& in);

Command execute(const std::string& input)
{
  std::stringstream sin(input);

  std::string command;
  sin >> command;

  if (command == "add")
  {
    std::string number = getCorrectNumber(sin);
    std::string name = getCorrectName(sin);

    return [number, name](PhoneBook& book)
    {
      book.add({number, name});
    };
  }
  if (command == "store")
  {
    std::string markName = getCorrectBookmark(sin);
    std::string newMarkName = getCorrectBookmark(sin);

    return [markName, newMarkName](PhoneBook& book)
    {
      book.store(markName, newMarkName);
    };
  }
  if (command == "insert")
  {
    std::string position;
    sin >> position;

    std::string markName = getCorrectBookmark(sin);
    std::string number = getCorrectNumber(sin);
    std::string name = getCorrectName(sin);

    return [position, markName, number, name](PhoneBook& book)
    {
      book.insert(position, markName, {number, name});
    };
  }
  if (command == "delete")
  {
    std::string markName = getCorrectBookmark(sin);

    return [markName](PhoneBook& book)
    {
      book.remove(markName);
    };
  }
  if (command == "show")
  {
    std::string markName = getCorrectBookmark(sin);

    return [markName](PhoneBook& book)
    {
      book.show(markName, std::cout);
    };
  }
  if (command == "move")
  {
    std::string markName = getCorrectBookmark(sin);
    std::string steps;
    sin >> steps;

    return [markName, steps](PhoneBook& book)
    {
      book.move(markName, steps);
    };
  }
  throw std::invalid_argument("<INVALID COMMAND>");
}

void task1(std::istream& in, std::ostream& out)
{
  PhoneBook book;
  std::string input;

  while (std::getline(in, input))
  {
    try
    {
      Command command = execute(input);
      command(book);
    }
    catch (std::invalid_argument& e)
    {
      out << e.what() << "\n";
    }
    catch (std::exception& e)
    {
      std::cerr << e.what() << "\n";
    }
  }
}

std::string getCorrectNumber(std::istream& in)
{
  std::string number;
  in >> number;

  for (auto i : number)
  {
    if (!isdigit(i))
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return number;
}

std::string getCorrectName(std::istream& in)
{
  std::string name;
  std::getline(in >> std::ws, name);

  if (name.empty())
  {
    return name;
  }
  if ((name.front() != '\"') || (name.back() != '\"'))
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }

  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  name.erase(name.begin());
  name.pop_back();

  return name;
}

std::string getCorrectBookmark(std::istream& in)
{
  std::string markName;
  in >> markName;

  for (auto i : markName)
  {
    if (!isalnum(i) && i != '-')
    {
      throw std::invalid_argument("getCorrectBookmark: Error. Invalid bookmark name.");
    }
  }
  return markName;
}
