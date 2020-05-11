#define BOOST_TEST_MODULE mytests

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

const double EPSYLON = 1e-10;
BOOST_AUTO_TEST_SUITE(RectangleTest)

BOOST_AUTO_TEST_CASE(chekRectangleAfterMovePoint)
{
  chevychelov::point_t middle = {1.5, 3.1};
  chevychelov::Rectangle testRectangle(11.2, 5.7, middle);
  chevychelov::point_t movePoint = {7.3, 9.2};
  double widthBeforeMove = testRectangle.getFrameRect().width;
  double heightBeforeMove = testRectangle.getFrameRect().height;

  testRectangle.move(movePoint);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, movePoint.x, EPSYLON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, movePoint.y, EPSYLON);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBeforeMove, EPSYLON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBeforeMove, EPSYLON);
}

BOOST_AUTO_TEST_CASE(chekRectangleAfterMoveCoordinates)
{
  chevychelov::point_t middle = { 1.5, 3.1 };
  chevychelov::Rectangle testRectangle(11.2, 5.7, middle);
  double widthBeforeMove = testRectangle.getFrameRect().width;
  double heightBeforeMove = testRectangle.getFrameRect().height;
  double dX = 3.7;
  double dY = 8.3;

  testRectangle.move(dX, dY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, middle.x + dX, EPSYLON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, middle.y + dY, EPSYLON);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBeforeMove, EPSYLON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBeforeMove, EPSYLON);
}

BOOST_AUTO_TEST_CASE(checkRectangleAreaAfterMovePoint)
{
  chevychelov::point_t middle = {1.5, 3.1};
  chevychelov::Rectangle testRectangle(11.2, 5.7, middle);
  double areaBeforeMove = testRectangle.getArea();

  testRectangle.move({1.7, 11.3});

  BOOST_CHECK_CLOSE(areaBeforeMove, testRectangle.getArea(), EPSYLON);
}

BOOST_AUTO_TEST_CASE(checkRectangleAreaAfterMoveCoordinates)
{
  chevychelov::point_t middle = { 1.5, 3.1 };
  chevychelov::Rectangle testRectangle(11.2, 5.7, middle);
  double areaBeforeMove = testRectangle.getArea();
  testRectangle.move(7.3, 9.2);

  BOOST_CHECK_CLOSE(areaBeforeMove, testRectangle.getArea(), EPSYLON);
}

BOOST_AUTO_TEST_CASE(checkRectangleAreaAfterScale)
{
  chevychelov::point_t middle = {1.5, 3.1};
  chevychelov::Rectangle testRectangle(11.2, 5.7, middle);
  double areaBeforeScale = testRectangle.getArea();
  testRectangle.scale(9.2);

  BOOST_CHECK_CLOSE(areaBeforeScale * 9.2 * 9.2, testRectangle.getArea(), EPSYLON);
}

BOOST_AUTO_TEST_CASE(rectangleInvalidWidth)
{
  BOOST_CHECK_THROW(chevychelov::Rectangle testRectangle(0.0, 11.2, {2.2, 2.2}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleInvalidHeight)
{
  BOOST_CHECK_THROW(chevychelov::Rectangle testRectangle(3.5, -11.2, {2.2, 2.2}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(rectangleInvalidScaleCoefficient)
{
  chevychelov::Rectangle testRectangle(3.0, 11.2, {2.2, 2.2});
  BOOST_CHECK_THROW(testRectangle.scale(-11.5), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(chekCircleAfterMovePoint)
{
  chevychelov::point_t middle = {1.5, 3.1};
  chevychelov::Circle testCircle(5.7, middle);
  chevychelov::point_t movePoint = {7.3, 9.2};
  double widthBeforeMove = testCircle.getFrameRect().width;
  double heightBeforeMove = testCircle.getFrameRect().height;

  testCircle.move(movePoint);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, movePoint.x, EPSYLON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, movePoint.y, EPSYLON);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBeforeMove, EPSYLON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBeforeMove, EPSYLON);
}

BOOST_AUTO_TEST_CASE(chekCircleAfterMoveCoordinates)
{
  chevychelov::point_t middle = { 1.5, 3.1 };
  chevychelov::Circle testCircle(5.7, middle);
  double widthBeforeMove = testCircle.getFrameRect().width;
  double heightBeforeMove = testCircle.getFrameRect().height;
  double dX = 3.7;
  double dY = 8.3;

  testCircle.move(dX, dY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, middle.x + dX, EPSYLON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, middle.y + dY, EPSYLON);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBeforeMove, EPSYLON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBeforeMove, EPSYLON);
}

BOOST_AUTO_TEST_CASE(checkCircleAreaAfterMovePoint)
{
  chevychelov::point_t middle{1.5, 3.1};
  chevychelov::Circle testCircle(5.7, middle);
  double areaBeforeMove = testCircle.getArea();

  testCircle.move({1.7, 11.3});

  BOOST_CHECK_CLOSE(areaBeforeMove, testCircle.getArea(), EPSYLON);
}

BOOST_AUTO_TEST_CASE(checkCircleAreaAfterMoveCoordinates)
{
  chevychelov::point_t middle{ 1.5, 3.1 };
  chevychelov::Circle testCircle(5.7, middle);
  double areaBeforeMove = testCircle.getArea();
  testCircle.move(7.3, 9.2);

  BOOST_CHECK_CLOSE(areaBeforeMove, testCircle.getArea(), EPSYLON);

}

BOOST_AUTO_TEST_CASE(checkCircleAreaAfterScale)
{
  chevychelov::point_t middle = {1.5, 3.1};
  chevychelov::Circle testCircle(5.7, middle);
  double areaBeforeScale = testCircle.getArea();
  testCircle.scale(9.2);

  BOOST_CHECK_CLOSE(areaBeforeScale * 9.2 * 9.2, testCircle.getArea(), EPSYLON);
}

BOOST_AUTO_TEST_CASE(circleInvalidRadius)
{
  BOOST_CHECK_THROW(chevychelov::Circle testCircle(-11.2, {2.2, 2.2}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(circleInvalidScaleCoefficient)
{
  chevychelov::Circle testCircle(3.0, {2.2, 2.2});
  BOOST_CHECK_THROW(testCircle.scale(-11.5), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()
