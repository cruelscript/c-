#define BOOST_TEST_MODULE LAB_A2_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"

const double ACCURACY = 1e-6;
const double DELTA_X = 5.;
const double DELTA_Y = 5.;
const double TO_X = 5.0;
const double TO_Y = 5.0;
const double WIDTH = 10.;
const double HEIGHT = 10.;
const double RADIUS = 10.;
const double POINT_X = 1.5;
const double POINT_Y = 1.5;
const double SCALE = 5.;
const double WRONG_PARAMETER = -1.;
const double ZERO_PARAMETER = 0.;

BOOST_AUTO_TEST_SUITE(TestsForRectangle)
  
  BOOST_AUTO_TEST_CASE(TestMoveRectangle)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    rectangle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, TO_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, TO_Y, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestDeltaMoveRectangle)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    rectangle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, POINT_X + DELTA_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, POINT_Y + DELTA_Y, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityWidthAfterMove)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    rectangle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().width, WIDTH, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityHeightAfterMove)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    rectangle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().height, HEIGHT, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityWidthAfterDeltaMove)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    rectangle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().width, WIDTH, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityHeightAfterDeltaMove)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    rectangle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().height, HEIGHT, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityAreaOfRectangleAfterMove)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    const double areaBeforeMove = rectangle.getArea();
    rectangle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBeforeMove, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityAreaOfRectangleAfterDeltaMove)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    const double areaBeforeDeltaMove = rectangle.getArea();
    rectangle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBeforeDeltaMove, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestScaleArea)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    const double areaBeforeScale = rectangle.getArea();
    rectangle.scale(SCALE);
    
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBeforeScale * SCALE * SCALE, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionWrongScale)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    
    BOOST_CHECK_THROW(rectangle.scale(-SCALE), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroScale)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    
    BOOST_CHECK_THROW(rectangle.scale(ZERO_PARAMETER), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidWidth)
  {
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(WRONG_PARAMETER, HEIGHT, POINT_X, POINT_Y), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroWidth)
  {
    gulyaev::Rectangle rectangle(WIDTH, HEIGHT, POINT_X, POINT_Y);
    
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(ZERO_PARAMETER, HEIGHT, POINT_X, POINT_Y), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidHeight)
  {
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(WIDTH, WRONG_PARAMETER, POINT_X, POINT_Y), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroHeight)
  {
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(ZERO_PARAMETER, WRONG_PARAMETER, POINT_X, POINT_Y),
      std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidWidthPoint)
  {
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(WRONG_PARAMETER, HEIGHT, {POINT_X, POINT_Y}), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroWidthPoint)
  {
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(ZERO_PARAMETER, HEIGHT, {POINT_X, POINT_Y}), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidHeightPoint)
  {
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(WIDTH, WRONG_PARAMETER, {POINT_X, POINT_Y}), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroHeightPoint)
  {
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(WIDTH, ZERO_PARAMETER, {POINT_X, POINT_Y}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestsForCircle)
  
  BOOST_AUTO_TEST_CASE(TestMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, TO_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, TO_Y, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestDeltaMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, POINT_X + DELTA_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, POINT_Y + DELTA_Y, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityRadiusAfterMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width / 2, RADIUS, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityRadiusAfterDeltaMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width / 2, RADIUS, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityWidthAfterMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, RADIUS * 2, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityHeightAfterMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().height, RADIUS * 2, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityWidthAfterDeltaMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, RADIUS * 2, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityHeightAfterDeltaMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    circle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, RADIUS * 2, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityAreaOfCircleAfterMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    const double areaBeforeMove = circle.getArea();
    circle.move({TO_X, TO_Y});
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBeforeMove, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityAreaOfCircleDeltaMove)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    const double areaBeforeDeltaMove = circle.getArea();
    circle.move(DELTA_X, DELTA_Y);
    
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBeforeDeltaMove, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestScaleArea)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    const double areaBeforeScale = circle.getArea();
    circle.scale(SCALE);
    
    BOOST_REQUIRE_CLOSE_FRACTION(areaBeforeScale * SCALE * SCALE, circle.getArea(), ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidScale)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    
    BOOST_CHECK_THROW(circle.scale(-SCALE), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroScale)
  {
    gulyaev::Circle circle(RADIUS, POINT_X, POINT_Y);
    
    BOOST_CHECK_THROW(circle.scale(ZERO_PARAMETER), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidRadiusParameterXAndY)
  {
    BOOST_CHECK_THROW(gulyaev::Circle circle(WRONG_PARAMETER, POINT_X, POINT_Y), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroRadiusParametersXAndY)
  {
    BOOST_CHECK_THROW(gulyaev::Circle circle(ZERO_PARAMETER, POINT_X, POINT_Y), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidRadiusParametersPoint)
  {
    BOOST_CHECK_THROW(gulyaev::Circle circle(WRONG_PARAMETER, {POINT_X, POINT_Y}), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionZeroRadiusParametersPoint)
  {
    BOOST_CHECK_THROW(gulyaev::Circle circle(ZERO_PARAMETER, {POINT_X, POINT_Y}), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
