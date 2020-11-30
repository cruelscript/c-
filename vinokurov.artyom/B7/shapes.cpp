#include <sstream>

#include "shapes.hpp"

Shape::Shape(const Point& pos) :
  center_(pos)
{}

bool Shape::isMoreLeft(Shape& shape) const
{
  return center_.x < shape.center_.x;
}

bool Shape::isUpper(Shape& shape) const
{
  return center_.y > shape.center_.y;
}

Circle::Circle(const Point& center) :
  Shape(center)
{}

Triangle::Triangle(const Point& center) :
  Shape(center)
{}

Square::Square(const Point& center) :
  Shape(center)
{}

void Circle::draw(std::ostream& out) const
{
  out << "CIRCLE (" << center_.x << "; " << center_.y << ")\n";
}

void Triangle::draw(std::ostream& out) const
{
  out << "TRIANGLE (" << center_.x << "; " << center_.y << ")\n";
}

void Square::draw(std::ostream& out) const
{
  out << "SQUARE (" << center_.x << "; " << center_.y << ")\n";
}

std::istream& operator >>(std::istream& in, Point& point)
{
  if (!(in >> std::ws))
  {
    return in;
  }

  char leftP = 0;
  char rightP = 0;
  char semicolon = 0;
  Point temp = {0, 0};

  in >> leftP >> temp.x >> semicolon >> temp.y >> rightP;

  if (leftP != '(' || rightP != ')' || semicolon != ';')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  if (!in.eof() && in.fail())
  {
    return in;
  }

  point = temp;
  return in;
}


std::istream& operator >>(std::istream& in, std::shared_ptr<Shape>& shapePtr)
{
  if (!(in >> std::ws))
  {
    return in;
  }

  std::string input;
  std::getline(in, input);
  std::stringstream sin(input);

  std::string name;
  for(char c; sin >> c;)
  {
    if(c == '(')
    {
      sin.unget();
      break;
    }
    name += c;
  }

  if (name.empty())
  {
    in.setstate(std::ios::failbit);
    return in;
  }


  Point temp{};
  sin >> temp;

  if (sin.fail())
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  if (name == "CIRCLE")
  {
    shapePtr = std::make_shared<Circle>(temp);
  }
  else if (name == "TRIANGLE")
  {
    shapePtr = std::make_shared<Triangle>(temp);
  }
  else if (name == "SQUARE")
  {
    shapePtr = std::make_shared<Square>(temp);
  }
  else
  {
    in.setstate(std::ios::failbit);
    return in;
  }
  return in;
}

std::ostream& operator <<(std::ostream& out, const std::shared_ptr<Shape>& shapePtr)
{
  shapePtr->draw(out);
  return out;
}
