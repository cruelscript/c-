#ifndef B1_SORT_HPP
#define B1_SORT_HPP

#include <utility>

template <template <typename> class Access, class Container, class Comparator>
void bubbleSort(Container& container, Comparator& comparator)
{
  typedef typename Access<Container>::iterator iterator;
  typedef typename Access<Container>::reference reference;

  for (iterator i = Access<Container>::begin(container); i != Access<Container>::end(container); ++i)
  {
    reference lhs = Access<Container>::element(container, i);

    for (iterator j = i; j != Access<Container>::end(container); ++j)
    {
      reference rhs = Access<Container>::element(container, j);

      if (comparator(lhs, rhs))
      {
        std::swap(lhs, rhs);
      }
    }
  }
}

#endif //B1_SORT_HPP
