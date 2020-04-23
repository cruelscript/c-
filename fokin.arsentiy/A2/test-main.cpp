#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const float EPSILON = 0.0001;

BOOST_AUTO_TEST_SUITE(RectangleTests)

BOOST_AUTO_TEST_CASE(RectangleCreatingWithInvalidWidth)
{
  BOOST_CHECK_THROW(fokin::Rectangle testRectangle(-4.0, 5.0, { 2.6, -1.4 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleCreatingWithInvalidHeight)
{
  BOOST_CHECK_THROW(fokin::Rectangle testRectangle(4.0, -5.0, { 2.6, -1.4 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleImmutabilityAfterMovingToPoint)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialWidth = testRectangle.getFrameRect().width;
  double initialHeight = testRectangle.getFrameRect().height;

  double initialArea = testRectangle.getArea();

  double newX = -5.1;
  double newY = 9.7;

  testRectangle.move({ newX, newY });

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().width, initialWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().height, initialHeight, EPSILON);

  BOOST_REQUIRE_CLOSE_FRACTION(testRectangle.getFrameRect().pos.x, newX, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(testRectangle.getFrameRect().pos.y, newY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(RectangleImmutabilityAfterShifting)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialFrameWidth = testRectangle.getFrameRect().width;
  double initialFrameHeight = testRectangle.getFrameRect().height;

  double initialX = testRectangle.getFrameRect().pos.x;
  double initialY = testRectangle.getFrameRect().pos.y;

  double initialArea = testRectangle.getArea();

  double dX = -5.1;
  double dY = 9.7;

  testRectangle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().width, initialFrameWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().height, initialFrameHeight, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.x, initialX + dX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.y, initialY + dY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(RectangleInvalidScaleCoefficient)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  BOOST_CHECK_THROW(testRectangle.scale(-2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleCorrectAreaAfterScaling)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialX = testRectangle.getFrameRect().pos.x;
  double initialY = testRectangle.getFrameRect().pos.y;

  double initialArea = testRectangle.getArea();
  double coefficient = 2.7;
  testRectangle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.x, initialX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().pos.y, initialY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getArea(), initialArea * coefficient * coefficient, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(CircleCreatingWithInvalidRadius)
{
  BOOST_CHECK_THROW(fokin::Circle testCircle({ 1.0, 0.0 }, -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleImmutabilityAfterMovingToPoint)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialFrameWidth = testCircle.getFrameRect().width;
  double initialFrameHeight = testCircle.getFrameRect().height;

  double initialArea = testCircle.getArea();

  double newX = -5.1;
  double newY = 9.7;

  testCircle.move({ newX, newY });

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().width, initialFrameWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().height, initialFrameHeight, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.x, newX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.y, newY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(CircleImmutabilityAfterShifting)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialFrameWidth = testCircle.getFrameRect().width;
  double initialFrameHeight = testCircle.getFrameRect().height;

  double initialX = testCircle.getFrameRect().pos.x;
  double initialY = testCircle.getFrameRect().pos.y;

  double initialArea = testCircle.getArea();

  double dX = -5.1;
  double dY = 9.7;

  testCircle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().width, initialFrameWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().height, initialFrameHeight, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.x, initialX + dX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.y, initialY + dY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(CircleInvalidScaleCoefficient)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  BOOST_CHECK_THROW(testCircle.scale(-2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleCorrectAreaAfterScaling)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialX = testCircle.getFrameRect().pos.x;
  double initialY = testCircle.getFrameRect().pos.y;

  double initialArea = testCircle.getArea();
  double coefficient = 2.7;
  testCircle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.x, initialX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().pos.y, initialY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getArea(), initialArea * coefficient * coefficient, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
