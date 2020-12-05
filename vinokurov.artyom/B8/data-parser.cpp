#include "data-parser.hpp"
#include <iterator>
#include <locale>

DataParser::DataParser(std::istream& istream, std::ostream& ostream, size_t lineWidth) :
  in(istream),
  out(ostream),
  lineWidth_(lineWidth)
{
  input();
  parse();
  print();
}

void DataParser::input()
{
  in >> std::noskipws;
  std::copy(std::istream_iterator<char>(in), std::istream_iterator<char>(),
            std::back_inserter(buffer_));

  if (!in.eof() && in.fail())
  {
    throw std::ios_base::failure("DataParser: Error. Failed to read data");
  }

  begin_ = buffer_.begin();
  end_ = buffer_.end();
}

void DataParser::parse()
{
  std::locale locale("C");
  bool isPunct = false;
  bool repeatPunct = false;

  while (begin_ != end_)
  {
    std::string current;

    if (std::isalpha(*begin_, locale))
    {
      while (begin_ != end_)
      {
        if (std::isalpha(*begin_, locale))
        {
          current.push_back(*begin_);
        }
        else if (*begin_ == '-')
        {
          current.push_back(*begin_);
          if (*(begin_ + 1) == '-')
          {
            throw std::invalid_argument("DataParser: Error. There is possible only 1 dash in a single word.");
          }
        }
        else break;
        begin_++;
      }
      if (current.size() > MAX_TOKEN_SIZE)
      {
        throw std::invalid_argument("DataParser: Error. Supported only 20-letters wide words.");
      }
      isPunct = false;
      repeatPunct = false;
    }

    else if (std::isdigit(*begin_, locale) ||
             ((*begin_ == '+' || *begin_ == '-') && std::isdigit(*(begin_ + 1), locale)))
    {
      if (*begin_ == '+' || *begin_ == '-')
      {
        current.push_back(*begin_);
        begin_++;
      }

      char decimalPoint = std::use_facet<std::numpunct<char>>(in.getloc()).decimal_point();
      size_t numDecimalPoints = 0;

      while (begin_ != end_)
      {
        if (std::isdigit(*begin_, locale) || *begin_ == decimalPoint)
        {
          if (*begin_ == decimalPoint && ++numDecimalPoints > 1)
          {
            throw std::invalid_argument("DataParser: Error. Number can have only 1 decimal point.");
          }
          current.push_back(*begin_);
        }
        else break;
        begin_++;
      }
      if (current.size() > MAX_TOKEN_SIZE)
      {
        throw std::invalid_argument("DataParser: Error. Supported only 20-letters wide words.");
      }
      isPunct = false;
      repeatPunct = false;
    }

    else if (*begin_ == '-')
    {
      for (size_t i = 0; i < MAX_DASH_SIZE; ++i)
      {
        if (*begin_ != '-')
        {
          throw std::invalid_argument("DataParser: Error. Invalid dash. Use '---' instead.");
        }
        current.push_back(*begin_);
        begin_++;
      }
    }

    while (begin_ != end_)
    {
      if (isPunct && *(begin_ + 1) == '-')
      {
        isPunct = false;
      }
      if (std::isspace(*begin_, locale))
      {
        begin_++;
      }
      else break;
    }

    if (begin_ != end_)
    {
      if (std::ispunct(*begin_, locale))
      {
        if (*begin_ != '-')
        {
          if (repeatPunct)
          {
            throw std::invalid_argument("DataParser: Error. Invalid punctuation location.");
          }
          current.push_back(*begin_);
          begin_++;
          isPunct = true;
        }
        repeatPunct = true;
      }
    }

    if (begin_ == end_ || !current.empty())
    {
      result_.push_back(current);
    }
  }
}

void DataParser::print()
{
  size_t size = 0;

  for (auto& token : result_)
  {
    size += token.size();

    if (size < lineWidth_)
    {
      if (!token.empty())
      {
        out << token;
        size++;
      }
    }
    else if (size == lineWidth_)
    {
      out << token << "\n";
      size = 0;
    }
    else
    {
      out << "\n" << token;
      size = token.size() + 1;
    }
    if(token != *result_.rbegin())
    {
      if(size < lineWidth_ && size != 0)
      {
        out << " ";
      }
    }
  }
}
