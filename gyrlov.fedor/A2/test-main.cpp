#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"

static const double EPSILON = 1e-8;
const double invalidHeight = -1.0;
const double zeroHeight = 0.0;
const double invalidWidth = -2.0;
const double zeroWidth = 0.0;
const double invalidScale = -3.0;
const double invalidRadius = -1.0;
const double zeroRadius = 0.0;
const gyrlov::point_t center = {5.0, 7.0};

BOOST_AUTO_TEST_SUITE(RecatangleTests)

BOOST_AUTO_TEST_CASE(TestMoveToRectangle)
{
  gyrlov::Rectangle rectangle(center, 2.0, 5.5);
  rectangle.move({5.5, 7.5});

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 5.5, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 7.5, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 2.0, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, EPSILON);
}


BOOST_AUTO_TEST_CASE(TestMoveToPointAreaRectangle)
{
  gyrlov::Rectangle rectangle(center, 2.0, 5.5);
  double areaBeforeMoving = rectangle.getArea();
  rectangle.move({5.4, 4.5});
  double areaAfterMoving = rectangle.getArea();

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 5.4, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 4.5, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(areaAfterMoving, areaBeforeMoving, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestMoveAlongRectangle)
{
  gyrlov::Rectangle rectangle(center, 3.0, 5.5);

  double dx = 7.5;
  double dy = 2.8;
  rectangle.move(dx, dy);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, center.x + dx, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, center.y + dy, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 3.0, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestMoveAlongAreaRectangle)
{
  gyrlov::Rectangle rectangle(center, 2.0, 5.5);
  
  double areaBeforeMoving = rectangle.getArea();
  
  double dx = 4.4;
  double dy = 6.4;
  rectangle.move(dx, dy);
  
  double areaAfterMoving = rectangle.getArea();

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, center.x + dx, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, center.y + dy, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(areaAfterMoving, areaBeforeMoving, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestScaleRectangle)
{
  gyrlov::Rectangle rectangle(center, 2.0, 4.2);

  double areaBeforeScaling = rectangle.getArea();

  rectangle.scale(2.0);

  double areaAfterScaling = rectangle.getArea();

  BOOST_CHECK_CLOSE_FRACTION(areaAfterScaling, areaBeforeScaling * 4.0, EPSILON);
}

BOOST_AUTO_TEST_CASE(RectangleInvalidWidth)
{
  BOOST_CHECK_THROW(gyrlov::Rectangle(center, invalidWidth, 5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleInvalidHeight)
{
  BOOST_CHECK_THROW(gyrlov::Rectangle(center, 5.5, invalidHeight), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleZeroWidth)
{
  BOOST_CHECK_THROW(gyrlov::Rectangle(center, zeroWidth, 5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleZeroHeight)
{
  BOOST_CHECK_THROW(gyrlov::Rectangle(center, 5.5, zeroHeight), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleInvalidScale)
{
  gyrlov::Rectangle testRectangle(center, 5.5, 5.5);
  BOOST_CHECK_THROW(testRectangle.scale(invalidScale), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(TestMovePointRadiusCircle)
{
  gyrlov::Circle circle(center, 2.0);
  circle.move({5.5, 7.4});

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, 5.5, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, 7.4, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestMovePointAreaCircle)
{
  gyrlov::Circle circle(center, 2.0);

  double areaBeforeMoving = circle.getArea();

  circle.move({6.4, 4.5});

  double areaAfterMoving = circle.getArea();

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, 6.4, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, 4.5, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(areaAfterMoving, areaBeforeMoving, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestMoveDeltaRadiusCircle)
{
  gyrlov::Circle circle(center, 2.0);

  double dx = 8.1;
  double dy = 3.5;
  circle.move(dx, dy);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, center.x + dx, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, center.y + dy, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestMoveDeltaAreaCircle)
{
  gyrlov::Circle circle(center, 2.0);

  double areaBeforeMoving = circle.getArea();

  double dx = 4.4;
  double dy = 6.4;
  circle.move(dx, dy);

  double areaAfterMoving = circle.getArea();

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, center.x + dx, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, center.y + dy, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(areaAfterMoving, areaBeforeMoving, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestScaleAreaCircle)
{
  gyrlov::Circle circle(center, 2.0);
  double areaBeforeScaling = circle.getArea();

  circle.scale(2.0);

  double areaAfterScaling = circle.getArea();

  BOOST_CHECK_CLOSE_FRACTION(areaAfterScaling, areaBeforeScaling * 4.0, EPSILON);
}

BOOST_AUTO_TEST_CASE(CircleInvalidRadius)
{
  BOOST_CHECK_THROW(gyrlov::Circle testCircle(center, invalidRadius), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleZeroRadius)
{
  BOOST_CHECK_THROW(gyrlov::Circle testCircle(center, zeroRadius), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleInvalidScale)
{
  gyrlov::Circle testCircle(center, 5.5);
  BOOST_CHECK_THROW(testCircle.scale(invalidScale), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
