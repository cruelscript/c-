#ifndef B1_ACCESS_HPP
#define B1_ACCESS_HPP

#include <iterator>

template <typename Container>
class OperatorAccess
{
public:

  typedef typename std::size_t iterator;
  typedef typename Container::reference reference;

  static size_t begin(const Container&)
  {
    return 0;
  }

  static size_t end(const Container& vector)
  {
    return vector.size();
  }

  static reference element(Container& vector, size_t index)
  {
    return vector[index];
  }
};

template <typename Container>
class AtAccess
{
public:

  typedef typename std::size_t iterator;
  typedef typename Container::reference reference;

  static iterator begin(const Container&)
  {
    return 0;
  }

  static iterator end(const Container& vector)
  {
    return vector.size();
  }

  static reference element(Container& vector, size_t index)
  {
    return vector.at(index);
  }
};

template <typename Container>
class IteratorAccess
{
public:

  typedef typename Container::reference reference;
  typedef typename Container::iterator iterator;

  static iterator begin(Container& container)
  {
    return container.begin();
  }

  static iterator end(Container& container)
  {
    return container.end();
  }

  static reference element(Container&, iterator& elem)
  {
    return *elem;
  }
};

#endif //B1_ACCESS_HPP
