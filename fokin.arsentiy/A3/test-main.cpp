#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <stdexcept>
#include <memory>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double EPSILON = 0.0001;

BOOST_AUTO_TEST_SUITE(RectangleTests)

BOOST_AUTO_TEST_CASE(RectangleCreatingWithInvalidWidth)
{
  BOOST_CHECK_THROW(fokin::Rectangle testRectangle(-4.0, 5.0, { 2.6, -1.4 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleCreatingWithInvalidHeight)
{
  BOOST_CHECK_THROW(fokin::Rectangle testRectangle(4.0, -5.0, { 2.6, -1.4 }), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleImmutabilityAfterMovingToPoint)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialWidth = testRectangle.getFrameRect().width;
  double initialHeight = testRectangle.getFrameRect().height;

  double newX = -5.1;
  double newY = 9.7;

  testRectangle.move({ newX, newY });

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().width, initialWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().height, initialHeight, EPSILON);
}

BOOST_AUTO_TEST_CASE(RectangleCorrectCenterAndAreaAfterMovingToPoint)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialArea = testRectangle.getArea();

  double newX = -5.1;
  double newY = 9.7;

  testRectangle.move({ newX, newY });

  BOOST_REQUIRE_CLOSE_FRACTION(testRectangle.getCenter().x, newX, EPSILON);
  BOOST_REQUIRE_CLOSE_FRACTION(testRectangle.getCenter().y, newY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(RectangleImmutabilityAfterShifting)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialFrameWidth = testRectangle.getFrameRect().width;
  double initialFrameHeight = testRectangle.getFrameRect().height;

  double dX = -5.1;
  double dY = 9.7;

  testRectangle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().width, initialFrameWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getFrameRect().height, initialFrameHeight, EPSILON);
}

BOOST_AUTO_TEST_CASE(RectangleCorrectCenterAndAreaAfterShifting)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialX = testRectangle.getCenter().x;
  double initialY = testRectangle.getCenter().y;

  double initialArea = testRectangle.getArea();

  double dX = -5.1;
  double dY = 9.7;

  testRectangle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getCenter().x, initialX + dX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getCenter().y, initialY + dY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(RectangleInvalidScaleCoefficient)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  BOOST_CHECK_THROW(testRectangle.scale(-2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RectangleCorrectCenterAndAreaAfterScaling)
{
  fokin::Rectangle testRectangle(4.0, 5.0, { 2.6, -1.4 });

  double initialX = testRectangle.getCenter().x;
  double initialY = testRectangle.getCenter().y;

  double initialArea = testRectangle.getArea();

  double coefficient = 2.7;
  testRectangle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getCenter().x, initialX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getCenter().y, initialY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testRectangle.getArea(), initialArea * coefficient * coefficient, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(CircleCreatingWithInvalidRadius)
{
  BOOST_CHECK_THROW(fokin::Circle testCircle({ 1.0, 0.0 }, -2.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleImmutabilityAfterMovingToPoint)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialFrameWidth = testCircle.getFrameRect().width;
  double initialFrameHeight = testCircle.getFrameRect().height;

  double newX = -5.1;
  double newY = 9.7;

  testCircle.move({ newX, newY });

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().width, initialFrameWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().height, initialFrameHeight, EPSILON);
}

BOOST_AUTO_TEST_CASE(CircleCorrectCenterAndAreaAfterMovingToPoint)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialArea = testCircle.getArea();

  double newX = -5.1;
  double newY = 9.7;

  testCircle.move({ newX, newY });

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getCenter().x, newX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getCenter().y, newY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(CircleImmutabilityAfterShifting)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialFrameWidth = testCircle.getFrameRect().width;
  double initialFrameHeight = testCircle.getFrameRect().height;

  double dX = -5.1;
  double dY = 9.7;

  testCircle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().width, initialFrameWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getFrameRect().height, initialFrameHeight, EPSILON);
}

BOOST_AUTO_TEST_CASE(CircleCorrectCenterAndAreaAfterShifting)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialX = testCircle.getCenter().x;
  double initialY = testCircle.getCenter().y;

  double initialArea = testCircle.getArea();

  double dX = -5.1;
  double dY = 9.7;

  testCircle.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getCenter().x, initialX + dX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getCenter().y, initialY + dY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(CircleInvalidScaleCoefficient)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  BOOST_CHECK_THROW(testCircle.scale(-2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CircleCorrectCenterAndAreaAfterScaling)
{
  fokin::Circle testCircle({ 1.0, 0.0 }, 2.0);

  double initialX = testCircle.getCenter().x;
  double initialY = testCircle.getCenter().y;

  double initialArea = testCircle.getArea();

  double coefficient = 2.7;
  testCircle.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getCenter().x, initialX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCircle.getCenter().y, initialY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCircle.getArea(), initialArea * coefficient * coefficient, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CompositeShapeTests)

BOOST_AUTO_TEST_CASE(CompositeShapePushingInvalidShape)
{
  std::shared_ptr<fokin::Shape> shape = nullptr;
  fokin::CompositeShape testCompositeShape;

  BOOST_CHECK_THROW(testCompositeShape.addShape(shape), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CompositeShapeImmutabilityAfterMovingToPoint)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  double initialWidth = testCompositeShape.getFrameRect().width;
  double initialHeight = testCompositeShape.getFrameRect().height;

  double newX = -5.1;
  double newY = 9.7;

  testCompositeShape.move({ newX, newY });

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getFrameRect().width, initialWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getFrameRect().height, initialHeight, EPSILON);
}

BOOST_AUTO_TEST_CASE(CompositeShapeCorrectCenterAndAreaAfterMovingToPoint)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  double initialArea = testCompositeShape.getArea();

  double newX = -5.1;
  double newY = 9.7;

  testCompositeShape.move({ newX, newY });

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getCenter().x, newX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getCenter().y, newY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(CompositeShapeImmutabilityAfterShifting)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  double initialFrameWidth = testCompositeShape.getFrameRect().width;
  double initialFrameHeight = testCompositeShape.getFrameRect().height;

  double dX = -5.1;
  double dY = 9.7;

  testCompositeShape.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getFrameRect().width, initialFrameWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getFrameRect().height, initialFrameHeight, EPSILON);
}

