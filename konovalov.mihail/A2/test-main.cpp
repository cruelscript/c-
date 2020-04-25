#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"

static const double EPSILON = 1e-8;

BOOST_AUTO_TEST_SUITE(RectangleTestsCases)

  BOOST_AUTO_TEST_CASE(TestCorrectConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_NO_THROW(konovalov::Rectangle rectangle({1.0, 1.0, {0.0, 0.0}}));
  }

  BOOST_AUTO_TEST_CASE(TestNotCorrectDataInConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_THROW(konovalov::Rectangle rectangle({-1.0, 1.1, {0.0, 1.1}}), std::invalid_argument);
    BOOST_CHECK_THROW(konovalov::Rectangle rectangle({1.0, -1.1, {0.0, 1.1}}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetFrameRectWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle({1.1, 1.2, {0.0, 0.1}});

    //check frame correct
    BOOST_CHECK_CLOSE_FRACTION(1.1, rectangle.getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(1.2, rectangle.getFrameRect().height, EPSILON);

    //check point correct
    BOOST_CHECK_CLOSE_FRACTION(0.0, rectangle.getFrameRect().pos.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(0.1, rectangle.getFrameRect().pos.y, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMoveCoordinateWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle({1.0, 2.0, {1.1, 3.5}});
    double expectX = 7.1 + 1.1;
    double expectY = 3.4 + 3.5;
    rectangle.move(7.1, 3.4);

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, expectX, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, expectY, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 1.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMovePointWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle({1.0, 2.0, {1.0, 2.0}});
    rectangle.move({7.1, 3.4});

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 7.1, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 3.4, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 1.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetAreaWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle({6.0, 2.0, {1.0, 2.0}});
    double expectArea = 6.0 * 2.0;
    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterMoving)
  {
    konovalov::point_t centerPoint = {1.0, 2.0};
    konovalov::Rectangle rectangle = konovalov::Rectangle({3.0, 2.0, {centerPoint.x, centerPoint.y}});
    double dx = 7.1;
    double dy = 3.4;
    double expectArea = 3.0 * 2.0;
    rectangle.move(dx, dy);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, centerPoint.x + dx, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, centerPoint.y + dy, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterChangingPoint)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle({3.0, 2.0, {1.0, 2.0}});
    konovalov::point_t newCenterPoint = {2.0, 3.0};
    double expectArea = 3.0 * 2.0;
    rectangle.move(newCenterPoint);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, newCenterPoint.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, newCenterPoint.y, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectExceptionScaleWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle({4.5, 2.0, {1.1, 1.2}});
    double coefficient = -1.1;
    //check correct exception
    BOOST_CHECK_THROW(rectangle.scale(coefficient), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectScaleWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle({4.5, 2.0, {1.1, 1.2}});
    double coefficient = 2.0;
    double expectArea = 4.5 * 2.0 * 2.0 * 2.0;
    rectangle.scale(coefficient);

    //check correct scaled
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 4.5 * coefficient, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 2.0 * coefficient, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CircleTestCases)

  BOOST_AUTO_TEST_CASE(TestCorrectConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_NO_THROW(konovalov::Circle circle(1.1, {0.0, 0.0}));
  }

  BOOST_AUTO_TEST_CASE(TestNotCorrectDataInConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_THROW(konovalov::Circle circle(-1.0, {0.0, 1.1}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetFrameRectWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.1, {0.0, 0.1});

    //check radius correct
    BOOST_CHECK_CLOSE_FRACTION(2.2, circle.getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(2.2, circle.getFrameRect().height, EPSILON);

    //check point correct
    BOOST_CHECK_CLOSE_FRACTION(0.0, circle.getFrameRect().pos.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(0.1, circle.getFrameRect().pos.y, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMoveCoordinateWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.0, {1.1, 3.5});
    double expectX = 1.1 + 7.1;
    double expectY = 3.5 + 3.4;
    circle.move(7.1, 3.4);

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, expectX, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, expectY, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 2.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMovePointWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.0, {1.0, 2.0});
    circle.move({7.1, 3.4});

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, 7.1, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, 3.4, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 2.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetAreaWork)
  {
    konovalov::Circle circle = konovalov::Circle(6.0, {1.0, 2.0});
    double expectArea = 6.0 * 6.0 * M_PI;
    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterMoving)
  {
    konovalov::point_t centerPoint = {1.0, 2.0};
    konovalov::Circle circle = konovalov::Circle(3.0, centerPoint);
    double dx = 7.1;
    double dy = 3.4;
    double expectArea = 3.0 * 3.0 * M_PI;
    circle.move(dx, dy);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, centerPoint.x + dx, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, centerPoint.y + dy, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterChangingPoint)
  {
    konovalov::Circle circle = konovalov::Circle(3.0, {1.0, 2.0});
    konovalov::point_t newCenterPoint = {3.2, 5.2};
    double expectArea = 3.0 * 3.0 * M_PI;
    circle.move(newCenterPoint);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, newCenterPoint.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, newCenterPoint.y, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectExceptionScaleWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.1, {1.2, 2.3});
    double coefficient = -1.1;

    //check correct exception
    BOOST_CHECK_THROW(circle.scale(coefficient), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectScaleWork)
  {
    konovalov::Circle circle = konovalov::Circle(2.0, {1.1, 1.2});
    double coefficient = 2.0;
    double expectArea = 2.0 * 2.0 * M_PI * 2.0 * 2.0;
    circle.scale(coefficient);

    //check correct scaled
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 2.0 * 2.0 * coefficient, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 2.0 * 2.0 * coefficient, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

BOOST_AUTO_TEST_SUITE_END()
