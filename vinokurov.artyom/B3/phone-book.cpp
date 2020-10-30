#include "phone-book.hpp"

#include <iostream>

PhoneBook::PhoneBook()
{
  bookmarks_["current"] = book_.begin();
}

void PhoneBook::add(const PhoneBook::contact& contact)
{
  book_.pushBack(contact);

  if (std::next(book_.begin()) == book_.end())
  {
    bookmarks_["current"] = book_.begin();
  }
}

void PhoneBook::store(const std::string& markName, const std::string& newMarkName)
{
  if (markName == newMarkName)
  {
    return;
  }
  auto bookmark = getBookmark(markName);

  bookmarks_[newMarkName] = bookmark->second;
}

void PhoneBook::insert(const std::string& position, const std::string& markName, const PhoneBook::contact& contact)
{
  auto bookmark = getBookmark(markName);

  if (book_.empty())
  {
    book_.pushBack(contact);
    bookmarks_.find("current")->second = book_.begin();
  }
  else if (position == "before")
  {
    book_.insertBefore(bookmark->second, contact);
  }
  else if (position == "after")
  {
    book_.insertAfter(bookmark->second, contact);
  }
  else throw std::invalid_argument("<INVALID COMMAND>");
}

void PhoneBook::remove(const std::string& markName)
{
  if (book_.empty())
  {
    throw std::invalid_argument("<EMPTY>");
  }

  auto oldBookmarkIt = getBookmark(markName)->second;

  for (auto& bookmark : bookmarks_)
  {
    if (bookmark.second == oldBookmarkIt)
    {
      if (std::next(bookmark.second) == book_.end())
      {
        bookmark.second = ComponentBook::prev(oldBookmarkIt);
      }
      else
      {
        bookmark.second = ComponentBook::next(oldBookmarkIt);
      }
    }
  }
  book_.remove(oldBookmarkIt);
}

void PhoneBook::show(const std::string& markName, std::ostream& out)
{
  auto bookmark = getBookmark(markName);

  if (book_.empty())
  {
    throw std::invalid_argument("<EMPTY>");
  }
  out << bookmark->second->first << " " << bookmark->second->second << "\n";
}

void PhoneBook::move(const std::string& markName, const std::string& distance)
{
  auto bookmark = getBookmark(markName);

  if (distance == "first")
  {
    bookmarks_[bookmark->first] = book_.begin();
  }
  else if (distance == "last")
  {
    if (!book_.empty())
    {
      bookmarks_[bookmark->first] = --book_.end();
    }
  }
  else
  {
    int steps = getSteps(distance);
    book_.move(bookmark->second, steps);
  }
}

std::map<std::string, ComponentBook::iterator>::iterator PhoneBook::getBookmark(const std::string& markName)
{
  auto bookmark = bookmarks_.find(markName);

  if (bookmark == bookmarks_.end())
  {
    throw std::invalid_argument("<INVALID BOOKMARK>");
  }
  return bookmark;
}

int PhoneBook::getSteps(const std::string& steps)
{
  try
  {
    int intSteps = std::stoi(steps);
    return intSteps;
  }
  catch (const std::invalid_argument& e)
  {
    throw std::invalid_argument("<INVALID STEP>");
  }
}
