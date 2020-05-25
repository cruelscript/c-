#define BOOST_TEST_MAIN
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

const double epsilon = 1e-6;

BOOST_AUTO_TEST_SUITE(TestRectandle)
BOOST_AUTO_TEST_CASE(NonPositiveWightOrHeightRectangle)
{
  BOOST_CHECK_THROW(kazanskaya::Rectangle(-0.5, 5.2, { 2.5, 1.5 }), std::invalid_argument);
  BOOST_CHECK_THROW(kazanskaya::Rectangle(0.5, -5.2, { 2.5, 1.5 }), std::invalid_argument);
  BOOST_CHECK_THROW(kazanskaya::Rectangle(-0.5, -5.2, { 2.5, 1.5 }), std::invalid_argument);
  BOOST_CHECK_THROW(kazanskaya::Rectangle(0.0, 5.2, { 2.5, 1.5 }), std::invalid_argument);
  BOOST_CHECK_THROW(kazanskaya::Rectangle(0.5, 0.0, { 2.5, 1.5 }), std::invalid_argument);
  BOOST_CHECK_THROW(kazanskaya::Rectangle(0.0, 0.0, { 2.5, 1.5 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleAfterMoveToPoint)
{
  kazanskaya::Rectangle rectangle(5.0, 2.0, { -0.5, 1.5 });

  double beforeFrameWidht = rectangle.getFrameRect().width;
  double beforeFrameHeight = rectangle.getFrameRect().height;
  double centerX = 0.5;
  double centerY = -1.5;
  rectangle.move({ centerX, centerY });

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, beforeFrameWidht, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, beforeFrameHeight, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, centerX, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, centerY, epsilon);
}

BOOST_AUTO_TEST_CASE(UnchangingRectangleAreaAfterMoveToPoint)
{
  kazanskaya::Rectangle rectangle(5.0, 2.0, { -0.5, 1.5 });

  double beforeArea = rectangle.getArea();
  double centerX = 0.5;
  double centerY = -1.5;
  rectangle.move({ centerX, centerY });

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), beforeArea, epsilon);
}

BOOST_AUTO_TEST_CASE(RectangleAfterMoveByShift)
{
  kazanskaya::Rectangle rectangle(5.0, 2.0, { -0.5, 1.5 });

  double beforeFrameWidht = rectangle.getFrameRect().width;
  double beforeFrameHeight = rectangle.getFrameRect().height;
  double beforeX = rectangle.getFrameRect().pos.x;
  double beforeY = rectangle.getFrameRect().pos.y;
  double dX = 4.2;
  double dY = -3.7;
  rectangle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, beforeFrameWidht, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, beforeFrameHeight, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, beforeX + dX, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, beforeY + dY, epsilon);
}

BOOST_AUTO_TEST_CASE(UnchangingRectangleAreaAfterMoveByShift)
{
  kazanskaya::Rectangle rectangle(5.0, 2.0, { -0.5, 1.5 });

  double beforeArea = rectangle.getArea();
  double dX = 4.2;
  double dY = -3.7;
  rectangle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), beforeArea, epsilon);
}

BOOST_AUTO_TEST_CASE(NonPositiveCoefficientForScale)
{
  kazanskaya::Rectangle rectangle(5.0, 2.0, { -0.5, 1.5 });

  BOOST_CHECK_THROW(rectangle.scale(-1.2), std::invalid_argument);
  BOOST_CHECK_THROW(rectangle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleAfterScale)
{
  kazanskaya::Rectangle rectangle(5.0, 2.0, { -0.5, 1.5 });

  double beforeX = rectangle.getFrameRect().pos.x;
  double beforeY = rectangle.getFrameRect().pos.y;
  double coefficient = 3.7;
  rectangle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, beforeX, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, beforeY, epsilon);
}

BOOST_AUTO_TEST_CASE(ChangingRectangleAreaAfterScale)
{
  kazanskaya::Rectangle rectangle(5.0, 2.0, { -0.5, 1.5 });

  double beforeArea = rectangle.getArea();
  double coefficient = 3.7;
  rectangle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), beforeArea * coefficient * coefficient, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCircle)
BOOST_AUTO_TEST_CASE(NonPositiveRadiusCircle)
{
  BOOST_CHECK_THROW(kazanskaya::Circle circle(-8.1, { 1.5, 3.4 }), std::invalid_argument);
  BOOST_CHECK_THROW(kazanskaya::Circle circle(0.0, { 1.5, 3.4 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleAfterMoveToPoint)
{
  kazanskaya::Circle circle(2.0, { -0.5, 1.5 });

  double beforeFrameWidht = circle.getFrameRect().width;
  double beforeFrameHeight = circle.getFrameRect().height;
  double centerX = 0.5;
  double centerY = -1.5;
  circle.move({ centerX, centerY });

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, beforeFrameWidht, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, beforeFrameHeight, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, centerX, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, centerY, epsilon);
}

BOOST_AUTO_TEST_CASE(UnchangingCircleAreaAfterMoveToPoint)
{
  kazanskaya::Circle circle(2.0, { -0.5, 1.5 });

  double beforeArea = circle.getArea();
  double centerX = 0.5;
  double centerY = -1.5;
  circle.move({ centerX, centerY });

  BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), beforeArea, epsilon);
}

BOOST_AUTO_TEST_CASE(CircleAfterMoveByShift)
{
  kazanskaya::Circle circle(2.0, { -0.5, 1.5 });

  double beforeFrameWidht = circle.getFrameRect().width;
  double beforeFrameHeight = circle.getFrameRect().height;
  double beforeX = circle.getFrameRect().pos.x;
  double beforeY = circle.getFrameRect().pos.y;
  double dX = 4.2;
  double dY = -3.7;
  circle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, beforeFrameWidht, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, beforeFrameHeight, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, beforeX + dX, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, beforeY + dY, epsilon);
}

BOOST_AUTO_TEST_CASE(UnchangingCircleAreaAfterMoveByShift)
{
  kazanskaya::Circle circle(2.0, { -0.5, 1.5 });

  double beforeArea = circle.getArea();
  double dX = 4.2;
  double dY = -3.7;
  circle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), beforeArea, epsilon);
}

BOOST_AUTO_TEST_CASE(NonPositiveCoefficientForScale)
{
  kazanskaya::Circle circle(2.0, { -0.5, 1.5 });

  BOOST_CHECK_THROW(circle.scale(-1.2), std::invalid_argument);
  BOOST_CHECK_THROW(circle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleAfterScale)
{
  kazanskaya::Circle circle(2.0, { -0.5, 1.5 });

  double beforeX = circle.getFrameRect().pos.x;
  double beforeY = circle.getFrameRect().pos.y;
  double coefficient = 3.7;
  circle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, beforeX, epsilon);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, beforeY, epsilon);
}

BOOST_AUTO_TEST_CASE(ChangingCircleAreaAfterScale)
{
  kazanskaya::Circle circle(2.0, { -0.5, 1.5 });

  double beforeArea = circle.getArea();
  double coefficient = 3.7;
  circle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), beforeArea * coefficient * coefficient, epsilon);
}

BOOST_AUTO_TEST_SUITE_END()
