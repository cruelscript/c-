#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>
#include <cmath>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(RecatangleTests)

  BOOST_AUTO_TEST_CASE(TestInvalidArgumentRectangle)
  {
    BOOST_CHECK_THROW(kubov::Rectangle rectangle({0.0, 0.0}, -3.0, 5.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovePointSideRectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({5.5, 7.4});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 5.5, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 7.4, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 2.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, 0.001);
  }


  BOOST_AUTO_TEST_CASE(TestMovePointAreaRectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({6.4, 4.5});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 6.4, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 4.5, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 11.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaSideRectangle)
  {
    kubov::point_t center = {0.0, 0.0};
    kubov::Rectangle rectangle(center, 2.0, 5.5);

    double deltaX = 7.5;
    double deltaY = 2.8;
    rectangle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 2.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaAreaRectangle)
  {
    kubov::point_t center = {0.0, 0.0};
    kubov::Rectangle rectangle(center, 2.0, 5.5);

    double deltaX = 4.4;
    double deltaY = 6.4;
    rectangle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 11.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestScaleAreaRectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 4.2);
    rectangle.scale(2.0);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 4.0 * 8.4, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTests)

  BOOST_AUTO_TEST_CASE(TestInvalidArgumentCircle)
  {
    BOOST_CHECK_THROW(kubov::Circle circle({0.0, 0.0}, -3.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovePointRadiusCircle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move({5.5, 7.4});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, 5.5, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, 7.4, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMovePointAreaCircle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move({6.4, 4.5});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, 6.4, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, 4.5, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaRadiusCircle)
  {
    kubov::point_t center = {0.0, 0.0};
    kubov::Circle circle(center, 2.0);

    double deltaX = 7.5;
    double deltaY = 2.8;
    circle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaAreaCircle)
  {
    kubov::point_t center = {0.0, 0.0};
    kubov::Circle circle(center, 2.0);

    double deltaX = 4.4;
    double deltaY = 6.4;
    circle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestScaleAreaCircle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.scale(2.0);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 4.0 * M_PI * 2.0 * 2.0, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()
