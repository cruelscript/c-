#define BOOST_TEST_MODULE UNIT_TESTS

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"

const double TOLERANCE = 0.0001;

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(testRectangleConstructorInvalidParameters)
{
  BOOST_CHECK_THROW(belova::Rectangle({ 6.56, 3.14 }, -13.4, 2.7), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle({ 6.56, 3.14 }, 13.4, -2.7), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle({ 6.56, 3.14 }, -13.4, -2.7), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle({ 6.56, 3.14 }, 0.0, 2.7), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle({ 6.56, 3.14 }, 13.4, 0.0), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle({ 6.56, 3.14 }, 0.0, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleSidesAfterPointMove)
{
  belova::Rectangle rectangle({ 0.0, 0.0 }, 18.1, 12.3);
  belova::rectangle_t rectBefore = rectangle.getFrameRect();

  rectangle.move({ 3.4, 12.2 });

  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, 3.4, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, 12.2, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.height, rectangle.getFrameRect().height, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.width, rectangle.getFrameRect().width, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaAfterPointMove)
{
  belova::Rectangle rectangle({ 0.0, 0.0 }, 5.2, 3.0);
  double rectAreaBefore = rectangle.getArea();
  rectangle.move({ 5.0, 1.2 });

  BOOST_CHECK_CLOSE(rectAreaBefore, rectangle.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testRectangleSidesAfterDeltaMove)
{
  belova::point_t center = { 0.0, 0.0 };
  belova::Rectangle rectangle(center, 18.1, 12.3);
  belova::rectangle_t rectBefore = rectangle.getFrameRect();

  double deltaX = -3.4;
  double deltaY = 12.2;
  rectangle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, center.x + deltaX, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, center.y + deltaY, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.height, rectangle.getFrameRect().height, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.width, rectangle.getFrameRect().width, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaAfterDeltaMove)
{
  belova::Rectangle rectangle({ 0.0, 0.0 }, 5.1, 9.0);
  double rectAreaBefore = rectangle.getArea();

  rectangle.move(-5.5, 24.0);

  BOOST_CHECK_CLOSE(rectAreaBefore, rectangle.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testRectangleInvalidScaleCoefficient)
{
  belova::Rectangle rectangle({ 0.0, 0.0 }, 5.0, 2.0);
  BOOST_CHECK_THROW(rectangle.scale(0.0), std::invalid_argument);
  BOOST_CHECK_THROW(rectangle.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaAfterScaling)
{
  belova::Rectangle rectangle({ 0.0, 0.0 }, 7.4, 9.0);
  double rectAreaBefore = rectangle.getArea();

  double scaleCoef = 2.0;
  rectangle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(rectAreaBefore * scaleCoef * scaleCoef, rectangle.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(testCircleConstructorInvalidParameters)
{
  BOOST_CHECK_THROW(belova::Circle({ 6.56, 3.14 }, -10.0), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Circle({ 6.56, 3.14 }, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleRadiusAfterPointMove)
{
  belova::Circle circle({ 0.0, 0.0 }, 5.5);
  belova::rectangle_t circBefore = circle.getFrameRect();

  circle.move({ 3.4, 12.2 });

  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, 3.4, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, 12.2, TOLERANCE);
  BOOST_CHECK_CLOSE(circBefore.width, circle.getFrameRect().width, TOLERANCE);
  BOOST_CHECK_CLOSE(circBefore.height, circle.getFrameRect().height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCircleAreaAfterPointMove)
{
  belova::Circle circle({ 0.0, 0.0 }, 3.1);
  double circAreaBefore = circle.getArea();
  circle.move({ 6.0, 3.2 });

  BOOST_CHECK_CLOSE(circAreaBefore, circle.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCircleRadiusAfterDeltaMove)
{
  belova::point_t center = { 0.0, 0.0 };
  belova::Circle circle(center, 3.1);
  belova::rectangle_t circBefore = circle.getFrameRect();

  double deltaX = 8.0;
  double deltaY = -12.3;
  circle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, center.x + deltaX, TOLERANCE);
  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, center.y + deltaY, TOLERANCE);
  BOOST_CHECK_CLOSE(circBefore.width, circle.getFrameRect().width, TOLERANCE);
  BOOST_CHECK_CLOSE(circBefore.height, circle.getFrameRect().height, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCircleAreaAfterDeltaMove)
{
  belova::Circle circle({ 0.0, 0.0 }, 34.1);
  double circAreaBefore = circle.getArea();

  circle.move(-5.0, 123.1);

  BOOST_CHECK_CLOSE(circAreaBefore, circle.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCircleInvalidScaleCoefficient)
{
  belova::Circle circle({ 0.0, 0.0 }, 5.0);
  BOOST_CHECK_THROW(circle.scale(0.0), std::invalid_argument);
  BOOST_CHECK_THROW(circle.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleAreaAfterScaling)
{
  belova::Circle circle({ 0.0, 0.0 }, 3.4);
  double circAreaBefore = circle.getArea();

  double scaleCoef = 3.0;
  circle.scale(scaleCoef);
  BOOST_CHECK_CLOSE(circAreaBefore * scaleCoef * scaleCoef, circle.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_SUITE_END()
