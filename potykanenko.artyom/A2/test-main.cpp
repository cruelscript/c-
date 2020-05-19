#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#define _USE_MATH_DEFINES

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"

#include <cmath>

const double ACCURACY = 1E-5;

BOOST_AUTO_TEST_SUITE(RectangleTests)

BOOST_AUTO_TEST_CASE(FirstConstructorCreateWrongRectangleTest)
{
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(10., -5., 0., 0.), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(-10., 5., 0., 0.), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(10., 0., 0., 0.), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(0., 5., 0., 0.), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(SecondConstructorCreateWrongRectangleTest)
{
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(10., -5., { 0., 0. }), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(-10., 5., { 0., 0. }), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(10., 0., { 0., 0. }), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Rectangle rectangle(0., 5., { 0., 0. }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(GetAreaRectangleTest)
{
  potykanenko::Rectangle rectangle(2., 5., 0., 0.);

  double area = 2. * 5.;

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), area, ACCURACY);
}

BOOST_AUTO_TEST_CASE(GetFrameRectWidthAndHeightRectangleTest)
{
  double width = 2.;
  double height = 5.;
  potykanenko::Rectangle rectangle(width, height, 0., 0.);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, width, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, height, ACCURACY);
}

BOOST_AUTO_TEST_CASE(GetFrameRectPosRectangleTest)
{
  double x = 1.5;
  double y = -3.5;
  potykanenko::Rectangle rectangle(2., 5., x, y);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, x, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, y, ACCURACY);
}

BOOST_AUTO_TEST_CASE(MoveDeltaWidthAndHeightRectangleTest)
{
  double width = 2.;
  double height = 5.;
  potykanenko::Rectangle rectangle(width, height, 4., 10.);

  double dx = 2.;
  double dy = -2.;
  rectangle.move(dx, dy);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, width, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, height, ACCURACY);
}

BOOST_AUTO_TEST_CASE(MoveDeltaPosXAndPosYRectangleTest)
{
  double firstX = 4.;
  double firstY = 10.;
  potykanenko::Rectangle rectangle(2., 5., firstX, firstY);

  double dx = 2.;
  double dy = -2.;

  rectangle.move(dx, dy);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, firstX + dx, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, firstY + dy, ACCURACY);
}

BOOST_AUTO_TEST_CASE(MovePointRectangleTest)
{
  double width = 2.;
  double height = 5.;
  potykanenko::Rectangle rectangle(width, height, 4., 7.);

  double secondX = 2.;
  double secondY = -2.;
  rectangle.move({ secondX, secondY });

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, width, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, height, ACCURACY);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, secondX, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, secondY, ACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleWrongCoefficientRectangleTest)
{
  potykanenko::Rectangle rectangle(10., 5., 0., 0.);

  BOOST_CHECK_THROW(rectangle.scale(-1.), std::invalid_argument);
  BOOST_CHECK_THROW(rectangle.scale(0.), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ScaleWidthAndHeightRectangleTest)
{
  double width = 10.;
  double height = 5.;
  potykanenko::Rectangle rectangle(width, height, 0., 0.);

  rectangle.scale(1.5);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, width * 1.5, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, height * 1.5, ACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalePosRectangleTest)
{
  double x = 1.;
  double y = -3.;
  potykanenko::Rectangle rectangle(10., 5., x, y);

  rectangle.scale(1.5);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, x, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, y, ACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleGetAreaRectangleTest)
{
  potykanenko::Rectangle rectangle(10., 5., 0., 0.);

  double expectedArea = rectangle.getArea() * 2.5 * 2.5;
  rectangle.scale(2.5);

  BOOST_CHECK_CLOSE_FRACTION(expectedArea, rectangle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(FirstConstructorCreateWrongCircleTest)
{
  BOOST_CHECK_THROW(potykanenko::Circle circle(-1., 2., 4.), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Circle circle(0., 2., 4.), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(SecondConstructorCreateWrongCircleTest)
{
  BOOST_CHECK_THROW(potykanenko::Circle circle(-1., { 2., 4. }), std::invalid_argument);
  BOOST_CHECK_THROW(potykanenko::Circle circle(0., { 2., 4. }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(GetAreaCircleTest)
{
  potykanenko::Circle circle(5., 0., 0.);

  double area = M_PI * 5. * 5.;

  BOOST_CHECK_CLOSE_FRACTION(area, circle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(GetFrameRectWidthAndHeightCircleTest)
{
  double radius = 4.5;
  potykanenko::Circle circle(radius, 0., 0.);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, radius * 2., ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, radius * 2., ACCURACY);
}

BOOST_AUTO_TEST_CASE(GetFrameRectPosCircleTest)
{
  double x = 2.;
  double y = 3.;
  potykanenko::Circle circle(4., x, y);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, x, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, y, ACCURACY);
}

BOOST_AUTO_TEST_CASE(MoveDeltaWidthAndHeightCircleTest)
{
  double radius = 2.;

  potykanenko::Circle circle(radius, 4., 10.);

  circle.move(2., -2.);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, radius * 2., ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, radius * 2., ACCURACY);
}

BOOST_AUTO_TEST_CASE(MoveDeltaPosXAndPosYCircleTest)
{
  double firstX = 4.;
  double firstY = 10.;

  potykanenko::Circle circle(2., firstX, firstY);

  double dx = 2.;
  double dy = -2.;
  circle.move(dx, dy);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, firstX + dx, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, firstY + dy, ACCURACY);
}

BOOST_AUTO_TEST_CASE(MovePointCircleTest)
{
  double radius = 2.;

  potykanenko::Circle circle(radius, 4., 7.);

  double secondX = 2.;
  double secondY = -2.;
  circle.move({ secondX, secondY });

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, secondX, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, secondY, ACCURACY);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, radius * 2, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, radius * 2, ACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleWrongCoefficientCircleTest)
{
  potykanenko::Circle circle(3., 0., 0.);

  BOOST_CHECK_THROW(circle.scale(-1.), std::invalid_argument);
  BOOST_CHECK_THROW(circle.scale(0.), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ScaleWidthAndHeightCircleTest)
{
  double radius = 4.5;
  potykanenko::Circle circle(radius, 0., 0.);

  radius *= 1.5;

  circle.scale(1.5);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, radius * 2., ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, radius * 2., ACCURACY);
}

BOOST_AUTO_TEST_CASE(ScalePosCircleTest)
{
  double x = 1.;
  double y = -3.;
  potykanenko::Circle circle(2., x, y);

  circle.scale(1.5);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, x, ACCURACY);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, y, ACCURACY);
}

BOOST_AUTO_TEST_CASE(ScaleGetAreaCircleTest)
{
  potykanenko::Circle circle(2., 0., 0.);

  double expectedArea = circle.getArea() * 2.5 * 2.5;
  circle.scale(2.5);

  BOOST_CHECK_CLOSE_FRACTION(expectedArea, circle.getArea(), ACCURACY); 
}

BOOST_AUTO_TEST_SUITE_END()
