#define BOOST_TEST_MODULE UNIT_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

const double ACCURACY = 1e-10;

BOOST_AUTO_TEST_SUITE(rectangleTest)

BOOST_AUTO_TEST_CASE(rectangleImmutabilityAfterPointMove)
{
  vinokurov::Rectangle testRectangle({1.2, 2.1}, 5.7, 7.5);
  testRectangle.move({4.8,-8.4});

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, 4.8, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, -8.4, ACCURACY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, 5.7, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, 7.5, ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangleImmutabilityAfterDeltaMove)
{
  vinokurov::Rectangle testRectangle({1.2,2.1}, 5.7, 7.5);
  testRectangle.move(4.8, -8.4);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, 1.2 + 4.8, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, 2.1 - 8.4, ACCURACY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, 5.7, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, 7.5, ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangleAreaImmutabilityAfterPointMove)
{
  vinokurov::Rectangle testRectangle({1.1,1.1}, 5.5, 5.5);
  double areaBefore = testRectangle.getArea();
  testRectangle.move({2.2,2.2});

  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangleAreaImmutabilityAfterDeltaMove)
{
  vinokurov::Rectangle testRectangle({1.1,1.1}, 5.5, 5.5);
  double areaBefore = testRectangle.getArea();
  testRectangle.move(2.2, 2.2);

  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectanleConstantAreaChangingAfterScaling)
{
  vinokurov::Rectangle testRectangle({1.1,1.1}, 5.5, 5.5);
  double areaBefore = testRectangle.getArea();
  testRectangle.scale(7.7);

  BOOST_CHECK_CLOSE(areaBefore * 7.7 * 7.7, testRectangle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionInvalidWidth)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle({1.1, 1.1}, -5.5, 5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionInvalidHeight)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle({1.1, 1.1}, 5.5, -5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionInvalidScaling)
{
  vinokurov::Rectangle testRectangle({1.1,1.1}, 5.5, 5.5);
  BOOST_CHECK_THROW(testRectangle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(circleTest)

BOOST_AUTO_TEST_CASE(circleImmutabilityAfterPointMove)
{
  vinokurov::Circle testCircle({1.2, 2.1}, 5.5);
  testCircle.move({4.8,-8.4});

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, 4.8, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, -8.4, ACCURACY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, 5.5 * 2, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, 5.5 * 2, ACCURACY);
}

BOOST_AUTO_TEST_CASE(circleImmutabilityAfterDeltaMove)
{
  vinokurov::Circle testCircle({1.2, 2.1}, 5.5);
  testCircle.move(4.8,-8.4);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, 1.2 + 4.8, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, 2.1 - 8.4, ACCURACY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, 5.5 * 2, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, 5.5 * 2, ACCURACY);
}

BOOST_AUTO_TEST_CASE(circleAreaImmutabilityAfterPointMove)
{
  vinokurov::Circle testCircle({1.1, 1.1}, 5.5);
  double areaBefore = testCircle.getArea();
  testCircle.move({2.2,2.2});

  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(circleAreaImmutabilityAfterDeltaMove)
{
  vinokurov::Circle testCircle({1.1, 1.1}, 5.5);
  double areaBefore = testCircle.getArea();
  testCircle.move(2.2,2.2);

  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(circleConstantAreaChangingAfterScaling)
{
  vinokurov::Circle testCircle({1.1,1.1}, 5.5);
  double areaBefore = testCircle.getArea();
  testCircle.scale(7.7);

  BOOST_CHECK_CLOSE(areaBefore * 7.7 * 7.7, testCircle.getArea(), ACCURACY);
}

BOOST_AUTO_TEST_CASE(circleExceptionInvalidRadius)
{
  BOOST_CHECK_THROW(vinokurov::Circle testCircle({1.1, 1.1}, -5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleExceptionInvalidScaling)
{
  vinokurov::Circle testCircle({1.1,1.1}, 5.5);
  BOOST_CHECK_THROW(testCircle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
