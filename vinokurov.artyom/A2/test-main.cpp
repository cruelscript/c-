#define BOOST_TEST_MODULE UNIT_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

const double ACCURACY = 1e-10;

BOOST_AUTO_TEST_SUITE(RectangleTest)

BOOST_AUTO_TEST_CASE(rectangleImmutabilityAfterPointMove)
{
  vinokurov::Rectangle testRectangle({1.2, 2.1}, 5.7, 7.5);

  double widthBefore = testRectangle.getFrameRect().width;
  double heightBefore = testRectangle.getFrameRect().height;
  vinokurov::point_t movePoint = {4.8, 8.4};

  testRectangle.move(movePoint);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, movePoint.x, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, movePoint.y, ACCURACY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBefore, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBefore, ACCURACY);
}

BOOST_AUTO_TEST_CASE(rectangleImmutabilityAfterDeltaMove)
{
  vinokurov::point_t centerPos = {1.2, 2.1};
  vinokurov::Rectangle testRectangle(centerPos, 5.7, 7.5);;

  double widthBefore = testRectangle.getFrameRect().width;
  double heightBefore = testRectangle.getFrameRect().height;
  double deltaX = 4.8;
  double deltaY = -8.4;

  testRectangle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, centerPos.x + deltaX, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, centerPos.y + deltaY, ACCURACY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBefore, ACCURACY);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBefore, ACCURACY);
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

BOOST_AUTO_TEST_CASE(rectangleAreaChangingAfterScaling)
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

BOOST_AUTO_TEST_CASE(rectangleExceptionZeroWidth)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle({ 1.1, 1.1 }, 0.0, 5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionInvalidHeight)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle({1.1, 1.1}, 5.5, -5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionZeroHeight)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle({ 1.1, 1.1 }, 5.5, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionInvalidScaling)
{
  vinokurov::Rectangle testRectangle({1.1,1.1}, 5.5, 5.5);
  BOOST_CHECK_THROW(testRectangle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleExceptionZeroScaling)
{
  vinokurov::Rectangle testRectangle({ 1.1,1.1 }, 5.5, 5.5);
  BOOST_CHECK_THROW(testRectangle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(circleImmutabilityAfterPointMove)
{
  vinokurov::Circle testCircle({1.2, 2.1}, 5.5);

  double widthBefore = testCircle.getFrameRect().width;
  double heightBefore = testCircle.getFrameRect().height;
  vinokurov::point_t movePoint = {4.8, -8.4};

  testCircle.move(movePoint);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, movePoint.x, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, movePoint.y, ACCURACY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBefore, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBefore, ACCURACY);
}

BOOST_AUTO_TEST_CASE(circleImmutabilityAfterDeltaMove)
{
  vinokurov::point_t centerPos = {1.2, 2.1};
  vinokurov::Circle testCircle(centerPos, 5.5);

  double deltaX = 4.8;
  double deltaY = -8.4;
  double widthBefore = testCircle.getFrameRect().width;
  double heightBefore = testCircle.getFrameRect().height;

  testCircle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, centerPos.x + deltaX, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, centerPos.y + deltaY, ACCURACY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBefore, ACCURACY);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBefore, ACCURACY);
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

BOOST_AUTO_TEST_CASE(circleAreaChangingAfterScaling)
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

BOOST_AUTO_TEST_CASE(circleExceptionZeroRadius)
{
  BOOST_CHECK_THROW(vinokurov::Circle testCircle({ 1.1, 1.1 }, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleExceptionInvalidScaling)
{
  vinokurov::Circle testCircle({1.1,1.1}, 5.5);
  BOOST_CHECK_THROW(testCircle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleExceptionZeroScaling)
{
  vinokurov::Circle testCircle({1.1, 1.1}, 5.5);
  BOOST_CHECK_THROW(testCircle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
