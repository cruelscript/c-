#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <stdexcept>
#include "circle.hpp"

const double ACCURACY_VALUE = 1e-10;

BOOST_AUTO_TEST_SUITE(circleTestSuite)

BOOST_AUTO_TEST_CASE(testFigureAfterMovingToPoint)
{
  gabdullina::Circle testCircle({1, 1}, 3);
  const double widthBefore = testCircle.getFrameRect().width;
  const double heightBefore = testCircle.getFrameRect().height;
  const double areaBefore = testCircle.getArea();

  testCircle.move({2.3, 1.8});
  const double xCoordinateAfter = testCircle.getPos().x;
  const double yCoordinateAfter = testCircle.getPos().y;
  const double widthAfter = testCircle.getFrameRect().width;
  const double heightAfter = testCircle.getFrameRect().height;
  const double areaAfter = testCircle.getArea();

  BOOST_CHECK_CLOSE(xCoordinateAfter, 2.3, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(yCoordinateAfter, 1.8, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(widthBefore, widthAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(heightBefore, heightAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testFigureAfterMovingAlongAxes)
{
  gabdullina::Circle testCircle(-1, -2, 1);
  const double xCoordinateBefore = testCircle.getPos().x;
  const double yCoordinateBefore = testCircle.getPos().y;
  const double widthBefore = testCircle.getFrameRect().width;
  const double heightBefore = testCircle.getFrameRect().height;
  const double areaBefore = testCircle.getArea();

  testCircle.move(3, 1);
  const double xCoordinateAfter = testCircle.getPos().x;
  const double yCoordinateAfter = testCircle.getPos().y;
  const double widthAfter = testCircle.getFrameRect().width;
  const double heightAfter = testCircle.getFrameRect().height;
  const double areaAfter = testCircle.getArea();

  BOOST_CHECK_CLOSE(xCoordinateBefore + 3, xCoordinateAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(yCoordinateBefore + 1, yCoordinateAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(widthBefore, widthAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(heightBefore, heightAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(areaBefore, areaAfter, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testFigureAfterScaling)
{
  gabdullina::Circle testCircle({2, 2}, 4);
  const double xCoordinateBefore = testCircle.getPos().x;
  const double yCoordinateBefore = testCircle.getPos().y;
  const double areaBefore = testCircle.getArea();

  testCircle.scale(1.75);
  const double xCoordinateAfter = testCircle.getPos().x;
  const double yCoordinateAfter = testCircle.getPos().y;
  const double areaAfter = testCircle.getArea();

  BOOST_CHECK_CLOSE(xCoordinateBefore, xCoordinateAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(yCoordinateBefore, yCoordinateAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(areaAfter, areaBefore * 1.75 * 1.75, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testExceptionConstructorWithPoint)
{
  BOOST_CHECK_THROW(gabdullina::Circle({1, 2}, -3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testNoExceptionConstructorWithPoint)
{
  BOOST_CHECK_NO_THROW(gabdullina::Circle({1, 2}, 0));
}

BOOST_AUTO_TEST_CASE(testExceptionConstructorWithAxes)
{
  BOOST_CHECK_THROW(gabdullina::Circle(1.2, 3, -5), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testNoExceptionConstructorWithAxes)
{
  BOOST_CHECK_NO_THROW(gabdullina::Circle(1.2, 3, 0));
}

BOOST_AUTO_TEST_CASE(testExceptionWhenScaling)
{
  gabdullina::Circle testCircle({2, 1}, 4);
  BOOST_CHECK_THROW(testCircle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testNoExceptionWhenScaling)
{
  gabdullina::Circle testCircle({2, 1}, 4);
  BOOST_CHECK_NO_THROW(testCircle.scale(0));
}

BOOST_AUTO_TEST_SUITE_END()
