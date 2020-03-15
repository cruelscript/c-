#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>
#include <cmath>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(Recatangle_Tests)

  BOOST_AUTO_TEST_CASE(Test_Invalid_Argument_Rectangle)
  {
    BOOST_CHECK_THROW(kubov::Rectangle rectangle({0.0, 0.0}, -3.0, 5.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Point_Side_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({5.5, 7.4});

    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 2.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, 0.001);
  }


  BOOST_AUTO_TEST_CASE(Test_Move_Point_Area_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({6.4, 4.5});

    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 11.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Side_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move(7.5, 2.8);

    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 2.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Area_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move(4.4, 6.4);

    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(rectangle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 11.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Scale_Area_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 4.2);
    rectangle.scale(2.0);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 4.0 * 8.4, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(Circle_Tests)

  BOOST_AUTO_TEST_CASE(Test_Invalid_Argument_Circle)
  {
    BOOST_CHECK_THROW(kubov::Circle circle({0.0, 0.0}, -3.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Point_Radius_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move({5.5, 7.4});

    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Point_Area_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move({6.4, 4.5});

    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Radius_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move(7.5, 2.8);

    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Area_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move(4.4, 6.4);

    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.x != 0.0, "Error in method move");
    BOOST_REQUIRE_MESSAGE(circle.getFrameRect().pos.y != 0.0, "Error in method move");

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Scale_Area_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.scale(2.0);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 4.0 * M_PI * 2.0 * 2.0, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()
