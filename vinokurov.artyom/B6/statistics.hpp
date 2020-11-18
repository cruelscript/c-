#ifndef B6_STATISTICS_HPP
#define B6_STATISTICS_HPP

#include <limits>
#include <iostream>
#include <algorithm>

template <typename value_t>
class Statistics
{
public:

  void operator()(value_t value);
  void print(std::ostream&);

private:
  value_t min_{};
  value_t max_{};
  double mean_{};
  size_t positive_{};
  size_t negative_{};
  value_t oddSum_{};
  value_t evenSum_{};
  bool firstEqLast_{};

  size_t count_ = 0;
  value_t first_{};
};

template<typename value_t>
void Statistics<value_t>::operator()(value_t value)
{
  if(count_ == 0)
  {
    first_ = value;
    min_ = value;
    max_ = value;
    firstEqLast_ = true;
  }
  else
  {
    min_ = std::min(min_, value);
    max_ = std::max(max_, value);
    firstEqLast_ = first_ == value;
  }

  if(value != 0)
  {
    value > 0 ? ++positive_ : ++negative_;
  }

  (value % 2 == 0 ? evenSum_ : oddSum_) += value;

  mean_ = static_cast<double>(oddSum_ + evenSum_) / ++count_;
}

template<typename value_t>
void Statistics<value_t>::print(std::ostream& out)
{
  if(count_ == 0)
  {
    out << "Empty\n";
  }
  else
  {
    out << "Max: " << max_
      << "\nMin: " << min_
      << "\nMean: " << mean_
      << "\nPositive: " << positive_
      << "\nNegative: " << negative_
      << "\nOdd Sum: " << oddSum_
      << "\nEven Sum: " << evenSum_
      << "\nFirst/Last Equal: " << (firstEqLast_ ? "yes" : "no");
  }
}

#endif //B6_STATISTICS_HPP
