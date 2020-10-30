#ifndef B3_FACTORIAL_HPP
#define B3_FACTORIAL_HPP


#include <iterator>

class Factorial
{
public:
  class FIterator: public std::iterator<std::bidirectional_iterator_tag, unsigned long long>
  {
  public:

    FIterator();
    explicit FIterator(size_t);

    FIterator& operator ++();
    FIterator operator ++(int);
    FIterator& operator --();
    FIterator operator --(int);

    bool operator ==(const FIterator&) const noexcept;
    bool operator !=(const FIterator&) const noexcept;

    size_t operator *() const;
    size_t operator ->() const;
  private:
    size_t n_;
    value_type factorial() const;
  };
  Factorial() = default;

  static FIterator begin() ;
  static FIterator end() ;
private:
  static const size_t MIN_NUM = 1;
  static const size_t MAX_NUM = 10;

};


#endif //B3_FACTORIAL_HPP
