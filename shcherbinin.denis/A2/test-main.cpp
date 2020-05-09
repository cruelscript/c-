#define BOOST_TEST_MODULE A2_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>
#include "circle.hpp"
#include "rectangle.hpp"

const double ACCURACY = 1e-10;
const double WIDTH = 5.0;
const double HEIGHT = 5.0;
const double RADIUS = 5.0;
const double SHAPE_CENTER_X = 1.0;
const double SHAPE_CENTER_Y = 1.0;
const double POINT_X = 3.0;
const double POINT_Y = 3.0;
const double DELTA_X = 2.0;
const double DELTA_Y = 2.0;
const double SCALE_COEF = 2.5;
const double ZERO_PARAMETER = 0.0;
const double NEGATIVE_PARAMETER = -1.0;

BOOST_AUTO_TEST_SUITE(RectangleTests)

  BOOST_AUTO_TEST_CASE(RectangleMoveToPointTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    rectangle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, POINT_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, POINT_Y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleDeltaMoveTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    rectangle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, SHAPE_CENTER_X + DELTA_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, SHAPE_CENTER_Y + DELTA_Y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleWidthNotChangedAfterMoveToPointTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    rectangle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().width, WIDTH, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleHeightNotChangedAfterMoveToPointTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    rectangle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().height, HEIGHT, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleWidthNotChangedAfterDeltaMoveTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    rectangle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().width, WIDTH, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleHeightNotChangedAfterDeltaMoveTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    rectangle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().height, HEIGHT, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleAreaNotChangedAfterMoveToPointTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    double areaBeforeMove = rectangle.getArea();
    rectangle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBeforeMove, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleAreaNotChangedAfterDeltaMoveTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    double areaBeforeMove = rectangle.getArea();
    rectangle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBeforeMove, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleScaleTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    double areaBeforeScale = rectangle.getArea();

    rectangle.scale(SCALE_COEF);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBeforeScale * SCALE_COEF * SCALE_COEF, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(RectangleNegativeWidthTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(NEGATIVE_PARAMETER, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectangleNegativeHeightTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(WIDTH, NEGATIVE_PARAMETER, SHAPE_CENTER_X, SHAPE_CENTER_Y),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectnagleNegativeSidesTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(NEGATIVE_PARAMETER, NEGATIVE_PARAMETER, SHAPE_CENTER_X, SHAPE_CENTER_Y),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectnagleZeroWidthTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(ZERO_PARAMETER, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectnagleZeroHeightTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(WIDTH, ZERO_PARAMETER, SHAPE_CENTER_X, SHAPE_CENTER_Y),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectnagleZeroSidesTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(ZERO_PARAMETER, ZERO_PARAMETER, SHAPE_CENTER_X, SHAPE_CENTER_Y),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectanglePointNegativeWidthTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(NEGATIVE_PARAMETER, HEIGHT, {SHAPE_CENTER_X, SHAPE_CENTER_Y}),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectanglePointNegativeHeightTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(WIDTH, NEGATIVE_PARAMETER, {SHAPE_CENTER_X, SHAPE_CENTER_Y}),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectanglePointNegativeSidesTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(NEGATIVE_PARAMETER, NEGATIVE_PARAMETER, {SHAPE_CENTER_X, SHAPE_CENTER_Y}),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectanglePointZeroWidthTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(ZERO_PARAMETER, HEIGHT, {SHAPE_CENTER_X, SHAPE_CENTER_Y}),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectanglePointZeroHeightTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(WIDTH, ZERO_PARAMETER, {SHAPE_CENTER_X, SHAPE_CENTER_Y}),
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectanglePointZeroSidesTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Rectangle(ZERO_PARAMETER, ZERO_PARAMETER, {SHAPE_CENTER_X, SHAPE_CENTER_Y}),\
      std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectangleNegativeScaleCoefTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    BOOST_CHECK_THROW(rectangle.scale(NEGATIVE_PARAMETER), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(RectangleZeroScaleCoefTest)
  {
    shcherbinin::Rectangle rectangle = shcherbinin::Rectangle(WIDTH, HEIGHT, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    BOOST_CHECK_THROW(rectangle.scale(ZERO_PARAMETER), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(CircleTests)

  BOOST_AUTO_TEST_CASE(CircleMoveToPointTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, POINT_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, POINT_Y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleDeltaMoveTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, POINT_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, POINT_Y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleRadiusNotChangedAfterMoveToPointTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width / 2, RADIUS, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleRadiusNotChangedAfterDeltaMoveTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width / 2, RADIUS, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleFrameRectangleWidthNotChangedAfterMoveToPointTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, RADIUS * 2, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleFrameRectangleHeightNotChangedAfterMoveToPointTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().height, RADIUS * 2, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleFrameRectangleWidthNotChangedAfterDeltaMoveTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, RADIUS * 2, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleFrameRectangleHeightNotChangedAfterDeltaMoveTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    circle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().height, RADIUS * 2, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleAreaNotChangedAfterMoveToPointTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    double areaBeforeMove = circle.getArea();
    circle.move({POINT_X, POINT_Y});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBeforeMove, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleAreaNotChangedAfterDeltaMoveTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    double areaBeforeMove = circle.getArea();
    circle.move(DELTA_X, DELTA_Y);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBeforeMove, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleScaleTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);
    double areaBeforeScale = circle.getArea();
    circle.scale(SCALE_COEF);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBeforeScale * SCALE_COEF * SCALE_COEF, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(CircleNegativeRadiusTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Circle(NEGATIVE_PARAMETER, SHAPE_CENTER_X, SHAPE_CENTER_Y), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(CircleZeroRadiusTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Circle(ZERO_PARAMETER, SHAPE_CENTER_X, SHAPE_CENTER_Y), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(CirclePointNegativeRadiusTest)
  {
    BOOST_CHECK_THROW(shcherbinin::Circle(NEGATIVE_PARAMETER, {SHAPE_CENTER_X, SHAPE_CENTER_Y}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(CirclePointZeroRadiusText)
  {
    BOOST_CHECK_THROW(shcherbinin::Circle(ZERO_PARAMETER, {SHAPE_CENTER_X, SHAPE_CENTER_Y}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(CricleNegativeScaleCoefTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);

    BOOST_CHECK_THROW(circle.scale(NEGATIVE_PARAMETER), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(CircleZeroScaleCoefTest)
  {
    shcherbinin::Circle circle = shcherbinin::Circle(RADIUS, SHAPE_CENTER_X, SHAPE_CENTER_Y);

    BOOST_CHECK_THROW(circle.scale(ZERO_PARAMETER), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
