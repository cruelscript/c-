#ifndef B3_COMPONENT_BOOK_HPP
#define B3_COMPONENT_BOOK_HPP

#include <string>
#include <list>

class ComponentBook
{
public:
  typedef std::pair<std::string, std::string> contact;
  typedef std::list<contact>::iterator iterator;

  static iterator next(iterator);
  static iterator prev(iterator);
  void insertBefore(const iterator&, const contact&);
  void insertAfter(const iterator&, const contact&);
  void pushBack(const contact&);
  void move(iterator&, int distance);

  iterator begin();
  iterator end();
  void remove(iterator);
  bool empty() const;

private:
  std::list<contact> book_;
};

#endif //B3_COMPONENT_BOOK_HPP
