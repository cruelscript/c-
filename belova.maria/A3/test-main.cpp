#define BOOST_TEST_MODULE UNIT_TESTS

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

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

  BOOST_CHECK_THROW(belova::Rectangle(0.0, 0.0, -18.1, 12.3), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle(0.0, 0.0, 18.1, -12.3), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle(0.0, 0.0, -18.1, -12.3), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle(0.0, 0.0, 0.0, 12.3), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle(0.0, 0.0, -18.1, 0.0), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Rectangle(0.0, 0.0, 0.0, 0.0), std::invalid_argument);
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

  BOOST_CHECK_THROW(belova::Circle(0.0, 0.0, -5.5), std::invalid_argument);
  BOOST_CHECK_THROW(belova::Circle(0.0, 0.0, 0.0), std::invalid_argument);
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

BOOST_AUTO_TEST_SUITE(TestCompositeShape)

BOOST_AUTO_TEST_CASE(testCompositeShapeCopyConstructor)
{
  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);

  belova::CompositeShape copyShape;
  copyShape.addShape(circle);

  BOOST_CHECK_NO_THROW(belova::CompositeShape testCompositeShape(copyShape));
}

BOOST_AUTO_TEST_CASE(testCompositeShapeCopyAssignmentOperator)
{
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);

  belova::CompositeShape copyShape;
  copyShape.addShape(rectangle);

  BOOST_CHECK_NO_THROW(belova::CompositeShape testCompositeShape = copyShape);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeInvalidIndex)
{
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(rectangle);

  BOOST_CHECK_THROW(compositeShape[1], std::out_of_range);
  BOOST_CHECK_THROW(compositeShape[4], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeSize)
{
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(rectangle);
  size_t sizeBefore = compositeShape.getSize();

  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);
  compositeShape.addShape(circle);
  size_t sizeAfter = compositeShape.getSize();

  BOOST_REQUIRE((sizeBefore * 2) == sizeAfter);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAmount)
{
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(rectangle);

  size_t amountBefore = compositeShape.getAmount();

  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);
  compositeShape.addShape(circle);

  size_t amountAfter = compositeShape.getAmount();

  BOOST_REQUIRE((amountBefore + 1) == amountAfter);

  compositeShape.deleteShape(0);
  amountAfter = compositeShape.getAmount();

  BOOST_REQUIRE(amountBefore == amountAfter);
}