BOOST_AUTO_TEST_CASE(CompositeShapeCorrectCenterAndAreaAfterShifting)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  double initialX = testCompositeShape.getCenter().x;
  double initialY = testCompositeShape.getCenter().y;

  double initialArea = testCompositeShape.getArea();

  double dX = -5.1;
  double dY = 9.7;

  testCompositeShape.move(dX, dY);

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getCenter().x, initialX + dX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getCenter().y, initialY + dY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getArea(), initialArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(CompositeShapeInvalidScaleCoefficient)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  BOOST_CHECK_THROW(testCompositeShape.scale(-2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CompositeShapeCorrectCenterAndAreaAfterScaling)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  double initialX = testCompositeShape.getCenter().x;
  double initialY = testCompositeShape.getCenter().y;

  double initialArea = testCompositeShape.getArea();

  double coefficient = 2.7;
  testCompositeShape.scale(coefficient);

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getCenter().x, initialX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getCenter().y, initialY, EPSILON);

  BOOST_CHECK_CLOSE_FRACTION(testCompositeShape.getArea(), initialArea * coefficient * coefficient, EPSILON);
}

BOOST_AUTO_TEST_CASE(CompositeShapeInvalidIndex)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  BOOST_CHECK_THROW(testCompositeShape[-1], std::out_of_range);
  BOOST_CHECK_THROW(testCompositeShape[2], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(CompositeShapeAddNullptrShape)
{
  fokin::CompositeShape testCompositeShape;

  BOOST_CHECK_THROW(testCompositeShape.addShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CompositeShapeCorrectDeleting)
{
  std::shared_ptr<fokin::Shape> testCircle =
    std::make_shared<fokin::Circle>(fokin::point_t{ 1.0, 0.0 }, 2.0);

  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testCircle);
  testCompositeShape.addShape(testRectangle);

  testCompositeShape.removeShape();

  BOOST_CHECK_EQUAL(testCompositeShape.getCapacity(), 1);
  BOOST_CHECK_EQUAL(testCompositeShape[0], testCircle);
}

BOOST_AUTO_TEST_CASE(CompositeShapeDeletingFromEmptyCompositeShape)
{
  fokin::CompositeShape testCompositeShape;

  BOOST_CHECK_THROW(testCompositeShape.removeShape(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(CompositeShapeEqualityAfterCopyConstructor)
{
  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testRectangle);

  fokin::CompositeShape copyCompositeShape(testCompositeShape);

  BOOST_CHECK_MESSAGE(testCompositeShape[0] == copyCompositeShape[0], "Objects are not equal!");
}

BOOST_AUTO_TEST_CASE(CompositeShapeEqualityAfterMoveConstructor)
{
  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testRectangle);

  fokin::CompositeShape copyCompositeShape = testCompositeShape;

  BOOST_CHECK_MESSAGE(testCompositeShape[0] == copyCompositeShape[0], "Objects are not equal!");
}

BOOST_AUTO_TEST_CASE(CompositeShapeEqualityAfterCopyCopyAssignmentOperation)
{
  std::shared_ptr<fokin::Shape> testRectangle =
    std::make_shared<fokin::Rectangle>(4.0, 5.0, fokin::point_t{ 2.6, -1.4 });

  fokin::CompositeShape testCompositeShape;
  testCompositeShape.addShape(testRectangle);

  fokin::CompositeShape copyCompositeShape;
  copyCompositeShape = testCompositeShape;

  BOOST_CHECK_MESSAGE(testCompositeShape[0] == copyCompositeShape[0], "Objects are not equal!");
}

BOOST_AUTO_TEST_SUITE_END()
