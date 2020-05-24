#define BOOST_TEST_MODULE TEST_A3
#include <stdexcept>
#include <memory>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

const double EPSILON = 1e-6;

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(NegativeParametersToConstructor)
{
  BOOST_CHECK_THROW(talipova::Rectangle invalidWidthRect({ 0, 0 }, -1, 5), std::invalid_argument);
  BOOST_CHECK_THROW(talipova::Rectangle invalidHeightRect({ 0, 0 }, 1.1, -4.23), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroParametersToConstructor)
{
  BOOST_CHECK_THROW(talipova::Rectangle invalidZeroWidthRect({ 0, 0 }, 0, 2.32), std::invalid_argument);
  BOOST_CHECK_THROW(talipova::Rectangle invalidZeroHeightRect({ 0, 0 }, 1.1, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NegativeParametersToSecondConstructor)
{
  BOOST_CHECK_THROW(talipova::Rectangle invalidWidthRect(0, 0, -1, 5), std::invalid_argument);
  BOOST_CHECK_THROW(talipova::Rectangle invalidHeightRect(0, 0, 1.1, -4.23), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroParametersToSecondConstructor)
{
  BOOST_CHECK_THROW(talipova::Rectangle invalidZeroWidthRect(0, 0, 0, 2.32), std::invalid_argument);
  BOOST_CHECK_THROW(talipova::Rectangle invalidZeroHeightRect(0, 0, 1.1, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ImmutabilityRectangleAfterMoveToPoint)
{
  talipova::Rectangle testRect({ -3.2, 3.2 }, 5.25, 4.432);
  talipova::rectangle_t frameRectBefore = testRect.getFrameRect();
  double areaBefore = testRect.getArea();
  testRect.move({ -4.32, 0.328 });
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(ImmutabilityRectangleAfterMoveOnAxes)
{
  talipova::Rectangle testRect(0.32, 4.32, 74.32, 34.22);
  talipova::rectangle_t frameRectBefore = testRect.getFrameRect();
  double areaBefore = testRect.getArea();
  testRect.move(5.34, -4.045);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(NegativeCoefficientForScale)
{
  talipova::Rectangle testRect({ 3, 4 }, 3.45, 65.3);
  BOOST_CHECK_THROW(testRect.scale(-4.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroCoefficientForScale)
{
  talipova::Rectangle testRect({ 3, 4 }, 3.45, 65.3);
  BOOST_CHECK_THROW(testRect.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectAreaAfterScale)
{
  talipova::Rectangle testRect({ 3.3, 5.0 }, 32.4, 67.3);
  double areaBefore = testRect.getArea();
  double coeff = 3.4;
  testRect.scale(coeff);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaBefore * coeff * coeff, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeParametersAfterScale)
{
  talipova::Rectangle testRect({ 0.34, -3.4 }, 32, 54.3);
  talipova::rectangle_t frameRectBefore = testRect.getFrameRect();
  double coeff = 4.5;
  testRect.scale(coeff);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().width, frameRectBefore.width * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().height, frameRectBefore.height * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().pos.x, frameRectBefore.pos.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().pos.y, frameRectBefore.pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveToPoint)
{
  talipova::Rectangle testRect({ 0.34, -3.4 }, 32, 54.3);
  talipova::point_t newCentre = { 4.3, 54.33 };
  testRect.move(newCentre);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getPosition().x, newCentre.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getPosition().y, newCentre.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveOnAxes)
{
  talipova::Rectangle testRect({ 0.34, -3.4 }, 32, 54.3);
  talipova::point_t centreBefore = testRect.getFrameRect().pos;
  double dx = 9.45;
  double dy = -4.234;
  testRect.move(dx, dy);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getPosition().x, centreBefore.x + dx, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getPosition().y, centreBefore.y + dy, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(NegativeRadiusToConstructor)
{
  BOOST_CHECK_THROW(talipova::Circle invalidRadiusCirc({ -2.3, 2.3 }, -2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroRadiusToConstructor)
{
  BOOST_CHECK_THROW(talipova::Circle zeroRadiusCirc({ -2.3, 2.3 }, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NegativeRadiusToSecondConstructor)
{
  BOOST_CHECK_THROW(talipova::Circle invalidRadiusCirc(-2.3, 2.3, -2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroRadiusToSecondConstructor)
{
  BOOST_CHECK_THROW(talipova::Circle zeroRadiusCirc(-2.3, 2.3, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ImmutabilityCircleAfterMoveToPoint)
{
  talipova::Circle testCirc({ 23.32, 2.87 }, 45.345);
  talipova::rectangle_t frameRectBefore = testCirc.getFrameRect();
  double areaBefore = testCirc.getArea();
  testCirc.move({ 4.02, -4.23 });
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(ImmutabilityCircleAfterMoveOnAxes)
{
  talipova::Circle testCirc(23.4, -45.9, 34.5);
  talipova::rectangle_t frameRectBefore = testCirc.getFrameRect();
  double areaBefore = testCirc.getArea();
  testCirc.move(-54.32, 3.42);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(NegativeCoefficientForScale)
{
  talipova::Circle testCirc({ 3.4, -45.6 }, 43.54);
  BOOST_CHECK_THROW(testCirc.scale(-4.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroCoefficientForScale)
{
  talipova::Circle testCirc({ 3.4, -45.6 }, 43.54);
  BOOST_CHECK_THROW(testCirc.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectAreaAfterScale)
{
  talipova::Circle testCirc({ -2, 4 }, 54.32);
  double areaBefore = testCirc.getArea();
  double coeff = 0.4;
  testCirc.scale(coeff);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getArea(), areaBefore * coeff * coeff, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeParametersAfterScale)
{
  talipova::Circle testCirc({ 4, -43.4 }, 345.32);
  talipova::rectangle_t frameRectBefore = testCirc.getFrameRect();
  double coeff = 0.85;
  testCirc.scale(coeff);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().width, frameRectBefore.width * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().height, frameRectBefore.height * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().pos.x, frameRectBefore.pos.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().pos.y, frameRectBefore.pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveToPoint)
{
  talipova::Circle testCirc({ 0.34, -3.4 }, 32);
  talipova::point_t newCentre = { 4.3, 54.33 };
  testCirc.move(newCentre);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getPosition().x, newCentre.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getPosition().y, newCentre.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveOnAxes)
{
  talipova::Circle testCirc({ 34.543, -65.32 }, 32);
  talipova::point_t centreBefore = testCirc.getFrameRect().pos;
  double dx = -34.4;
  double dy = 24.958;
  testCirc.move(dx, dy);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getPosition().x, centreBefore.x + dx, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getPosition().y, centreBefore.y + dy, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCompositeShape)

BOOST_AUTO_TEST_CASE(CorrectSizeToConstructor)
{
  BOOST_CHECK_NO_THROW(talipova::CompositeShape correctSize(0));
  BOOST_CHECK_NO_THROW(talipova::CompositeShape correctSize(3));
}

BOOST_AUTO_TEST_CASE(CorrectComparisonOFTwoCS)
{
  talipova::CompositeShape shapes;
  talipova::CompositeShape shapes2;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  shapes2.addShape(rectangle1);
  shapes2.addShape(rectangle2);
  shapes2.addShape(circle1);
  BOOST_CHECK_MESSAGE(shapes == shapes2, "Comparison does not work");
  shapes2.deleteShape(0);
  BOOST_CHECK_MESSAGE(shapes != shapes2, "Comparison does not work");
}

BOOST_AUTO_TEST_CASE(EqualityOfTwoCSAfterCopyConstructor)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  talipova::CompositeShape copyShapes(shapes);
  BOOST_CHECK_MESSAGE(shapes == copyShapes, "Objects are not equal");
}

BOOST_AUTO_TEST_CASE(CorrectCopyAssignmentOperation)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  talipova::CompositeShape copyShapes;
  copyShapes = shapes;
  BOOST_CHECK_MESSAGE(shapes == copyShapes, "Objects are not equal");
}

BOOST_AUTO_TEST_CASE(InvalidIndexForGetShape)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  BOOST_CHECK_THROW(shapes[-1], std::out_of_range);
  BOOST_CHECK_THROW(shapes[3], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(InvalidIndexForAddingShape)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  BOOST_CHECK_THROW(shapes.addShape(rectangle, -1), std::out_of_range);
  BOOST_CHECK_THROW(shapes.addShape(rectangle, 1), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(ErrorAddCompositeShapeToItsef)
{
  std::shared_ptr<talipova::CompositeShape> pShapes = std::make_shared<talipova::CompositeShape>();
  BOOST_CHECK_THROW(pShapes->addShape(pShapes), std::logic_error);
}

BOOST_AUTO_TEST_CASE(CorrectAddingShapesToTheEnd)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  BOOST_CHECK_EQUAL(shapes.getSize(), 3);
  BOOST_CHECK_EQUAL(shapes[0], rectangle1);
  BOOST_CHECK_EQUAL(shapes[1], rectangle2);
  BOOST_CHECK_EQUAL(shapes[2], circle1);
}

BOOST_AUTO_TEST_CASE(CorrectAddingShapesByIndex)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1, 0);
  shapes.addShape(rectangle2, 0);
  shapes.addShape(circle1, 1);
  BOOST_CHECK_EQUAL(shapes.getSize(), 3);
  BOOST_CHECK_EQUAL(shapes[0], rectangle2);
  BOOST_CHECK_EQUAL(shapes[1], circle1);
  BOOST_CHECK_EQUAL(shapes[2], rectangle1);
}

BOOST_AUTO_TEST_CASE(ErrorAddNullShapePtr)
{
  talipova::CompositeShape shapes;
  BOOST_CHECK_THROW(shapes.addShape(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(shapes.addShape(nullptr, 1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ErrorDeleteNullShapePtr)
{
  talipova::CompositeShape shapes;
  BOOST_CHECK_THROW(shapes.deleteShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectDeletingShapeByIndex)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  shapes.deleteShape(1);
  shapes.deleteShape(0);
  BOOST_CHECK_EQUAL(shapes.getSize(), 1);
  BOOST_CHECK_EQUAL(shapes[0], circle1);
}

BOOST_AUTO_TEST_CASE(ErrorDeleteByInvalidIndex)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  shapes.addShape(rectangle1);
  BOOST_CHECK_THROW(shapes.deleteShape(1), std::out_of_range);
  BOOST_CHECK_THROW(shapes.deleteShape(3), std::out_of_range);
  BOOST_CHECK_THROW(shapes.deleteShape(-1), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(CorrectDeletingShape)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  shapes.deleteShape(rectangle2);
  shapes.deleteShape(shapes[0]);
  BOOST_CHECK_EQUAL(shapes.getSize(), 1);
  BOOST_CHECK_EQUAL(shapes[0], circle1);
}

BOOST_AUTO_TEST_CASE(ImmutabilityCSAfterDeleteShapeThatIsNot)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.deleteShape(circle1);
  BOOST_CHECK_EQUAL(shapes.getSize(), 2);
  BOOST_CHECK_EQUAL(shapes[0], rectangle1);
  BOOST_CHECK_EQUAL(shapes[1], rectangle2);
}

BOOST_AUTO_TEST_CASE(ErrorDeleteFromEmptyCompositeShape)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  BOOST_CHECK_THROW(shapes.deleteShape(0), std::logic_error);
}

BOOST_AUTO_TEST_CASE(CorrecFrameRectangle)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(-3, 2, 4, 8);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(8, -2, 4, 4);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(8, 4, 2);
  std::shared_ptr<talipova::Shape> circle2 = std::make_shared<talipova::Circle>(3, 1, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  shapes.addShape(circle2);
  talipova::rectangle_t frameRect = shapes.getFrameRect();
  BOOST_CHECK_CLOSE_FRACTION(frameRect.pos.x, 2.5, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRect.pos.y, 1, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRect.width, 15, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRect.height, 10, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectCalculateArea)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  double totalArea = rectangle1->getArea();
  totalArea += rectangle2->getArea();
  totalArea += circle1->getArea();
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  BOOST_CHECK_CLOSE_FRACTION(shapes.getArea(), totalArea, EPSILON);
  shapes.deleteShape(rectangle1);
  totalArea -= rectangle1->getArea();
  BOOST_CHECK_CLOSE_FRACTION(shapes.getArea(), totalArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectMoveToPoint)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  talipova::rectangle_t frameRectBefore = shapes.getFrameRect();
  double areaBefore = shapes.getArea();
  talipova::point_t newCenter = { 3, -8.2 };
  shapes.move(newCenter);
  talipova::rectangle_t frameRectAfter = shapes.getFrameRect();
  BOOST_CHECK_CLOSE_FRACTION(shapes.getArea(), areaBefore, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.x, newCenter.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.y, newCenter.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectMoveOnAxes)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  talipova::rectangle_t frameRectBefore = shapes.getFrameRect();
  double areaBefore = shapes.getArea();
  double dx = -3.2;
  double dy = 2.32;
  shapes.move(dx, dy);
  talipova::rectangle_t frameRectAfter = shapes.getFrameRect();
  BOOST_CHECK_CLOSE_FRACTION(shapes.getArea(), areaBefore, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.x, frameRectBefore.pos.x + dx, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.y, frameRectBefore.pos.y + dy, EPSILON);
}


BOOST_AUTO_TEST_CASE(InvalidCoefficientForScale)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  BOOST_CHECK_THROW(shapes.scale(-4.5), std::invalid_argument);
  BOOST_CHECK_THROW(shapes.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectScaleIncrease)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  talipova::rectangle_t frameRectBefore = shapes.getFrameRect();
  double areaBefore = shapes.getArea();
  double coeff = 0.5;
  shapes.scale(coeff);
  talipova::rectangle_t frameRectAfter = shapes.getFrameRect();
  BOOST_CHECK_CLOSE_FRACTION(shapes.getArea(), areaBefore * coeff * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.width, frameRectBefore.width * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.height, frameRectBefore.height * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.x, frameRectBefore.pos.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.y, frameRectBefore.pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectScaleReduce)
{
  talipova::CompositeShape shapes;
  std::shared_ptr<talipova::Shape> rectangle1 = std::make_shared<talipova::Rectangle>(6, 8, 4, 4);
  std::shared_ptr<talipova::Shape> rectangle2 = std::make_shared<talipova::Rectangle>(-5, 0, 8, 12);
  std::shared_ptr<talipova::Shape> circle1 = std::make_shared<talipova::Circle>(-2, -4, 3);
  shapes.addShape(rectangle1);
  shapes.addShape(rectangle2);
  shapes.addShape(circle1);
  talipova::rectangle_t frameRectBefore = shapes.getFrameRect();
  double areaBefore = shapes.getArea();
  double coeff = 3;
  shapes.scale(coeff);
  talipova::rectangle_t frameRectAfter = shapes.getFrameRect();
  BOOST_CHECK_CLOSE_FRACTION(shapes.getArea(), areaBefore * coeff * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.width, frameRectBefore.width * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.height, frameRectBefore.height * coeff, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.x, frameRectBefore.pos.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(frameRectAfter.pos.y, frameRectBefore.pos.y, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
