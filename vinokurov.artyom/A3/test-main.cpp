#define BOOST_TEST_MODULE UNIT_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <stdexcept>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double EPSILON = 1e-10;

BOOST_AUTO_TEST_SUITE(RectangleTest)

BOOST_AUTO_TEST_CASE(testRectangleImmutabilityAfterPointMove)
{
  vinokurov::Rectangle testRectangle(5.7, 7.5, {1.2, 2.1});

  double widthBefore = testRectangle.getFrameRect().width;
  double heightBefore = testRectangle.getFrameRect().height;
  vinokurov::point_t movePoint = {4.8, 8.4};

  testRectangle.move(movePoint);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, movePoint.x, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, movePoint.y, EPSILON);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleImmutabilityAfterDeltaMove)
{
  vinokurov::point_t centerPos = {1.2, 2.1};
  vinokurov::Rectangle testRectangle(5.7, 7.5, centerPos);

  double widthBefore = testRectangle.getFrameRect().width;
  double heightBefore = testRectangle.getFrameRect().height;
  double deltaX = 4.8;
  double deltaY = -8.4;

  testRectangle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.x, centerPos.x + deltaX, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().pos.y, centerPos.y + deltaY, EPSILON);

  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testRectangle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaImmutabilityAfterPointMove)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  double areaBefore = testRectangle.getArea();
  testRectangle.move({2.2, 2.2});

  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaImmutabilityAfterDeltaMove)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  double areaBefore = testRectangle.getArea();
  testRectangle.move(2.2, 2.2);

  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleAreaChangingAfterScaling)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  double areaBefore = testRectangle.getArea();
  testRectangle.scale(7.7);

  BOOST_CHECK_CLOSE(areaBefore * 7.7 * 7.7, testRectangle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidWidth)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(-5.5, 5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroWidth)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(0.0, 5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidHeight)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(5.5, -5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroHeight)
{
  BOOST_CHECK_THROW(vinokurov::Rectangle(5.5, 0.0, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionInvalidScaling)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  BOOST_CHECK_THROW(testRectangle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleExceptionZeroScaling)
{
  vinokurov::Rectangle testRectangle(5.5, 5.5, {1.1, 1.1});
  BOOST_CHECK_THROW(testRectangle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(testCircleImmutabilityAfterPointMove)
{
  vinokurov::Circle testCircle(5.5, {1.2, 2.1});

  double widthBefore = testCircle.getFrameRect().width;
  double heightBefore = testCircle.getFrameRect().height;
  vinokurov::point_t movePoint = {4.8, -8.4};

  testCircle.move(movePoint);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, movePoint.x, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, movePoint.y, EPSILON);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleImmutabilityAfterDeltaMove)
{
  vinokurov::point_t centerPos = {1.2, 2.1};
  vinokurov::Circle testCircle(5.5, centerPos);

  double deltaX = 4.8;
  double deltaY = -8.4;
  double widthBefore = testCircle.getFrameRect().width;
  double heightBefore = testCircle.getFrameRect().height;

  testCircle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.x, centerPos.x + deltaX, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().pos.y, centerPos.y + deltaY, EPSILON);

  BOOST_CHECK_CLOSE(testCircle.getFrameRect().width, widthBefore, EPSILON);
  BOOST_CHECK_CLOSE(testCircle.getFrameRect().height, heightBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleAreaImmutabilityAfterPointMove)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  double areaBefore = testCircle.getArea();
  testCircle.move({2.2, 2.2});

  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleAreaImmutabilityAfterDeltaMove)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  double areaBefore = testCircle.getArea();
  testCircle.move(2.2, 2.2);

  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleAreaChangingAfterScaling)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  double areaBefore = testCircle.getArea();
  testCircle.scale(7.7);

  BOOST_CHECK_CLOSE(areaBefore * 7.7 * 7.7, testCircle.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionInvalidRadius)
{
  BOOST_CHECK_THROW(vinokurov::Circle testCircle(-5.5, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionZeroRadius)
{
  BOOST_CHECK_THROW(vinokurov::Circle testCircle(0.0, {1.1, 1.1}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionInvalidScaling)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  BOOST_CHECK_THROW(testCircle.scale(-7.7), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCircleExceptionZeroScaling)
{
  vinokurov::Circle testCircle(5.5, {1.1, 1.1});
  BOOST_CHECK_THROW(testCircle.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CompositeShapeTest)

BOOST_AUTO_TEST_CASE(testCompositeShapeImmutabilityAfterPointMove)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  vinokurov::rectangle_t frameRectBefore = testCompositeShape.getFrameRect();
  vinokurov::point_t movePoint = {6.6, 6.6};

  testCompositeShape.move(movePoint);

  vinokurov::rectangle_t frameRectAfter = testCompositeShape.getFrameRect();

  BOOST_CHECK_CLOSE(frameRectAfter.pos.x, movePoint.x, EPSILON);
  BOOST_CHECK_CLOSE(frameRectAfter.pos.y, movePoint.y, EPSILON);

  BOOST_CHECK_CLOSE(frameRectAfter.width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectAfter.height, frameRectBefore.height, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapePartsImmutabilityAfterPointMove)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  vinokurov::point_t compositeShapeCenter = testCompositeShape.getFrameRect().pos;
  vinokurov::rectangle_t rectangleFrameRectBefore = testCompositeShape[0]->getFrameRect();
  vinokurov::rectangle_t circleFrameRectBefore = testCompositeShape[1]->getFrameRect();
  vinokurov::point_t movePoint = {6.6, 6.6};

  testCompositeShape.move(movePoint);

  vinokurov::rectangle_t rectangleFrameRectAfter = testCompositeShape[0]->getFrameRect();
  vinokurov::rectangle_t circleFrameRectAfter = testCompositeShape[1]->getFrameRect();
  double deltaX = movePoint.x - compositeShapeCenter.x;
  double deltaY = movePoint.y - compositeShapeCenter.y;

  BOOST_CHECK_CLOSE(rectangleFrameRectBefore.pos.x + deltaX, rectangleFrameRectAfter.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(rectangleFrameRectBefore.pos.y + deltaY, rectangleFrameRectAfter.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectBefore.pos.x + deltaX, circleFrameRectAfter.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectBefore.pos.y + deltaY, circleFrameRectAfter.pos.y, EPSILON);

  BOOST_CHECK_CLOSE(rectangleFrameRectBefore.width, rectangleFrameRectAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(rectangleFrameRectBefore.height, rectangleFrameRectAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectBefore.width, circleFrameRectAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectBefore.height, circleFrameRectAfter.height, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeImmutabilityAfterDeltaMove)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  vinokurov::rectangle_t frameRectBefore = testCompositeShape.getFrameRect();
  vinokurov::point_t centerPos = frameRectBefore.pos;
  double deltaX = 4.8;
  double deltaY = -8.4;

  testCompositeShape.move(deltaX, deltaY);

  vinokurov::rectangle_t frameRectAfter = testCompositeShape.getFrameRect();

  BOOST_CHECK_CLOSE(frameRectAfter.pos.x, centerPos.x + deltaX, EPSILON);
  BOOST_CHECK_CLOSE(frameRectAfter.pos.y, centerPos.y + deltaY, EPSILON);

  BOOST_CHECK_CLOSE(frameRectAfter.width, frameRectBefore.width, EPSILON);
  BOOST_CHECK_CLOSE(frameRectAfter.height, frameRectBefore.height, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapePartsImmutabilityAfterDeltaMove)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  vinokurov::rectangle_t rectangleFrameRectBefore = testCompositeShape[0]->getFrameRect();
  vinokurov::point_t rectangleCenterPosBefore = rectangleFrameRectBefore.pos;
  vinokurov::rectangle_t circleFrameRectBefore = testCompositeShape[1]->getFrameRect();
  vinokurov::point_t circleCenterPosBefore = circleFrameRectBefore.pos;
  double deltaX = 4.8;
  double deltaY = -8.4;

  testCompositeShape.move(deltaX, deltaY);

  vinokurov::rectangle_t rectangleFrameRectAfter = testCompositeShape[0]->getFrameRect();
  vinokurov::rectangle_t circleFrameRectAfter = testCompositeShape[1]->getFrameRect();

  BOOST_CHECK_CLOSE(rectangleFrameRectAfter.pos.x, rectangleCenterPosBefore.x + deltaX, EPSILON);
  BOOST_CHECK_CLOSE(rectangleFrameRectAfter.pos.y, rectangleCenterPosBefore.y + deltaY, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectAfter.pos.x, circleCenterPosBefore.x + deltaX, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectAfter.pos.y, circleCenterPosBefore.y + deltaY, EPSILON);

  BOOST_CHECK_CLOSE(rectangleFrameRectBefore.width, rectangleFrameRectAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(rectangleFrameRectBefore.height, rectangleFrameRectAfter.height, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectBefore.width, circleFrameRectAfter.width, EPSILON);
  BOOST_CHECK_CLOSE(circleFrameRectBefore.height, circleFrameRectAfter.height, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAreaImmutabilityAfterPointMove)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  double areaBefore = testCompositeShape.getArea();

  testCompositeShape.move({-9.7, 8.9});

  BOOST_CHECK_CLOSE(testCompositeShape.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAreaImmutabilityAfterDeltaMove)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  double areaBefore = testCompositeShape.getArea();

  testCompositeShape.move(-9.7, 8.9);

  BOOST_CHECK_CLOSE(testCompositeShape.getArea(), areaBefore, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeAreaChangingAfterScaling)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  double areaBefore = testCompositeShape.getArea();

  testCompositeShape.scale(8.8);

  BOOST_CHECK_CLOSE(testCompositeShape.getArea(), areaBefore * 8.8 * 8.8, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapePartsAreaChangingAfterScaling)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});
  vinokurov::CompositeShape::shapePtr testCircle =
    std::make_shared<vinokurov::Circle>(1.1, vinokurov::point_t{5.5, 5.5});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  double rectangleAreaBefore = testCompositeShape[0]->getArea();
  double circleAreaBefore = testCompositeShape[1]->getArea();

  testCompositeShape.scale(8.8);

  BOOST_CHECK_CLOSE(testCompositeShape[0]->getArea(), rectangleAreaBefore * 8.8 * 8.8, EPSILON);
  BOOST_CHECK_CLOSE(testCompositeShape[1]->getArea(), circleAreaBefore * 8.8 * 8.8, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeCopyConstructorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape copyCompositeShape;
  copyCompositeShape.add(testRectangle);

  BOOST_CHECK_NO_THROW(vinokurov::CompositeShape testCompositeShape(copyCompositeShape));
}

BOOST_AUTO_TEST_CASE(testCompositeShapeCopyConstructorCopying)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape copyCompositeShape;
  copyCompositeShape.add(testRectangle);
  vinokurov::CompositeShape testCompositeShape(copyCompositeShape);

  vinokurov::rectangle_t copyCompositeShapeFrameRect = copyCompositeShape.getFrameRect();
  vinokurov::rectangle_t testCompositeShapeFrameRect = testCompositeShape.getFrameRect();

  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.pos.x, testCompositeShapeFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.pos.y, testCompositeShapeFrameRect.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.width, testCompositeShapeFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.height, testCompositeShapeFrameRect.height, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeMoveConstructorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape compositeShape;
  compositeShape.add(testRectangle);

  BOOST_CHECK_NO_THROW(vinokurov::CompositeShape testCompositeShape(std::move(compositeShape)));
}

BOOST_AUTO_TEST_CASE(testCompositeShapeMoveConstructorMoving)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape movedCompositeShape;
  movedCompositeShape.add(testRectangle);
  vinokurov::rectangle_t movedCompositeShapeFrameRect = movedCompositeShape.getFrameRect();

  vinokurov::CompositeShape testCompositeShape(std::move(movedCompositeShape));

  vinokurov::rectangle_t testCompositeShapeFrameRect = testCompositeShape.getFrameRect();

  BOOST_CHECK_CLOSE(movedCompositeShapeFrameRect.pos.x, testCompositeShapeFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(movedCompositeShapeFrameRect.pos.y, testCompositeShapeFrameRect.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(movedCompositeShapeFrameRect.width, testCompositeShapeFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(movedCompositeShapeFrameRect.height, testCompositeShapeFrameRect.height, EPSILON);

  BOOST_CHECK_THROW(movedCompositeShape.getFrameRect(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeCopyAssignmentOperatorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape copyCompositeShape;
  copyCompositeShape.add(testRectangle);

  BOOST_CHECK_NO_THROW(vinokurov::CompositeShape testCompositeShape = copyCompositeShape);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeCopyAssignmentOperatorCopying)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape copyCompositeShape;
  copyCompositeShape.add(testRectangle);
  vinokurov::CompositeShape testCompositeShape = copyCompositeShape;

  vinokurov::rectangle_t copyCompositeShapeFrameRect = copyCompositeShape.getFrameRect();
  vinokurov::rectangle_t testCompositeShapeFrameRect = testCompositeShape.getFrameRect();

  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.pos.x, testCompositeShapeFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.pos.y, testCompositeShapeFrameRect.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.width, testCompositeShapeFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(copyCompositeShapeFrameRect.height, testCompositeShapeFrameRect.height, EPSILON);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeMoveAssignmentOperatorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape compositeShape;
  compositeShape.add(testRectangle);

  BOOST_CHECK_NO_THROW(vinokurov::CompositeShape testCompositeShape = std::move(compositeShape));
}

BOOST_AUTO_TEST_CASE(testCompositeShapeMoveAssignmentOperatorMoving)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape movedCompositeShape;
  movedCompositeShape.add(testRectangle);
  vinokurov::rectangle_t compositeShapeFrameRect = movedCompositeShape.getFrameRect();

  vinokurov::CompositeShape testCompositeShape = std::move(movedCompositeShape);

  vinokurov::rectangle_t testCompositeShapeFrameRect = testCompositeShape.getFrameRect();

  BOOST_CHECK_CLOSE(compositeShapeFrameRect.pos.x, testCompositeShapeFrameRect.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(compositeShapeFrameRect.pos.y, testCompositeShapeFrameRect.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(compositeShapeFrameRect.width, testCompositeShapeFrameRect.width, EPSILON);
  BOOST_CHECK_CLOSE(compositeShapeFrameRect.height, testCompositeShapeFrameRect.height, EPSILON);

  BOOST_CHECK_THROW(movedCompositeShape.getFrameRect(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeExceptionInvalidIndex)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);

  BOOST_CHECK_THROW(testCompositeShape[100], std::out_of_range);
  BOOST_CHECK_THROW(testCompositeShape[-1], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeExceptionAddingNullptr)
{
  vinokurov::CompositeShape testCompositeShape;

  BOOST_CHECK_THROW(testCompositeShape.add(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeExceptonUnderflow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.remove();

  BOOST_CHECK_THROW(testCompositeShape.remove(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeExceptionZeroSizeFrameRect)
{
  vinokurov::CompositeShape testCompositeShape;

  BOOST_CHECK_THROW(testCompositeShape.getFrameRect(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeExceptionInvalidScaling)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);

  BOOST_CHECK_THROW(testCompositeShape.scale(-8.8), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testCompositeShapeExceptionZeroScaling)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);

  BOOST_CHECK_THROW(testCompositeShape.scale(0.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
