#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>

#include <stdexcept>
#include <cmath>

#include "rectangle.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(Recatangle_Tests)

  BOOST_AUTO_TEST_CASE(test_invalid_argument_rectangle)
  {
    BOOST_CHECK_THROW(kubov::Rectangle rectangle({0.0, 0.0}, -3.0, 5.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Point_Side_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({5.5, 7.4});
    BOOST_CHECK_EQUAL(rectangle.getFrameRect().width, 2.0);
    BOOST_CHECK_EQUAL(rectangle.getFrameRect().height, 5.5);
  }


  BOOST_AUTO_TEST_CASE(Test_Move_Point_Area_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({6.4, 4.5});
    BOOST_CHECK_EQUAL(rectangle.getArea(), 11.0);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Side_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move(7.5, 2.8);
    BOOST_CHECK_EQUAL(rectangle.getFrameRect().width, 2.0);
    BOOST_CHECK_EQUAL(rectangle.getFrameRect().height, 5.5);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Area_Rectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move(4.4, 6.4);
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
    BOOST_CHECK_EQUAL(circle.getFrameRect().width, 4.0);
    BOOST_CHECK_EQUAL(circle.getFrameRect().height, 4.0);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Point_Area_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move({6.4, 4.5});
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Radius_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move(7.5, 2.8);
    BOOST_CHECK_EQUAL(circle.getFrameRect().width, 4.0);
    BOOST_CHECK_EQUAL(circle.getFrameRect().height, 4.0);
  }

  BOOST_AUTO_TEST_CASE(Test_Move_Delta_Area_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move(4.4, 6.4);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(Test_Scale_Area_Circle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.scale(2.0);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 4.0 * M_PI * 2.0 * 2.0, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()
