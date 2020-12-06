#ifndef B8_DATA_PARSER_HPP
#define B8_DATA_PARSER_HPP

#include <vector>
#include <iostream>

class DataParser
{
public:
  explicit DataParser(std::istream&, std::ostream&, size_t lineWidth = 40);

  void input();
  void parse();
  void print();

private:
  static const size_t MAX_TOKEN_SIZE = 20;
  static const size_t MAX_DASH_SIZE = 3;

  std::istream& in;
  std::ostream& out;
  size_t lineWidth_;

  std::vector<char> buffer_;
  std::vector<std::string> result_;
};

#endif //B8_DATA_PARSER_HPP
