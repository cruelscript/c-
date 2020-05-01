#define BOOST_TEST_MODULE TEST_A2
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"
#include "base-types.hpp"

const double EPSILON = 1e-6;

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(NegativeParametersRectanglesInConstr)
{
  BOOST_CHECK_THROW(talipova::Rectangle invalidWidthRect({ 0, 0 }, -1, 5), std::invalid_argument);
  BOOST_CHECK_THROW(talipova::Rectangle invalidHeightRect({ 0, 0 }, 1.1, -4.23), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroParametersRectanglesInConstr)
{
  BOOST_CHECK_THROW(talipova::Rectangle invalidZeroWidthRect({ 0, 0 }, 0, 2.32), std::invalid_argument);
  BOOST_CHECK_THROW(talipova::Rectangle invalidZeroHeightRect({ 0, 0 }, 1.1, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NegativeParametersRectanglesInConstrTwo)
{
  BOOST_CHECK_THROW(talipova::Rectangle invalidWidthRect(0, 0, -1, 5), std::invalid_argument);
  BOOST_CHECK_THROW(talipova::Rectangle invalidHeightRect(0, 0, 1.1, -4.23), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroParametersRectanglesInConstrTwo)
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

BOOST_AUTO_TEST_CASE(ImmutabilityRectangleAfterMoveDelta)
{
  talipova::Rectangle testRect(0.32, 4.32, 74.32, 34.22);
  talipova::rectangle_t frameRectBefore = testRect.getFrameRect();
  double areaBefore = testRect.getArea();
  testRect.move(5.34, -4.045);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getFrameRect().height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(NegativeCoefficientForScaleRect)
{
  talipova::Rectangle testRect({ 3, 4 }, 3.45, 65.3);
  BOOST_CHECK_THROW(testRect.scale(-4.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroCoefficientForScaleRect)
{
  talipova::Rectangle testRect({ 3, 4 }, 3.45, 65.3);
  BOOST_CHECK_THROW(testRect.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectRectAreaAfterScale)
{
  talipova::Rectangle testRect({ 3.3, 5.0 }, 32.4, 67.3);
  double areaBefore = testRect.getArea();
  double coeff = 3.4;
  testRect.scale(coeff);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getArea(), areaBefore * coeff * coeff, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeParametersAfterScaleForRect)
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

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveToPointForRect)
{
  talipova::Rectangle testRect({ 0.34, -3.4 }, 32, 54.3);
  talipova::point_t newCentre = { 4.3, 54.33 };
  testRect.move(newCentre);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getPosition().x, newCentre.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testRect.getPosition().y, newCentre.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveDeltaForRect)
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

BOOST_AUTO_TEST_CASE(NegativeRadiusCirclesInConstr)
{
  BOOST_CHECK_THROW(talipova::Circle invalidRadiusCirc({ -2.3, 2.3 }, -2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroRadiusCirclesInConstr)
{
  BOOST_CHECK_THROW(talipova::Circle zeroRadiusCirc({ -2.3, 2.3 }, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NegativeRadiusCirclesInConstrTwo)
{
  BOOST_CHECK_THROW(talipova::Circle invalidRadiusCirc(-2.3, 2.3, -2.2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroRadiusCirclesInConstrTwo)
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

BOOST_AUTO_TEST_CASE(ImmutabilityCircleAfterMoveDelta)
{
  talipova::Circle testCirc(23.4, -45.9, 34.5);
  talipova::rectangle_t frameRectBefore = testCirc.getFrameRect();
  double areaBefore = testCirc.getArea();
  testCirc.move(-54.32, 3.42);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getFrameRect().height, frameRectBefore.height, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(NegativeCoefficientForScaleCirc)
{
  talipova::Circle testCirc({ 3.4, -45.6 }, 43.54);
  BOOST_CHECK_THROW(testCirc.scale(-4.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(ZeroCoefficientForScaleCirc)
{
  talipova::Circle testCirc({ 3.4, -45.6 }, 43.54);
  BOOST_CHECK_THROW(testCirc.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CorrectCircAreaAfterScale)
{
  talipova::Circle testCirc({ -2, 4 }, 54.32);
  double areaBefore = testCirc.getArea();
  double coeff = 0.4;
  testCirc.scale(coeff);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getArea(), areaBefore * coeff * coeff, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeParametersAfterScaleForCirc)
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

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveToPointForCirc)
{
  talipova::Circle testCirc({ 0.34, -3.4 }, 32);
  talipova::point_t newCentre = { 4.3, 54.33 };
  testCirc.move(newCentre);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getPosition().x, newCentre.x, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(testCirc.getPosition().y, newCentre.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(CorrectChangeCentreAfterMoveDeltaForCirc)
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
