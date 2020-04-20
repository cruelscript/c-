#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const float epsilon = 0.0001;

BOOST_AUTO_TEST_SUITE(TestsRectangle)
  BOOST_AUTO_TEST_CASE(RectangleCreateWithInvalidWidth)
  {
    BOOST_CHECK_THROW(shevtsov::Rectangle rectangle(-2.0, 2.0, {1.0, 3.1}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectangleCreateWithInvalidHeight)
  {
    BOOST_CHECK_THROW(shevtsov::Rectangle rectangle(2.0, -2.0, {1.0, 3.1}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectangleMoveCenterToPoint)
  {
    shevtsov::Rectangle rectangle(10.0, 3.2, {-1.2, 1.0});

    double originalFrameWidth = rectangle.getFrameRect().width;
    double originalFrameHeight = rectangle.getFrameRect().height;

    double newX = 3.7;
    double newY = -1.0;

    rectangle.move({newX, newY});

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, originalFrameWidth, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, originalFrameHeight, epsilon);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, newX, epsilon);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, newY, epsilon);
  }

  BOOST_AUTO_TEST_CASE(RectangleAreaImmutabilityAfterMoveCenterToPoint)
  {
    shevtsov::Rectangle rectangle(10.0, 3.2, {-1.2, 1.0});

    double originalArea = rectangle.getArea();
    rectangle.move({4.7, 2.5});

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(RectangleMoveCenterByShift)
  {
    shevtsov::Rectangle rectangle(10.0, 3.2, {-1.2, 1.0});

    double originalFrameWidth = rectangle.getFrameRect().width;
    double originalFrameHeight = rectangle.getFrameRect().height;

    double originalX = rectangle.getFrameRect().pos.x;
    double originalY = rectangle.getFrameRect().pos.y;

    double shiftX = 1.7;
    double shiftY = -5.4;

    rectangle.move(shiftX, shiftY);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, originalFrameWidth, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, originalFrameHeight, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, originalX + shiftX, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, originalY + shiftY, epsilon);
  }

  BOOST_AUTO_TEST_CASE(RectangleAreaImmutabilityAfterMoveCenterByShift)
  {
    shevtsov::Rectangle rectangle(10.0, 3.2, {-1.2, 1.0});

    double originalArea = rectangle.getArea();
    rectangle.move(1.7, -5.4);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(RectangleInvalidScaleRate)
  {
    shevtsov::Rectangle rectangle(10.0, 3.2, {-1.2, 1.0});

    BOOST_CHECK_THROW(rectangle.scale(-2.2), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectangleScaleMutabilityArea)
  {
    shevtsov::Rectangle rectangle(10.0, 3.2, {-1.2, 1.0});

    double originalX = rectangle.getFrameRect().pos.x;
    double originalY = rectangle.getFrameRect().pos.y;

    double originalArea = rectangle.getArea();
    double scaleRate = 2.4;
    rectangle.scale(scaleRate);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, originalX, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, originalY, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), originalArea * scaleRate * scaleRate, epsilon);
  }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestsCircle)
  BOOST_AUTO_TEST_CASE(CircleCreateWithInvalidRadius)
  {
    BOOST_CHECK_THROW(shevtsov::Circle circle(-2.0, {1.0, 0.0}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(CircleMoveCenterToPoint)
  {
    shevtsov::Circle circle(3.2, {0.0, 0.0});

    double originalFrameWidth = circle.getFrameRect().width;
    double originalFrameHeight = circle.getFrameRect().height;

    double newX = 3.7;
    double newY = -1.0;

    circle.move({newX, newY});

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, originalFrameWidth, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, originalFrameHeight, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, newX, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, newY, epsilon);
  }

  BOOST_AUTO_TEST_CASE(CircleAreaImmutabilityAfterMoveCenterToPoint)
  {
    shevtsov::Circle circle(3.2, {0.0, 0.0});

    double originalArea = circle.getArea();
    circle.move({3.7, -1.0});

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(CircleMoveCenterByShift)
  {
    shevtsov::Circle circle(3.2, {-1.2, 1.0});

    double originalFrameWidth = circle.getFrameRect().width;
    double originalFrameHeight = circle.getFrameRect().height;

    double originalX = circle.getFrameRect().pos.x;
    double originalY = circle.getFrameRect().pos.y;

    double shiftX = 1.7;
    double shiftY = -5.4;

    circle.move(shiftX, shiftY);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, originalFrameWidth, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, originalFrameHeight, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, originalX + shiftX, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, originalY + shiftY, epsilon);
  }

  BOOST_AUTO_TEST_CASE(CircleAreaImmutabilityAfterMoveCenterByShift)
  {
    shevtsov::Circle circle(3.2, {-1.2, 1.0});

    double originalArea = circle.getArea();
    circle.move(1.7, -5.4);

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(CircleInvalidScaleRate)
  {
    shevtsov::Circle circle(3.5, {0.0, 1.0});

    BOOST_CHECK_THROW(circle.scale(-2.3), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(CircleScaleMutabilityArea)
  {
    shevtsov::Circle circle(3.5, {0.0, 1.0});

    double originalArea = circle.getArea();
    double scaleRate = 2;
    circle.scale(2);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, 0.0, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, 1.0, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), originalArea * scaleRate * scaleRate, epsilon);
  }
BOOST_AUTO_TEST_SUITE_END()
