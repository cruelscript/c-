#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#define _USE_MATH_DEFINES

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"

const float epsilon = 0.00001;

BOOST_AUTO_TEST_SUITE(TestsRectangle)

  BOOST_AUTO_TEST_CASE(TestRectangleGetFrame)
  {
    sviridov::Rectangle rectangle = sviridov::Rectangle({ -2.2, 3.7 }, 4.4, 11.3);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, -2.2, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 3.7, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 4.4, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 11.3, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleGetArea)
  {
    sviridov::Rectangle rectangle = sviridov::Rectangle({ -7.9, 6.1 }, 2.2, 5.7);
    double expectedArea = 2.2 * 5.7;
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectedArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleMovingToPoint)
  {
    sviridov::Rectangle rectangle({ -4.6, 3.0 }, 9.1, 8.3);

    rectangle.move({ -11.1, -4.9 });

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, -11.1, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, -4.9, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 9.1, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 8.3, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleAreaAfterMovingToPoint)
  {
    sviridov::Rectangle rectangle({ -3.3, 7.0 }, 6.7, 3.5);

    double originalArea = rectangle.getArea();
    rectangle.move({ 7.7, -3.5 });

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleShifting)
  {
    sviridov::Rectangle rectangle({ -4.0, 3.8 }, 7.6, 8.1);

    double shiftX = 8.9;
    double shiftY = -4.5;

    rectangle.move(shiftX, shiftY);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, -4.0 + shiftX, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 3.8 + shiftY, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 7.6, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 8.1, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleAreaAfterShifting)
  {
    sviridov::Rectangle rectangle({ -6.7, 3.3 }, 4.1, 9.7);

    double originalArea = rectangle.getArea();

    rectangle.move(-3.8, -9.9);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestRectangleScaling)
  {
    sviridov::Rectangle rectangle({ -4.6, -8.7 }, 1.1, 9.9);

    double originalArea = rectangle.getArea();
    double scaleCoefficient = 3.7;

    rectangle.scale(scaleCoefficient);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, -4.6, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, -8.7, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 1.1 * scaleCoefficient, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 9.9 * scaleCoefficient, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), originalArea * scaleCoefficient * scaleCoefficient, epsilon);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCircle)

  BOOST_AUTO_TEST_CASE(TestCircleGetFrame)
  {
    sviridov::Circle circle = sviridov::Circle({ 0.4, 2.4 }, 3.1);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, 0.4, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, 2.4, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 6.2, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 6.2, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestCircleGetArea)
  {
    sviridov::Circle circle = sviridov::Circle({ 1.3, 6.4 }, 4.5);
    double expectedArea = 4.5 * 4.5 * M_PI;
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectedArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestCircleMovingToPoint)
  {
    sviridov::Circle circle({ 0.7, 1.0 }, 3.3);

    circle.move({ 3.7, -1.0 });

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, 3.7, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, -1.0, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 6.6, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 6.6, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestCircleAreaAfterMovingToPoint)
  {
    sviridov::Circle circle({ 3.3, 3.3 }, 7.5);

    double originalArea = circle.getArea();

    circle.move({ 3.7, -1.0 });

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestCircleShifting)
  {
    sviridov::Circle circle({ -3.2, 4.0 }, 2.3);

    double shiftX = 1.7;
    double shiftY = -5.4;

    circle.move(shiftX, shiftY);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, -3.2 + shiftX, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, 4.0 + shiftY, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.6, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.6, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestCircleAreaAfterShifting)
  {
    sviridov::Circle circle({ -2.4, 2.7 }, 1.9);

    double originalArea = circle.getArea();

    circle.move(-3.6, 3.3);

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), originalArea, epsilon);
  }

  BOOST_AUTO_TEST_CASE(TestCircleScaling)
  {
    sviridov::Circle circle({ -4.6, -8.7 }, 5.5);

    double originalArea = circle.getArea();
    double scaleCoefficient = 7.7;

    circle.scale(scaleCoefficient);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, -4.6, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, -8.7, epsilon);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 2 * 5.5 * scaleCoefficient, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 2 * 5.5 * scaleCoefficient, epsilon);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), originalArea * scaleCoefficient * scaleCoefficient, epsilon);
  }

BOOST_AUTO_TEST_SUITE_END()
