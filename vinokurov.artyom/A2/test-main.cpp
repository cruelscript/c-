#define BOOST_TEST_MODULE UNIT_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

const double EPSILON = 1e-10;

BOOST_AUTO_TEST_SUITE(RectangleTest)

BOOST_AUTO_TEST_CASE(testRectangleImmutabilityAfterPointMove)
{
  vinokurov::Rectangle testRectangle(5.7, 7.5, {1.2, 2.1});

  double widthBefore = testRectangle.getFrameRect().width;
  double heightBefore = testRectangle.getFrameRect().height;
  vinokurov::point_t movePoint = {4.8, 8.4};

  testRectangle.move(movePoint);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, movePoint.x, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, movePoint.y, EPSILON);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleImmutabilityAfterDeltaMove)
{
  vinokurov::point_t centerPos = {1.2, 2.1};
  vinokurov::Rectangle testRectangle(5.7, 7.5, centerPos);

  double widthBefore = testRectangle.getFrameRect().width;
  double heightBefore = testRectangle.getFrameRect().height;
  double deltaX = 4.8;
  double deltaY = -8.4;

  testRectangle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, centerPos.x + deltaX, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, centerPos.y + deltaY, EPSILON);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaImmutabilityAfterPointMove)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  double areaBefore = testRectangle.getArea();
  testRectangle.move({2.2, 2.2});

  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaImmutabilityAfterDeltaMove)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  double areaBefore = testRectangle.getArea();
  testRectangle.move(2.2, 2.2);

  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaChangingAfterScaling)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  double areaBefore = testRectangle.getArea();
  testRectangle.scale(7.7);

  BOOST_CHECK_CLOSE(areaBefore * 7.7 * 7.7, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidWidth)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(-5.5, 5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroWidth)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(0.0, 5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidHeight)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(5.5, -5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroHeight)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(5.5, 0.0, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidScaling)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  BOOST_CHECK_THROW(testRectangle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroScaling)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  BOOST_CHECK_THROW(testRectangle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


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