BOOST_AUTO_TEST_CASE(testCompositeShapeAddNullShape)
{
  belova::CompositeShape compositeShape;

  BOOST_CHECK_THROW(compositeShape.addShape(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(compositeShape.addShape(nullptr, 1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAddByInvalidIndex)
{
  belova::CompositeShape compositeShape;
  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);

  BOOST_CHECK_THROW(compositeShape.addShape(circle, -1), std::out_of_range);
  BOOST_CHECK_THROW(compositeShape.addShape(circle, 2), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAddShape)
{
  belova::CompositeShape compositeShape;
  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);

  compositeShape.addShape(circle);
  compositeShape.addShape(rectangle);
  BOOST_CHECK_EQUAL(compositeShape.getAmount(), 2);
  BOOST_CHECK_EQUAL(compositeShape[0], circle);
  BOOST_CHECK_EQUAL(compositeShape[1], rectangle);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAddByIndex)
{
  belova::CompositeShape compositeShape;
  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);
  std::shared_ptr<belova::Shape> rect = std::make_shared<belova::Rectangle>(0.0, 0.3, 3.4, 5.0);

  compositeShape.addShape(circle, 0);
  compositeShape.addShape(rectangle, 1);
  compositeShape.addShape(rect, 1);
  BOOST_CHECK_EQUAL(compositeShape.getAmount(), 3);
  BOOST_CHECK_EQUAL(compositeShape[0], circle);
  BOOST_CHECK_EQUAL(compositeShape[1], rect);
  BOOST_CHECK_EQUAL(compositeShape[2], rectangle);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeDeleteShapeFromEmptyCompositeShape)
{
  belova::CompositeShape compositeShape;

  BOOST_CHECK_THROW(compositeShape.deleteShape(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeDeleteShapeByInvalidIndex)
{
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(rectangle);

  BOOST_REQUIRE(compositeShape.getAmount() > 0);
  BOOST_CHECK_THROW(compositeShape.deleteShape(-4), std::out_of_range);
  BOOST_CHECK_THROW(compositeShape.deleteShape(4), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeDeleteShape)
{
  belova::CompositeShape compositeShape;
  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);
  std::shared_ptr<belova::Shape> rect = std::make_shared<belova::Rectangle>(0.0, 0.3, 3.4, 5.0);

  compositeShape.addShape(circle);
  compositeShape.addShape(rectangle);
  compositeShape.addShape(rect);
  
  compositeShape.deleteShape();

  BOOST_CHECK_EQUAL(compositeShape.getAmount(), 2);
  BOOST_CHECK_EQUAL(compositeShape[0], circle);
  BOOST_CHECK_EQUAL(compositeShape[1], rectangle);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeDeleteByIndex)
{
  belova::CompositeShape compositeShape;
  std::shared_ptr<belova::Shape> circle = std::make_shared<belova::Circle>(6.7, 2.3, 5.0);
  std::shared_ptr<belova::Shape> rectangle = std::make_shared<belova::Rectangle>(0.0, 2.3, 5.4, 45.0);
  std::shared_ptr<belova::Shape> rect = std::make_shared<belova::Rectangle>(0.0, 0.3, 3.4, 5.0);

  compositeShape.addShape(circle, 0);
  compositeShape.addShape(rectangle, 1);
  compositeShape.addShape(rect, 1);

  compositeShape.deleteShape(1);

  BOOST_CHECK_EQUAL(compositeShape.getAmount(), 2);
  BOOST_CHECK_EQUAL(compositeShape[0], circle);
  BOOST_CHECK_EQUAL(compositeShape[1], rectangle);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeSidesAfterPointMove)
{
  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(6.7, 2.3, 3.2, 5.2);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Rectangle>(1.3, 0.0, 9.1, 9.1);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second);

  belova::rectangle_t rectBefore = compositeShape.getFrameRect();
  compositeShape.move({ 3.4, 12.2 });

  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().pos.x, 3.4, TOLERANCE);
  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().pos.y, 12.2, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.height, compositeShape.getFrameRect().height, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.width, compositeShape.getFrameRect().width, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAreaAfterPointMove)
{
  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(0.0, 0.0, 5.2, 3.0);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Rectangle>(13.2, 0.0, 10.1, 10.1);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second);

  double areaBefore = compositeShape.getArea();
  compositeShape.move({ 5.0, 1.2 });

  BOOST_CHECK_CLOSE(areaBefore, compositeShape.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeSidesAfterDeltaMove)
{
  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(33.7, 33.3, 3.2, 5.2);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Rectangle>(23.3, 0.0, 2.1, 9.1);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second);

  belova::rectangle_t rectBefore = compositeShape.getFrameRect();
  belova::point_t center = rectBefore.pos;
  double deltaX = -3.4;
  double deltaY = 12.2;
  compositeShape.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().pos.x, center.x + deltaX, TOLERANCE);
  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().pos.y, center.y + deltaY, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.height, compositeShape.getFrameRect().height, TOLERANCE);
  BOOST_CHECK_CLOSE(rectBefore.width, compositeShape.getFrameRect().width, TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAreaAfterDeltaMove)
{
  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(0.0, 0.0, 5.2, 3.0);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Rectangle>(13.2, 0.0, 10.1, 10.1);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second);

  double areaBefore = compositeShape.getArea();
  compositeShape.move(-5.5, 24.0);

  BOOST_CHECK_CLOSE(areaBefore, compositeShape.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeArea)
{
  belova::Rectangle firstRect({ 0.0, 0.0 }, 5.2, 3.0);
  belova::Rectangle secondRect({ 13.2, 0.0 }, 10.1, 10.1);
  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(firstRect);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Rectangle>(secondRect);

  double firstArea = firstRect.getArea();
  double secondArea = secondRect.getArea();

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second);

  BOOST_REQUIRE(compositeShape.getAmount() > 0);
  BOOST_CHECK_CLOSE(firstArea + secondArea, compositeShape.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeInvalidScaleCoefficient)
{
  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(0.0, 0.0, 5.2, 3.0);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Rectangle>(13.2, 0.0, 10.1, 10.1);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second);

  BOOST_CHECK_THROW(compositeShape.scale(0.0), std::invalid_argument);
  BOOST_CHECK_THROW(compositeShape.scale(-3.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAreaAfterScaling)
{
  std::shared_ptr<belova::Shape> first = std::make_shared<belova::Rectangle>(0.0, 0.0, 5.2, 3.0);
  std::shared_ptr<belova::Shape> second = std::make_shared<belova::Rectangle>(13.2, 0.0, 10.1, 10.1);

  belova::CompositeShape compositeShape;
  compositeShape.addShape(first);
  compositeShape.addShape(second);

  double areaBefore = compositeShape.getArea();
  double scaleCoef = 2.0;
  compositeShape.scale(scaleCoef);

  BOOST_CHECK_CLOSE(areaBefore * scaleCoef * scaleCoef, compositeShape.getArea(), TOLERANCE);
}

BOOST_AUTO_TEST_SUITE_END()
