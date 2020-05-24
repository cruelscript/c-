#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <cmath>
#include <stdexcept>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "../common/rectangle.hpp"
#include "../common/circle.hpp"
#include "../common/composite-shape.hpp"

static const double EPSILON = 1e-8;

BOOST_AUTO_TEST_SUITE(RectangleTestsCases)

  BOOST_AUTO_TEST_CASE(TestCorrectConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_NO_THROW(konovalov::Rectangle rectangle(1.0, 1.0, {0.0, 0.0}));
  }

  BOOST_AUTO_TEST_CASE(TestNotCorrectDataInConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_THROW(konovalov::Rectangle rectangle(-1.0, 1.1, {0.0, 1.1}), std::invalid_argument);
    BOOST_CHECK_THROW(konovalov::Rectangle rectangle(1.0, -1.1, {0.0, 1.1}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetFrameRectWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle(1.1, 1.2, {0.0, 0.1});

    //check frame correct
    BOOST_CHECK_CLOSE_FRACTION(1.1, rectangle.getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(1.2, rectangle.getFrameRect().height, EPSILON);

    //check point correct
    BOOST_CHECK_CLOSE_FRACTION(0.0, rectangle.getFrameRect().pos.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(0.1, rectangle.getFrameRect().pos.y, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMoveCoordinateWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle(1.0, 2.0, {1.1, 3.5});
    double expectX = 7.1 + 1.1;
    double expectY = 3.4 + 3.5;
    rectangle.move(7.1, 3.4);

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, expectX, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, expectY, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 1.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMovePointWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle(1.0, 2.0, {1.0, 2.0});
    rectangle.move({7.1, 3.4});

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 7.1, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 3.4, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 1.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetAreaWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle(6.0, 2.0, {1.0, 2.0});
    double expectArea = 6.0 * 2.0;
    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterMoving)
  {
    konovalov::point_t centerPoint = {1.0, 2.0};
    konovalov::Rectangle rectangle = konovalov::Rectangle(3.0, 2.0, {centerPoint.x, centerPoint.y});
    double dx = 7.1;
    double dy = 3.4;
    double expectArea = 3.0 * 2.0;
    rectangle.move(dx, dy);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, centerPoint.x + dx, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, centerPoint.y + dy, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterChangingPoint)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle(3.0, 2.0, {1.0, 2.0});
    konovalov::point_t newCenterPoint = {2.0, 3.0};
    double expectArea = 3.0 * 2.0;
    rectangle.move(newCenterPoint);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, newCenterPoint.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, newCenterPoint.y, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectExceptionScaleWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle(4.5, 2.0, {1.1, 1.2});
    double coefficient = -1.1;
    //check correct exception
    BOOST_CHECK_THROW(rectangle.scale(coefficient), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectScaleWork)
  {
    konovalov::Rectangle rectangle = konovalov::Rectangle(4.5, 2.0, {1.1, 1.2});
    double coefficient = 2.0;
    double expectArea = 4.5 * 2.0 * 2.0 * 2.0;
    rectangle.scale(coefficient);

    //check correct scaled
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 4.5 * coefficient, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 2.0 * coefficient, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectArea, EPSILON);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CircleTestCases)

  BOOST_AUTO_TEST_CASE(TestCorrectConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_NO_THROW(konovalov::Circle circle(1.1, {0.0, 0.0}));
  }

  BOOST_AUTO_TEST_CASE(TestNotCorrectDataInConstructorWork)
  {
    //check constructors work
    BOOST_CHECK_THROW(konovalov::Circle circle(-1.0, {0.0, 1.1}), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetFrameRectWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.1, {0.0, 0.1});

    //check radius correct
    BOOST_CHECK_CLOSE_FRACTION(2.2, circle.getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(2.2, circle.getFrameRect().height, EPSILON);

    //check point correct
    BOOST_CHECK_CLOSE_FRACTION(0.0, circle.getFrameRect().pos.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(0.1, circle.getFrameRect().pos.y, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMoveCoordinateWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.0, {1.1, 3.5});
    double expectX = 1.1 + 7.1;
    double expectY = 3.5 + 3.4;
    circle.move(7.1, 3.4);

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, expectX, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, expectY, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 2.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMovePointWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.0, {1.0, 2.0});
    circle.move({7.1, 3.4});

    //check correct point coordinate
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, 7.1, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, 3.4, EPSILON);

    //check unchanged height and width
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 2.0, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 2.0, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetAreaWork)
  {
    konovalov::Circle circle = konovalov::Circle(6.0, {1.0, 2.0});
    double expectArea = 6.0 * 6.0 * M_PI;
    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterMoving)
  {
    konovalov::point_t centerPoint = {1.0, 2.0};
    konovalov::Circle circle = konovalov::Circle(3.0, centerPoint);
    double dx = 7.1;
    double dy = 3.4;
    double expectArea = 3.0 * 3.0 * M_PI;
    circle.move(dx, dy);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, centerPoint.x + dx, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, centerPoint.y + dy, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestAreaAfterChangingPoint)
  {
    konovalov::Circle circle = konovalov::Circle(3.0, {1.0, 2.0});
    konovalov::point_t newCenterPoint = {3.2, 5.2};
    double expectArea = 3.0 * 3.0 * M_PI;
    circle.move(newCenterPoint);

    //check correct move
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, newCenterPoint.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, newCenterPoint.y, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectExceptionScaleWork)
  {
    konovalov::Circle circle = konovalov::Circle(1.1, {1.2, 2.3});
    double coefficient = -1.1;

    //check correct exception
    BOOST_CHECK_THROW(circle.scale(coefficient), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectScaleWork)
  {
    konovalov::Circle circle = konovalov::Circle(2.0, {1.1, 1.2});
    double coefficient = 2.0;
    double expectArea = 2.0 * 2.0 * M_PI * 2.0 * 2.0;
    circle.scale(coefficient);

    //check correct scaled
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 2.0 * 2.0 * coefficient, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 2.0 * 2.0 * coefficient, EPSILON);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectArea, EPSILON);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CompositeShapeTestCases)

  BOOST_AUTO_TEST_CASE(TestInvalidPushShape)
  {
    std::shared_ptr<konovalov::Shape> shape = nullptr;
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();

    //check invalid push
    BOOST_CHECK_THROW(compositeShape.pushShapeBack(shape), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectPushShapeWork)
  {
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.1, konovalov::point_t{1.2, 0.0});
    std::shared_ptr<konovalov::Shape> expectedRectangle =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, konovalov::point_t{0.1, 0.0});
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();
    compositeShape.pushShapeBack(expectedCircle);
    compositeShape.pushShapeBack(expectedRectangle);

    //check correct number of shapes
    BOOST_CHECK_EQUAL(compositeShape.getSize(), 2);

    //check correct elements in composite shape
    //circle
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getCenterPoint().x, expectedCircle->getCenterPoint().x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getCenterPoint().y, expectedCircle->getCenterPoint().y, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getFrameRect().width, expectedCircle->getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getFrameRect().height, expectedCircle->getFrameRect().height,
      EPSILON);
    //rectangle
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getCenterPoint().x, expectedRectangle->getCenterPoint().x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getCenterPoint().y, expectedRectangle->getCenterPoint().y, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getFrameRect().width, expectedRectangle->getFrameRect().width,
      EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getFrameRect().height, expectedRectangle->getFrameRect().height,
      EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidAddShape)
  {
    std::shared_ptr<konovalov::Shape> shape = nullptr;
    std::shared_ptr<konovalov::Shape> circleForIndexTest =
      std::make_shared<konovalov::Circle>(1.1, konovalov::point_t{1.2, 0.0});
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();

    //check invalid push
    BOOST_CHECK_THROW(compositeShape.addShape(0, shape), std::invalid_argument);
    BOOST_CHECK_THROW(compositeShape.addShape(1, shape), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectAddShapeWork)
  {
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.1, konovalov::point_t{1.2, 0.0});
    std::shared_ptr<konovalov::Shape> expectedRectangle =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, konovalov::point_t{0.1, 0.0});
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();
    compositeShape.pushShapeBack(expectedCircle);
    compositeShape.addShape(0, expectedRectangle);

    //check correct number of shapes
    BOOST_CHECK_EQUAL(compositeShape.getSize(), 2);

    //check correct elements in composite shape
    //circle
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getCenterPoint().x, expectedCircle->getCenterPoint().x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getCenterPoint().y, expectedCircle->getCenterPoint().y, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getFrameRect().width, expectedCircle->getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[1]->getFrameRect().height, expectedCircle->getFrameRect().height,
      EPSILON);

    //rectangle
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getCenterPoint().x, expectedRectangle->getCenterPoint().x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getCenterPoint().y, expectedRectangle->getCenterPoint().y, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getFrameRect().width, expectedRectangle->getFrameRect().width,
      EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getFrameRect().height, expectedRectangle->getFrameRect().height,
      EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidOperatorGet)
  {
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();

    //check out of range index
    BOOST_CHECK_THROW(compositeShape[0], std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectOperatorGetWork)
  {
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.1, konovalov::point_t{1.2, 0.0});
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();
    compositeShape.pushShapeBack(expectedCircle);

    //check correct elements on index
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getCenterPoint().x, expectedCircle->getCenterPoint().x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getCenterPoint().y, expectedCircle->getCenterPoint().y, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getFrameRect().width, expectedCircle->getFrameRect().width, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape[0]->getFrameRect().height, expectedCircle->getFrameRect().height,
      EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectAssignmentOperatorWork)
  {
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.1, konovalov::point_t{1.2, 0.0});
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();
    konovalov::CompositeShape actualCompositeShape = konovalov::CompositeShape();
    compositeShape.pushShapeBack(expectedCircle);
    actualCompositeShape = compositeShape;

    //check correct elements on index
    BOOST_CHECK_CLOSE_FRACTION(actualCompositeShape[0]->getCenterPoint().x, expectedCircle->getCenterPoint().x,
      EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(actualCompositeShape[0]->getCenterPoint().y, expectedCircle->getCenterPoint().y,
      EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(actualCompositeShape[0]->getFrameRect().width, expectedCircle->getFrameRect().width,
      EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(actualCompositeShape[0]->getFrameRect().height, expectedCircle->getFrameRect().height,
      EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidDeleteShape)
  {
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();

    //check invalid delete
    BOOST_CHECK_THROW(compositeShape.deleteShape(0), std::out_of_range);
    BOOST_CHECK_THROW(compositeShape.deleteShapeFromBack(), std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectDeleteShapeWork)
  {
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.1, konovalov::point_t{1.2, 0.0});
    std::shared_ptr<konovalov::Shape> expectedRectangle =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, konovalov::point_t{0.1, 0.0});
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();

    compositeShape.pushShapeBack(expectedCircle);
    compositeShape.pushShapeBack(expectedRectangle);
    compositeShape.deleteShapeFromBack();
    compositeShape.deleteShape(0);

    //check correct number of shapes
    BOOST_CHECK_EQUAL(compositeShape.getSize(), 0);
  }

  BOOST_AUTO_TEST_CASE(TestInvalidGetFrameRect)
  {
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();

    //check error
    BOOST_CHECK_THROW(compositeShape.getFrameRect(), std::runtime_error);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetFrameRectWork)
  {
    konovalov::point_t expectedCenter = {0.0, 0.0};
    std::shared_ptr<konovalov::Shape> expectedCircle1 =
      std::make_shared<konovalov::Circle>(1.0, expectedCenter);
    std::shared_ptr<konovalov::Shape> expectedRectangle1 =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, expectedCenter);
    std::shared_ptr<konovalov::Shape> expectedCircle2 =
      std::make_shared<konovalov::Circle>(1.0, expectedCenter);
    std::shared_ptr<konovalov::Shape> expectedRectangle2 =
      std::make_shared<konovalov::Rectangle>(5.1, 2.2, expectedCenter);
    konovalov::CompositeShape compositeShape1 = konovalov::CompositeShape();
    konovalov::CompositeShape compositeShape2 = konovalov::CompositeShape();

    double firstExpectedWidth = 1.0 * 2.0;
    double firstExpectedHeight = 1.0 * 2.0;
    double secondExpectedWidth = 5.1;
    double secondExpectedHeight = 2.2;

    compositeShape1.pushShapeBack(expectedCircle1);
    compositeShape1.pushShapeBack(expectedRectangle1);
    compositeShape2.pushShapeBack(expectedCircle2);
    compositeShape2.pushShapeBack(expectedRectangle2);

    //check correct first frame rect
    BOOST_CHECK_CLOSE_FRACTION(compositeShape1.getFrameRect().pos.x, expectedCenter.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape1.getFrameRect().pos.y, expectedCenter.y, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape1.getFrameRect().width, firstExpectedWidth, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape1.getFrameRect().height, firstExpectedHeight, EPSILON);

    //check correct second frame rect
    BOOST_CHECK_CLOSE_FRACTION(compositeShape2.getFrameRect().pos.x, expectedCenter.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape2.getFrameRect().pos.y, expectedCenter.y, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape2.getFrameRect().width, secondExpectedWidth, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape2.getFrameRect().height, secondExpectedHeight, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectGetAreaWork)
  {
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.0, konovalov::point_t{0.0, 0.0});
    std::shared_ptr<konovalov::Shape> expectedRectangle =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, konovalov::point_t{0.0, 0.0});
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();
    double expectedArea = 0.0;

    expectedArea += expectedCircle->getArea() + expectedRectangle->getArea();
    compositeShape.pushShapeBack(expectedCircle);
    compositeShape.pushShapeBack(expectedRectangle);

    //check correct area
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getArea(), expectedArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMovePointWork)
  {
    konovalov::point_t centerPoint = {0.0, 0.0};
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.0, centerPoint);
    std::shared_ptr<konovalov::Shape> expectedRectangle =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, centerPoint);
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();
    centerPoint = {1.1, 1.1};
    compositeShape.pushShapeBack(expectedCircle);
    compositeShape.pushShapeBack(expectedRectangle);
    double expectedWidth = compositeShape.getFrameRect().width;
    double expectedHeight = compositeShape.getFrameRect().height;
    double expectedArea = compositeShape.getArea();
    compositeShape.move(centerPoint);

    //check correct moving point
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenterPoint().x, centerPoint.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenterPoint().y, centerPoint.y, EPSILON);

    //check correct not changing height and width
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getFrameRect().width, expectedWidth, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getFrameRect().height, expectedHeight, EPSILON);

    //check not changing area
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getArea(), expectedArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectMoveCoordinateWork)
  {
    konovalov::point_t centerPoint = {0.0, 0.0};
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.0, centerPoint);
    std::shared_ptr<konovalov::Shape> expectedRectangle =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, centerPoint);
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();
    double expectedX = centerPoint.x + 1.1;
    double expectedY = centerPoint.y + 2.2;
    compositeShape.pushShapeBack(expectedCircle);
    compositeShape.pushShapeBack(expectedRectangle);
    double expectedWidth = compositeShape.getFrameRect().width;
    double expectedHeight = compositeShape.getFrameRect().height;
    double expectedArea = compositeShape.getArea();

    compositeShape.move(expectedX, expectedY);

    //check correct moving
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenterPoint().x, expectedX, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenterPoint().y, expectedY, EPSILON);

    //check correct not changing height and width
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getFrameRect().width, expectedWidth, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getFrameRect().height, expectedHeight, EPSILON);

    //check not changing area
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getArea(), expectedArea, EPSILON);
  }

  BOOST_AUTO_TEST_CASE(TestCorrectScaleWork)
  {
    konovalov::point_t expectedCenterPoint = {0.0, 0.0};
    std::shared_ptr<konovalov::Shape> expectedCircle =
      std::make_shared<konovalov::Circle>(1.0, expectedCenterPoint);
    std::shared_ptr<konovalov::Shape> expectedRectangle =
      std::make_shared<konovalov::Rectangle>(1.1, 1.2, expectedCenterPoint);
    konovalov::CompositeShape compositeShape = konovalov::CompositeShape();

    compositeShape.pushShapeBack(expectedCircle);
    compositeShape.pushShapeBack(expectedRectangle);

    double coefficient = 2.0;
    double expectedArea = compositeShape.getArea() * coefficient * coefficient;
    double expectedWidth = compositeShape.getFrameRect().width * coefficient;
    double expectedHeight = compositeShape.getFrameRect().height * coefficient;

    compositeShape.scale(coefficient);

    //check correct coordinates
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenterPoint().x, expectedCenterPoint.x, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenterPoint().y, expectedCenterPoint.y, EPSILON);

    //check correct frame
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getFrameRect().width, expectedWidth, EPSILON);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getFrameRect().height, expectedHeight, EPSILON);

    //check correct area scale
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getArea(), expectedArea, EPSILON);
  }

BOOST_AUTO_TEST_SUITE_END()
