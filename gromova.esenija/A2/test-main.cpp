#define BOOST_TEST_MODULE TEST_A2

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

const double EPSILON = 1e-6;

BOOST_AUTO_TEST_SUITE(RectangleTests)

BOOST_AUTO_TEST_CASE(NegativeHeightInConstuctor)
{
  BOOST_CHECK_THROW(gromova::Rectangle rectangleWithNegativeHeight(-6.8, 4.2, { -3, -9 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroHeightInConstructor)
{
  BOOST_CHECK_THROW(gromova::Rectangle rectangleWithNegativeHeight(0, 4.2, { -3, -9 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NegativeWidthInConstructor)
{
  BOOST_CHECK_THROW(gromova::Rectangle rectangleWithNegativeHeight(6.8, -4.2, { -3, -9 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroWidthInConstructor)
{
  BOOST_CHECK_THROW(gromova::Rectangle rectangleWithNegativeHeight(6.8, 0, { -3, -9 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NegativeCoefficientInScaleRectangle)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });
  BOOST_CHECK_THROW(testRectangle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroCoefficientInScaleRectangle)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NormalCoefficientInScaleRectangle)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });
  BOOST_CHECK_NO_THROW(testRectangle.scale(3));
}

BOOST_AUTO_TEST_CASE(InvariabilityOfRectangleAfterMovingToThePoint)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });
  double heightBeforeMoving = testRectangle.getFrameRect().height;
  double widthBeforeMoving = testRectangle.getFrameRect().width;
  double areaBeforeMoving = testRectangle.getArea();

  testRectangle.move({ 4.7, 6.3 });

  BOOST_CHECK_CLOSE_FRACTION(heightBeforeMoving, testRectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(widthBeforeMoving, testRectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(areaBeforeMoving, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(InvariabilityOfRectangleAfterMovingByAxeses)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });
  double heightBeforeMoving = testRectangle.getFrameRect().height;
  double widthBeforeMoving = testRectangle.getFrameRect().width;
  double areaBeforeMoving = testRectangle.getArea();

  testRectangle.move(3, -4);

  BOOST_CHECK_CLOSE_FRACTION(heightBeforeMoving, testRectangle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(widthBeforeMoving, testRectangle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(areaBeforeMoving, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(QuadraticChangeInTheAreaOfTheRectangleWhenScaling)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });
  double areaBeforeScaling = testRectangle.getArea();
  double k = 3;
  testRectangle.scale(k);

  BOOST_CHECK_CLOSE_FRACTION(areaBeforeScaling, testRectangle.getArea() / (k * k), EPSILON);
}

BOOST_AUTO_TEST_CASE(CenterChangeOfRectangleAfterMovingToThePoint)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });

  testRectangle.move({ 4.7, 6.3 });

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.x, 4.7, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.y, 6.3, EPSILON);
}

BOOST_AUTO_TEST_CASE(CenterChangeOfRectangleAfterMovingByAxeses)
{
  gromova::Rectangle testRectangle(6.8, 4.2, { -3, -9 });
  gromova::point_t centreBeforeMoving = { testRectangle.getFrameRect().pos.x, testRectangle.getFrameRect().pos.y };

  testRectangle.move(3, -4);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.x, centreBeforeMoving.x + 3, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.y, centreBeforeMoving.y - 4, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(NegativeRadiusInConstuctor)
{
  BOOST_CHECK_THROW(gromova::Circle circle(-5.7, { 2.5, 8 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroRadiusInConstuctor)
{
  BOOST_CHECK_THROW(gromova::Circle circle(0, { 2.5, 8 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NegativeCoefficientInScaleCircle)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });
  BOOST_CHECK_THROW(testCircle.scale(-3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroCoefficientInScaleCircle)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });
  BOOST_CHECK_THROW(testCircle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NormalCoefficientInScaleCircle)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });
  BOOST_CHECK_NO_THROW(testCircle.scale(3));
}

BOOST_AUTO_TEST_CASE(InvariabilityOfCircleAfterMovingToThePoint)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });
  double heightBeforeMoving = testCircle.getFrameRect().height;
  double widthBeforeMoving = testCircle.getFrameRect().width;
  double areaBeforeMoving = testCircle.getArea();

  testCircle.move({ 4.7, 6.3 });

  BOOST_CHECK_CLOSE_FRACTION(heightBeforeMoving, testCircle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(widthBeforeMoving, testCircle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(areaBeforeMoving, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(InvariabilityOfCircleAfterMovingByAxeses)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });
  double heightBeforeMoving = testCircle.getFrameRect().height;
  double widthBeforeMoving = testCircle.getFrameRect().width;
  double areaBeforeMoving = testCircle.getArea();

  testCircle.move(3, -4);

  BOOST_CHECK_CLOSE_FRACTION(heightBeforeMoving, testCircle.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(widthBeforeMoving, testCircle.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(areaBeforeMoving, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(QuadraticChangeInTheAreaOfTheCircleWhenScaling)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });
  double areaBeforeScaling = testCircle.getArea();
  double k = 3;
  testCircle.scale(k);

  BOOST_CHECK_CLOSE_FRACTION(areaBeforeScaling, testCircle.getArea() / (k * k), EPSILON);
}

BOOST_AUTO_TEST_CASE(CenterChangeOfCircleAfterMovingToThePoint)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });

  testCircle.move({ 4.7, 6.3 });

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.x, 4.7, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.y, 6.3, EPSILON);
}

BOOST_AUTO_TEST_CASE(CenterChangeOfCircleAfterMovingByAxeses)
{
  gromova::Circle testCircle(5.7, { 2.5, 8 });
  gromova::point_t centreBeforeMoving = { testCircle.getFrameRect().pos.x, testCircle.getFrameRect().pos.y };

  testCircle.move(3, -4);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.x, centreBeforeMoving.x + 3, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.y, centreBeforeMoving.y - 4, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
