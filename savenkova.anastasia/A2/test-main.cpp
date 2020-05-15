#define BOOST_TEST_MODULE UNIT_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

const double ACCURACY = 1e-5;

BOOST_AUTO_TEST_SUITE(circleTest)

  BOOST_AUTO_TEST_CASE(testMovingCircleToPoint)
  {
    savenkova::Circle testCircle({ 0.0, 0.0 }, 7.7);

    const double areaBefore = testCircle.getArea();
    const savenkova::rectangle_t circleFrameBefore = testCircle.getFrameRect();
  
    testCircle.move({ 3.5, -2.4 });

    BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, 3.5, ACCURACY);
    BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, -2.4, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameBefore.width, testCircle.getFrameRect().width, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameBefore.height, testCircle.getFrameRect().height, ACCURACY);
    BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ACCURACY);

  }

  BOOST_AUTO_TEST_CASE(testMovingCircleAlongAxes)
  {
    savenkova::Circle testCircle({ 2.1, -3.6 }, 5.5);
    const savenkova::rectangle_t circleFrameBefore = testCircle.getFrameRect();
    const double areaBefore = testCircle.getArea();

    double xOffset = 4.9;
    double yOffset = 4.3;

    testCircle.move(xOffset, yOffset);
 
    const savenkova::rectangle_t circleFrameAfter = testCircle.getFrameRect();
    const double areaAfter = testCircle.getArea();

    BOOST_CHECK_CLOSE(circleFrameBefore.pos.x + xOffset, circleFrameAfter.pos.x, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameBefore.pos.y + yOffset, circleFrameAfter.pos.y, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameBefore.width, circleFrameAfter.width, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameAfter.height, circleFrameAfter.height, ACCURACY);
    BOOST_CHECK_CLOSE(areaBefore, areaAfter, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(testCircleScaling)
  {
    savenkova::Circle testCircle({ 1.2, 1.6 }, 2.3);
    const savenkova::rectangle_t circleFrameBefore = testCircle.getFrameRect();
    const double areaBefore = testCircle.getArea();

    double coefficient = 2.56;
    testCircle.scale(coefficient);

    const savenkova::rectangle_t circleFrameAfter = testCircle.getFrameRect();
    const double areaAfter = testCircle.getArea();

    BOOST_CHECK_CLOSE(circleFrameBefore.pos.x, circleFrameAfter.pos.x, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameBefore.pos.y, circleFrameAfter.pos.y, ACCURACY);
    BOOST_CHECK_CLOSE(areaBefore * coefficient * coefficient, areaAfter, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameBefore.width * coefficient, circleFrameAfter.width, ACCURACY);
    BOOST_CHECK_CLOSE(circleFrameBefore.height * coefficient, circleFrameAfter.height, ACCURACY);

  }

  BOOST_AUTO_TEST_CASE(testNoExceptionOfCircleConstrustor)
  {
    BOOST_CHECK_NO_THROW(savenkova::Circle({ 2.34, 0.0 }, 4.64));
  }

  BOOST_AUTO_TEST_CASE(testExceptionOfCircleConstrustor)
  {
    BOOST_CHECK_THROW(savenkova::Circle({ 4.322, 3.543 }, -42.4), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testExceptionOfScalingCoefficient)
  {
    savenkova::Circle testCircle({ 3.54, 5.24 }, 5.242);
    BOOST_CHECK_THROW(testCircle.scale(-4.65), std::invalid_argument);
  }


  BOOST_AUTO_TEST_CASE(testNoExceptionOfScalingCoefficient)
  {
    savenkova::Circle testCircle({ 3.54, 5.24 }, 5.242);
    BOOST_CHECK_NO_THROW(testCircle.scale(6.35));
  }

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(rectangleTest)

  BOOST_AUTO_TEST_CASE(testMovingRectangleToPoint)
  {
    savenkova::Rectangle testRectangle({ 0.0, 0.0 }, 6.535, 5.354);

    const double areaBefore = testRectangle.getArea();
    const savenkova::rectangle_t rectangleBefore = testRectangle.getFrameRect();

    testRectangle.move({ 4.24, -5.65 });

    const double areaAfter = testRectangle.getArea();
    const savenkova::rectangle_t rectangleAfter = testRectangle.getFrameRect();

    BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, 4.24, ACCURACY);
    BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, -5.65, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.width, rectangleAfter.width, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.height, rectangleAfter.height, ACCURACY);
    BOOST_CHECK_CLOSE(areaBefore, areaAfter, ACCURACY);

  }


  BOOST_AUTO_TEST_CASE(testMovingRectangleAlongAxes)
  {
    savenkova::Rectangle testRectangle({ 4.34, -6.553 }, 7.9573, 5.343);
    const savenkova::rectangle_t rectangleBefore = testRectangle.getFrameRect();
    const double areaBefore = testRectangle.getArea();

    double xOffset = 5.8;
    double yOffset = 3.53;

    testRectangle.move(xOffset, yOffset);

    const savenkova::rectangle_t rectangleAfter = testRectangle.getFrameRect();
    const double areaAfter = testRectangle.getArea();

    BOOST_CHECK_CLOSE(rectangleBefore.pos.x + xOffset, rectangleAfter.pos.x, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.pos.y + yOffset, rectangleAfter.pos.y, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.width, rectangleAfter.width, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.height, rectangleBefore.height, ACCURACY);
    BOOST_CHECK_CLOSE(areaBefore, areaAfter, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(testRectangleScaling)
  {
    savenkova::Rectangle testRectangle({ 0.432, -5.23 }, 2.35, 6.42);
    const savenkova::rectangle_t rectangleBefore = testRectangle.getFrameRect();
    const double areaBefore = testRectangle.getArea();

    double coefficient = 1.7;
    testRectangle.scale(coefficient);

    const savenkova::rectangle_t rectangleAfter = testRectangle.getFrameRect();
    const double areaAfter = testRectangle.getArea();

    BOOST_CHECK_CLOSE(rectangleBefore.pos.x, rectangleAfter.pos.x, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.pos.y, rectangleAfter.pos.y, ACCURACY);
    BOOST_CHECK_CLOSE(areaBefore * coefficient * coefficient, areaAfter, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.width * coefficient, rectangleAfter.width, ACCURACY);
    BOOST_CHECK_CLOSE(rectangleBefore.height * coefficient, rectangleAfter.height, ACCURACY);

  }

  BOOST_AUTO_TEST_CASE(testNoExceptionOfRectangleConstrustor)
  {
    BOOST_CHECK_NO_THROW(savenkova::Rectangle({ 0.0, 5.354 }, 8.434, 3.535));
  }

  BOOST_AUTO_TEST_CASE(testExceptionOfRectangleConstrustor)
  {
    BOOST_CHECK_THROW(savenkova::Rectangle({ 1.302, 0.543 }, -3.542, 5.423), std::invalid_argument);
    BOOST_CHECK_THROW(savenkova::Rectangle({ 8.434, 3.54 }, 0.542, -4.233), std::invalid_argument);
    BOOST_CHECK_THROW(savenkova::Rectangle({ 0.0, 0.0 }, -2.32, -1.242), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testExceptionOfScalingCoefficient)
  {
    savenkova::Rectangle testRectangle({ 38.32, 53.1241 }, 54.0, 42.424);

    BOOST_CHECK_THROW(testRectangle.scale(-0.44), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(testNoExceptionOfScalingCoefficient)
  {
    savenkova::Rectangle testRectangle({ 38.32, 53.1241 }, 54.0, 42.424);

    BOOST_CHECK_NO_THROW(testRectangle.scale(0.32));
  }

BOOST_AUTO_TEST_SUITE_END()
