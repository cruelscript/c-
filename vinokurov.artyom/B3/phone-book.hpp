#ifndef B3_PHONE_BOOK_HPP
#define B3_PHONE_BOOK_HPP

#include <map>
#include "component-book.hpp"

class PhoneBook
{
public:
  typedef ComponentBook::contact contact;

  PhoneBook();

  void add(const contact&);
  void store(const std::string& markName, const std::string& newMarkName);
  void insert(const std::string& position, const std::string& markName, const contact&);
  void remove(const std::string& markName);
  void show(const std::string& markName, std::ostream&);
  void move(const std::string& markName, const std::string& destination);

  static int getSteps(const std::string& steps);

private:
  ComponentBook book_;
  std::map<std::string, ComponentBook::iterator> bookmarks_;

  std::map<std::string, ComponentBook::iterator>::iterator getBookmark(const std::string& markName);
};


#endif //B3_PHONE_BOOK_HPP
