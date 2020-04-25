#define BOOST_TEST_MODULE UNIT_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

const double EXACTNESS = 1e-6;

BOOST_AUTO_TEST_SUITE(RectangleTests)

BOOST_AUTO_TEST_CASE(testRectangleSidesImmutabilityAfterMoveToPoint)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  double widthBefore = rectangle.getWidth();
  double heightBefore = rectangle.getHeight();
  dambieva::point_t newCenter = {7.0, 2.0};
  rectangle.move(newCenter);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getPos().x, newCenter.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getPos().y, newCenter.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getWidth(), widthBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getHeight(), heightBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleSidesImmutabilityAfterMove)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  dambieva::point_t centerBefore = rectangle.getPos();
  double widthBefore = rectangle.getWidth();
  double heightBefore = rectangle.getHeight();
  const double deltaX = 7.0;
  const double deltaY = 2.0;
  rectangle.move(deltaX, deltaY);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getPos().x, centerBefore.x + deltaX, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getPos().y, centerBefore.y + deltaY, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getWidth(), widthBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getHeight(), heightBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleSidesProportionalChangeAfterScale)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  dambieva::point_t centerBefore = rectangle.getPos();
  double widthBefore = rectangle.getWidth();
  double heightBefore = rectangle.getHeight();
  const double scaleIn = 3;
  rectangle.scale(scaleIn);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getPos().x, centerBefore.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getPos().y, centerBefore.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getWidth(), widthBefore * scaleIn, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getHeight(), heightBefore * scaleIn, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaImmutabilityAfterMoveToPoint)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  double areaBefore = rectangle.getArea();
  rectangle.move({7.0, 2.0});

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaImmutabilityAfterMove)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  double areaBefore = rectangle.getArea();
  rectangle.move(7.0, 2.0);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaProportionalChangeAfterScale)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  double areaBefore = rectangle.getArea();
  const double scaleIn = 3;
  rectangle.scale(scaleIn);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getArea(), areaBefore * scaleIn * scaleIn, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleFrameImmutabilityAfterMoveToPoint)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  double frameWidthBefore = rectangle.getFrameRect().width;
  double frameHeightBefore = rectangle.getFrameRect().height;
  dambieva::point_t newCenter = {7.0, 2.0};
  rectangle.move(newCenter);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, newCenter.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, newCenter.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().width, frameWidthBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().height, frameHeightBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleFrameImmutabilityAfterMove)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  dambieva::point_t centerBefore = rectangle.getPos();
  double frameWidthBefore = rectangle.getFrameRect().width;
  double frameHeightBefore = rectangle.getFrameRect().height;
  const double deltaX = 7.0;
  const double deltaY = 2.0;
  rectangle.move(deltaX, deltaY);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, centerBefore.x + deltaX, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, centerBefore.y + deltaY, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().width, frameWidthBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().height, frameHeightBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleFrameProportionalChangeAfterScale)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);

  dambieva::point_t centerBefore = rectangle.getPos();
  double frameWidthBefore = rectangle.getFrameRect().width;
  double frameHeightBefore = rectangle.getFrameRect().height;
  const double scaleIn = 3;
  rectangle.scale(scaleIn);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, centerBefore.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, centerBefore.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().width, frameWidthBefore * scaleIn, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().height, frameHeightBefore * scaleIn, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidWidth)
{
  BOOST_CHECK_THROW(dambieva::Rectangle(5.5, 5.5, -10.0, 20.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroWidth)
{
  BOOST_CHECK_THROW(dambieva::Rectangle(5.5, 5.5, 0.0, 20.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidHeight)
{
  BOOST_CHECK_THROW(dambieva::Rectangle(5.5, 5.5, 10.0, -20.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroHeight)
{
  BOOST_CHECK_THROW(dambieva::Rectangle(5.5, 5.5, 10.0, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleWithPointExceptionInvalidWidth)
{
  BOOST_CHECK_THROW(dambieva::Rectangle({5.5, 5.5}, -10.0, 20.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleWithPointExceptionZeroWidth)
{
  BOOST_CHECK_THROW(dambieva::Rectangle({5.5, 5.5}, 0.0, 20.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleWithPointExceptionInvalidHeight)
{
  BOOST_CHECK_THROW(dambieva::Rectangle({5.5, 5.5}, 10.0, -20.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleWithPointExceptionZeroHeight)
{
  BOOST_CHECK_THROW(dambieva::Rectangle({5.5, 5.5}, 10.0, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidScale)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
  BOOST_CHECK_THROW(rectangle.scale(-7.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroScale)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
  BOOST_CHECK_THROW(rectangle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidWidthSetter)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
  BOOST_CHECK_THROW(rectangle.setWidth(-7.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroWidthSetter)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
  BOOST_CHECK_THROW(rectangle.setWidth(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidHeightSetter)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
  BOOST_CHECK_THROW(rectangle.setHeight(-7.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroHeightSetter)
{
  dambieva::Rectangle rectangle(5.5, 5.5, 10.0, 20.0);
  BOOST_CHECK_THROW(rectangle.setHeight(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(TestCircleRadiusImmutabilityAfterMoveToPoint)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);

  double radiusBefore = circle.getRadius();
  double areaBefore = circle.getArea();
  dambieva::point_t newCenter = {7.0, 2.0};
  circle.move(newCenter);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getPos().x, newCenter.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getPos().y, newCenter.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getRadius(), radiusBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleRadiusImmutabilityAfterMove)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);

  dambieva::point_t centerBefore = circle.getPos();
  double radiusBefore = circle.getRadius();
  double areaBefore = circle.getArea();
  const double deltaX = 7.0;
  const double deltaY = 2.0;
  circle.move(deltaX, deltaY);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getPos().x, centerBefore.x + deltaX, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getPos().y, centerBefore.y + deltaY, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getRadius(), radiusBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleRadiusProportionalChangeAfterScale)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);

  dambieva::point_t centerBefore = circle.getPos();
  double radiusBefore = circle.getRadius();
  double areaBefore = circle.getArea();
  const double scaleIn = 3;
  circle.scale(scaleIn);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getPos().x, centerBefore.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getPos().y, centerBefore.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getRadius(), radiusBefore * scaleIn, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBefore * scaleIn * scaleIn, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleAreaImmutabilityAfterMoveToPoint)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);
  double areaBefore = circle.getArea();
  circle.move({7.0, 2.0});

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleAreaImmutabilityAfterMove)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);
  double areaBefore = circle.getArea();
  circle.move(7.0, 2.0);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleAreaProportionalChangeAfterScale)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);
  double areaBefore = circle.getArea();
  const double scaleIn = 3;
  circle.scale(scaleIn);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getArea(), areaBefore * scaleIn * scaleIn, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleFrameImmutabilityAfterMoveToPoint)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);

  double frameWidthBefore = circle.getFrameRect().width;
  double frameHeightBefore = circle.getFrameRect().height;
  dambieva::point_t newCenter = {7.0, 2.0};
  circle.move(newCenter);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, newCenter.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, newCenter.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, frameWidthBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().height, frameHeightBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleFrameImmutabilityAfterMove)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);

  dambieva::point_t centerBefore = circle.getPos();
  double frameWidthBefore = circle.getFrameRect().width;
  double frameHeightBefore = circle.getFrameRect().height;
  const double deltaX = 7.0;
  const double deltaY = 2.0;
  circle.move(deltaX, deltaY);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, centerBefore.x + deltaX, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, centerBefore.y + deltaY, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, frameWidthBefore, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().height, frameHeightBefore, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(TestCircleFrameProportionalChangeAfterScale)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);

  dambieva::point_t centerBefore = circle.getPos();
  double frameWidthBefore = circle.getFrameRect().width;
  double frameHeightBefore = circle.getFrameRect().height;
  const double scaleIn = 3;
  circle.scale(scaleIn);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, centerBefore.x, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, centerBefore.y, EXACTNESS);

  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().width, frameWidthBefore * scaleIn, EXACTNESS);
  BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().height, frameHeightBefore * scaleIn, EXACTNESS);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionInvalidRadius)
{
  BOOST_CHECK_THROW(dambieva::Circle(10.0, 10.0, -5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionZeroRadius)
{
  BOOST_CHECK_THROW(dambieva::Circle(10.0, 10.0, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleWithPointExceptionInvalidRadius)
{
  BOOST_CHECK_THROW(dambieva::Circle({10.0, 10.0}, -5.5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleWithPointExceptionZeroRadius)
{
  BOOST_CHECK_THROW(dambieva::Circle({10.0, 10.0}, 0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionInvalidScale)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);
  BOOST_CHECK_THROW(circle.scale(-7.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionZeroScale)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);
  BOOST_CHECK_THROW(circle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionInvalidSetter)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);
  BOOST_CHECK_THROW(circle.setRadius(-7.0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionZeroSetter)
{
  dambieva::Circle circle(10.0, 10.0, 5.5);
  BOOST_CHECK_THROW(circle.setRadius(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
