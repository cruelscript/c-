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
}

void DataParser::parse()
{
  std::locale locale("C");
  bool repeatPunct = false;

  auto begin = buffer_.begin();
  auto end = buffer_.end();

  while (begin != end)
  {
    std::string current;

    if (std::isalpha(*begin, locale))
    {
      while (begin != end)
      {
        if (std::isalpha(*begin, locale))
        {
          current.push_back(*begin);
        }
        else if (*begin == '-')
        {
          current.push_back(*begin);
          if (*(begin + 1) == '-')
          {
            throw std::invalid_argument("DataParser: Error. There is possible only 1 dash in a single word.");
          }
        }
        else break;
        begin++;
      }
      if (current.size() > MAX_TOKEN_SIZE)
      {
        throw std::invalid_argument("DataParser: Error. Supported only 20-letters wide words.");
      }
      repeatPunct = false;
    }

    else if (std::isdigit(*begin, locale) ||
             ((*begin == '+' || *begin == '-') && std::isdigit(*(begin + 1), locale)))
    {
      if (*begin == '+' || *begin == '-')
      {
        current.push_back(*begin);
        begin++;
      }

      char decimalPoint = std::use_facet<std::numpunct<char>>(in.getloc()).decimal_point();
      size_t numDecimalPoints = 0;

      while (begin != end)
      {
        if (std::isdigit(*begin, locale) || *begin == decimalPoint)
        {
          if (*begin == decimalPoint && ++numDecimalPoints > 1)
          {
            throw std::invalid_argument("DataParser: Error. Number can have only 1 decimal point.");
          }
          current.push_back(*begin);
        }
        else break;
        begin++;
      }
      if (current.size() > MAX_TOKEN_SIZE)
      {
        throw std::invalid_argument("DataParser: Error. Supported only 20-letters wide words.");
      }
      repeatPunct = false;
    }

    else if (*begin == '-')
    {
      if (result_.empty())
      {
        throw std::invalid_argument("DataParser: Error. Invalid dash location.");
      }
      char lastCh = result_.back().back();
      if (std::ispunct(lastCh, locale) && lastCh != ',' && lastCh != '-')
      {
        throw std::invalid_argument("DataParser: Error. Invalid punctuation location.");
      }
      for (size_t i = 0; i < MAX_DASH_SIZE; ++i)
      {
        if (*begin != '-')
        {
          throw std::invalid_argument("DataParser: Error. Invalid dash. Use '---' instead.");
        }
        current.push_back(*begin);
        begin++;
      }
      if(begin != end)
      {
        if(*begin == '-')
        {
          throw std::invalid_argument("DataParser: Error. Invalid dash. Use '---' instead.");
        }
      }
    }

    while (begin != end)
    {
      if (std::isspace(*begin, locale))
      {
        begin++;
      }
      else break;
    }

    if (begin != end)
    {
      if (std::ispunct(*begin, locale))
      {
        if (*begin != '-')
        {
          if (repeatPunct || current.empty())
          {
            throw std::invalid_argument("DataParser: Error. Invalid punctuation location.");
          }
          current.push_back(*begin);
          begin++;
        }
        repeatPunct = true;
      }
    }

    if (begin == end || !current.empty())
    {
      if (current == "---")
      {
        result_.back() += " ---";
      }
      else result_.push_back(current);
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
    if (token != *result_.rbegin())
    {
      if (size < lineWidth_ && size != 0)
      {
        out << " ";
      }
    }
    else out << "\n";
  }
}
