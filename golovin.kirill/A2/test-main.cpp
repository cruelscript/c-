#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <stdexcept>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"

const double ACCURACY = 1e-8;

BOOST_AUTO_TEST_SUITE(TestRectangle)

  BOOST_AUTO_TEST_CASE(TestInvalidWidth)
  {
    const double width = -5.0;
    const double height = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};

    BOOST_CHECK_THROW(golovin::Rectangle rectangle(basePoint, width, height), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidHeight)
  {
    const double width = 5.0;
    const double height = -10.0;
    const golovin::point_t basePoint{0.0, 0.0};

    BOOST_CHECK_THROW(golovin::Rectangle rectangle(basePoint, width, height), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovingInPoint)
  {
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};
    const double width = 5.0;
    const double height = 10.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    rectangle.move(endPoint);

    BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, endPoint.x, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, endPoint.y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestMovingByOffset)
  {
    const double dX = 2.0;
    const double dY = -2.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double width = 5.0;
    const double height = 10.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    rectangle.move(dX, dY);

    BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, basePoint.x + dX, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, basePoint.y + dY, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestRightArea)
  {
    const double width = 5.0;
    const double height = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double rightArea = 50.0;

    golovin::Rectangle rectangle(basePoint, width, height);

    BOOST_CHECK_CLOSE(rectangle.getArea(), rightArea, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfSidesAfterMovingInPoint)
  {
    const double baseWidth = 5.0;
    const double baseHeight = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Rectangle rectangle(basePoint, baseWidth, baseHeight);
    double width = rectangle.getFrameRect().width;
    double height = rectangle.getFrameRect().height;
    rectangle.move(endPoint);

    BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfSidesAfterMovingByOffset)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    rectangle.move(dX, dY);

    BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingInPoint)
  {
    const double baseWidth = 5.0;
    const double baseHeight = 10.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Rectangle rectangle(basePoint, baseWidth, baseHeight);
    double area = rectangle.getArea();
    rectangle.move(endPoint);

    BOOST_CHECK_CLOSE(rectangle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingByOffset)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    double area = rectangle.getArea();
    rectangle.move(dX, dY);

    BOOST_CHECK_CLOSE(rectangle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidScale)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = -2.0;

    golovin::Rectangle rectangle(basePoint, width, height);

    BOOST_CHECK_THROW(rectangle.scale(scaleValue), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestRightAreaAfterScale)
  {
    const double width = 2.0;
    const double height = 4.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = 2.0;

    golovin::Rectangle rectangle(basePoint, width, height);
    double area = rectangle.getArea();
    rectangle.scale(scaleValue);

    BOOST_CHECK_CLOSE(rectangle.getArea(), area * scaleValue * scaleValue, ACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCircle)

  BOOST_AUTO_TEST_CASE(TestInvalidRadius)
  {
    const double radius = -5.0;
    const golovin::point_t basePoint{0.0, 0.0};

    BOOST_CHECK_THROW(golovin::Circle circle(basePoint, radius), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovingInPoint)
  {
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};
    const double radius = 5.0;

    golovin::Circle circle(basePoint, radius);
    circle.move(endPoint);

    BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, endPoint.x, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, endPoint.y, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestMovingByOffset)
  {
    const double dX = 2.0;
    const double dY = -2.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double radius = 5.0;

    golovin::Circle circle(basePoint, radius);
    circle.move(dX, dY);

    BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, basePoint.x + dX, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, basePoint.y + dY, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestRightArea)
  {
    const golovin::point_t basePoint{0.0, 0.0};
    const double radius = 1.0;
    const double rightArea = M_PI;

    golovin::Circle circle(basePoint, radius);

    BOOST_CHECK_CLOSE(circle.getArea(), rightArea, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfRadiusAfterMovingInPoint)
  {
    const double baseRadius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Circle circle(basePoint, baseRadius);
    double width = circle.getFrameRect().width;
    double height = circle.getFrameRect().height;
    circle.move(endPoint);

    BOOST_CHECK_CLOSE(circle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfRadiusAfterMovingByOffset)
  {
    const double baseRadius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Circle circle(basePoint, baseRadius);
    double width = circle.getFrameRect().width;
    double height = circle.getFrameRect().height;
    circle.move(dX, dY);

    BOOST_CHECK_CLOSE(circle.getFrameRect().width, width, ACCURACY);
    BOOST_CHECK_CLOSE(circle.getFrameRect().height, height, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingInPoint)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const golovin::point_t endPoint{10.0, -10.0};

    golovin::Circle circle(basePoint, radius);
    double area = circle.getArea();
    circle.move(endPoint);

    BOOST_CHECK_CLOSE(circle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvarianceOfAreaAfterMovingByOffset)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double dX = 2.0;
    const double dY = -2.0;

    golovin::Circle circle(basePoint, radius);
    double area = circle.getArea();
    circle.move(dX, dY);

    BOOST_CHECK_CLOSE(circle.getArea(), area, ACCURACY);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidScale)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = -2.0;

    golovin::Circle circle(basePoint, radius);

    BOOST_CHECK_THROW(circle.scale(scaleValue), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestRightAreaAfterScale)
  {
    const double radius = 5.0;
    const golovin::point_t basePoint{0.0, 0.0};
    const double scaleValue = 2.0;

    golovin::Circle circle(basePoint, radius);
    double area = circle.getArea();
    circle.scale(scaleValue);

    BOOST_CHECK_CLOSE(circle.getArea(), area * scaleValue * scaleValue, ACCURACY);
  }

BOOST_AUTO_TEST_SUITE_END()
