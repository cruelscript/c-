#include "factorial.hpp"

Factorial::FIterator::FIterator():
  n_(1)
{}

Factorial::FIterator::FIterator(size_t n):
  n_(n)
{}

Factorial::FIterator& Factorial::FIterator::operator++()
{
  ++n_;
  return *this;
}

Factorial::FIterator Factorial::FIterator::operator++(int)
{
  Factorial::FIterator temp = *this;
  ++(*this);
  return temp;

}

Factorial::FIterator& Factorial::FIterator::operator--()
{
  --n_;
  return *this;
}

Factorial::FIterator Factorial::FIterator::operator--(int)
{
  Factorial::FIterator temp = *this;
  --(*this);
  return temp;
}

bool Factorial::FIterator::operator==(const FIterator& rhs) const noexcept
{
  return rhs.n_ == n_;
}

bool Factorial::FIterator::operator!=(const FIterator& rhs) const noexcept
{
  return rhs.n_ != n_;
}

size_t Factorial::FIterator::operator*() const
{
  return factorial();
}

size_t Factorial::FIterator::operator->() const
{
  return factorial();
}

unsigned long long int Factorial::FIterator::factorial() const
{
  value_type result = 1;

  for(size_t i = 1; i <= n_; ++i)
  {
    result *= i;
  }
  return result;
}

Factorial::FIterator Factorial::begin()
{
  return Factorial::FIterator();
}

Factorial::FIterator Factorial::end()
{
  return Factorial::FIterator(MAX_NUM + 1);
}
