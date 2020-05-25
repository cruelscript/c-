#define BOOST_TEST_MODULE LAB_A3_TEST

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

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
    BOOST_CHECK_THROW(gulyaev::Rectangle rectangle(ZERO_PARAMETER, WRONG_PARAMETER, POINT_X, POINT_Y), std::invalid_argument);
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











BOOST_AUTO_TEST_SUITE(TestCompositeShape)
  
  BOOST_AUTO_TEST_CASE(TestConstructorDefaultNoThrow)
  {
    BOOST_CHECK_NO_THROW(gulyaev::CompositeShape compositeShape());
  }
  
  BOOST_AUTO_TEST_CASE(TestConstructorElementNoThrow)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    BOOST_CHECK_NO_THROW(gulyaev::CompositeShape compositeShape(circle));
  }
  
  BOOST_AUTO_TEST_CASE(TestCopyConstructorNoThrow)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape current(circle);
    BOOST_CHECK_NO_THROW(gulyaev::CompositeShape compositeShape(current));
  }
  
  BOOST_AUTO_TEST_CASE(TestMoveConstructorNoThrow)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape current(circle);
    BOOST_CHECK_NO_THROW(gulyaev::CompositeShape compositeShape(std::move(current)));
  }
  
  BOOST_AUTO_TEST_CASE(TestSizeAfterInsertShape)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, 1.5, 1.5);
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, 1.5, 1.5);
    compositeShape.add(rectangle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle2);
    BOOST_CHECK_EQUAL(compositeShape.getSize(), 4);
  }
  BOOST_AUTO_TEST_CASE(TestDeleteShape)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(rectangle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle2);
    double area = compositeShape.getArea();
    area -= compositeShape[3]->getArea();
    compositeShape.remove();
    BOOST_CHECK_EQUAL(compositeShape.getSize(), 3);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getArea(), area, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionOutOfRange)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.remove();
    BOOST_CHECK_THROW(compositeShape.remove(), std::out_of_range);
  }
  
  BOOST_AUTO_TEST_CASE(TestClear)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(rectangle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle2);
    compositeShape.clear();
    BOOST_CHECK_EQUAL(compositeShape.getSize(), 0);
  }
  
  BOOST_AUTO_TEST_CASE(TestMove)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    compositeShape.move({TO_X, TO_Y});
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.x, TO_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.y, TO_Y, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestDeltaMove)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    double x = compositeShape.getFrameRect().pos.x;
    double y = compositeShape.getFrameRect().pos.y;
    compositeShape.move(DELTA_X, DELTA_Y);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.x, x + DELTA_X, ACCURACY);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.y, y + DELTA_Y, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestArea)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    double area = 0.;
    area += circle->getArea();
    area += circle2->getArea();
    area += rectangle->getArea();
    area += rectangle2->getArea();
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getArea(), area, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityAreaAfterMove)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    double area = 0.;
    area += circle->getArea();
    area += circle2->getArea();
    area += rectangle->getArea();
    area += rectangle2->getArea();
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    compositeShape.move({TO_X, TO_Y});
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getArea(), area, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestImmutabilityAreaAfterDeltaMove)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    double area = 0.;
    area += circle->getArea();
    area += circle2->getArea();
    area += rectangle->getArea();
    area += rectangle2->getArea();
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    compositeShape.move(DELTA_X, DELTA_Y);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getArea(), area, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestScale)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    double area = compositeShape.getArea();
    compositeShape.scale(SCALE);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getArea(), area * SCALE * SCALE, ACCURACY);
  }
  
  BOOST_AUTO_TEST_CASE(TestExceptionInvalidScale)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    BOOST_CHECK_THROW(compositeShape.scale(-SCALE), std::invalid_argument);
  }
  BOOST_AUTO_TEST_CASE(TestExceptionZeroScale)
  {
    std::shared_ptr<gulyaev::Shape> circle2 = std::make_shared<gulyaev::Circle>(5, 15, 15);
    std::shared_ptr<gulyaev::Shape> rectangle = std::make_shared<gulyaev::Rectangle>(5, 5, -10, -10);
    std::shared_ptr<gulyaev::Shape> rectangle2 = std::make_shared<gulyaev::Rectangle>(5, 5, -30, -20);
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    compositeShape.add(circle2);
    compositeShape.add(rectangle);
    compositeShape.add(rectangle2);
    BOOST_CHECK_THROW(compositeShape.scale(ZERO_PARAMETER), std::invalid_argument);
  }
  
  BOOST_AUTO_TEST_CASE(TestInsertNullPointerShape)
  {
    std::shared_ptr<gulyaev::Shape> circle = nullptr;
    BOOST_CHECK_THROW(gulyaev::CompositeShape compositeShape(circle), std::invalid_argument);
  }
  
  
  
  
  
  
  
  
  BOOST_AUTO_TEST_CASE(TestAddCompositeShapeNoThrow)
  {
    std::shared_ptr<gulyaev::Shape> circle = std::make_shared<gulyaev::Circle>(5, 1.5, 1.5);
    gulyaev::CompositeShape compositeShape(circle);
    std::shared_ptr<gulyaev::Shape> com = std::make_shared<gulyaev::CompositeShape>(compositeShape);
    BOOST_CHECK_NO_THROW(compositeShape.add(com));
  }
  
  
  
  

BOOST_AUTO_TEST_SUITE_END()










BOOST_AUTO_TEST_SUITE(TestDynamicArray)
  
  BOOST_AUTO_TEST_CASE(TestDefaultConstructorNoThrow)
  {
    BOOST_CHECK_NO_THROW(gulyaev::detail::DynamicArray<int> dynamicArray());
  }
  
  BOOST_AUTO_TEST_CASE(TestConstructorSizeNoThrow)
  {
    BOOST_CHECK_NO_THROW(gulyaev::detail::DynamicArray<int> dynamicArray(100));
  }
  
  BOOST_AUTO_TEST_CASE(TestCopyConstructorNoThrow)
  {
    gulyaev::detail::DynamicArray<int> dynamicArray1(100);
    BOOST_CHECK_NO_THROW(gulyaev::detail::DynamicArray<int> dynamicArray2(dynamicArray1));
  }
  
  BOOST_AUTO_TEST_CASE(TestMoveConstructorNoThrow)
  {
    gulyaev::detail::DynamicArray<int> dynamicArray1(100);
    BOOST_CHECK_NO_THROW(gulyaev::detail::DynamicArray<int> dynamicArray2(std::move(dynamicArray1)));
  }
  
  BOOST_AUTO_TEST_CASE(TestAddingElements)
  {
    gulyaev::detail::DynamicArray<int> dynamicArray(100);
    dynamicArray.add(5);
    dynamicArray.add(6);
    BOOST_CHECK_EQUAL(dynamicArray.getAmount(), 2);
  }
  
  BOOST_AUTO_TEST_CASE(TestRemoveOutOfRangeThrow)
  {
    gulyaev::detail::DynamicArray<int> dynamicArray(100);
    dynamicArray.add(5);
    dynamicArray.add(6);
    dynamicArray.remove();
    dynamicArray.remove();
    BOOST_CHECK_THROW(dynamicArray.remove(), std::out_of_range);
  }
BOOST_AUTO_TEST_SUITE_END()
