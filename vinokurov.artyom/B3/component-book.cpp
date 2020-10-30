#include "component-book.hpp"

ComponentBook::iterator ComponentBook::begin()
{
  return book_.begin();
}

ComponentBook::iterator ComponentBook::end()
{
  return book_.end();
}

ComponentBook::iterator ComponentBook::next(iterator iterator)
{
  return ++iterator;
}

ComponentBook::iterator ComponentBook::prev(iterator iterator)
{
  return --iterator;
}

void ComponentBook::insertBefore(const iterator& iterator, const contact& value)
{
  book_.insert(iterator, value);
}

void ComponentBook::insertAfter(const iterator& iterator, const contact& value)
{
  book_.insert(std::next(iterator), value);
}

void ComponentBook::pushBack(const contact& value)
{
  book_.push_back(value);
}

void ComponentBook::move(iterator& iterator, int distance)
{
  if (book_.empty())
  {
    return;
  }

  for (int i = 0; i < std::abs(distance); ++i)
  {
    if (distance >= 0)
    {
      if (++iterator == book_.end())
      {
        break;
      }
    }
    else
    {
      if (--iterator == book_.begin())
      {
        break;
      }
    }
  }
}

void ComponentBook::remove(iterator iterator)
{
  book_.erase(iterator);
}

bool ComponentBook::empty() const
{
  return book_.empty();
}
