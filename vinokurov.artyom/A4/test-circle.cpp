#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "circle.hpp"

const double EPSILON = 1e-10;

BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(testCircleImmutabilityAfterPointMove)
{
  vinokurov::Circle testCircle(5.5, {1.2, 2.1});

  double widthBefore = testCircle.getFrameRect().width;
  double heightBefore = testCircle.getFrameRect().height;
  vinokurov::point_t movePoint = {4.8, -8.4};

  testCircle.move(movePoint);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, movePoint.x, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, movePoint.y, EPSILON);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleImmutabilityAfterDeltaMove)
{
  vinokurov::point_t centerPos = {1.2, 2.1};
  vinokurov::Circle testCircle(5.5, centerPos);

  double deltaX = 4.8;
  double deltaY = -8.4;
  double widthBefore = testCircle.getFrameRect().width;
  double heightBefore = testCircle.getFrameRect().height;

  testCircle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, centerPos.x + deltaX, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, centerPos.y + deltaY, EPSILON);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleImmutabilityAfterRotating)
{
  vinokurov::point_t centerPos = {1.2, 2.1};
  vinokurov::Circle testCircle(5.5, centerPos);

  double widthBefore = testCircle.getFrameRect().width;
  double heightBefore = testCircle.getFrameRect().height;

  testCircle.rotate(90);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, centerPos.x, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, centerPos.y, EPSILON);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, heightBefore, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, widthBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleAreaImmutabilityAfterPointMove)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  double areaBefore = testCircle.getArea();

  testCircle.move({2.2, 2.2});

  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleAreaImmutabilityAfterDeltaMove)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  double areaBefore = testCircle.getArea();

  testCircle.move(2.2, 2.2);

  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleAreaImmutabilityAfterRotating)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  double areaBefore = testCircle.getArea();

  testCircle.rotate(90);

  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleAreaChangingAfterScaling)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  double areaBefore = testCircle.getArea();

  testCircle.scale(7.7);

  BOOST_CHECK_CLOSE(areaBefore * 7.7 * 7.7, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionInvalidRadius)
{
  BOOST_CHECK_THROW(vinokurov::Circle testCircle(-5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionZeroRadius)
{
  BOOST_CHECK_THROW(vinokurov::Circle testCircle(0.0, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionInvalidScaling)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});

  BOOST_CHECK_THROW(testCircle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionZeroScaling)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});

  BOOST_CHECK_THROW(testCircle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
