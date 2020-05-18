#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <stdexcept>
#include <utility>

#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

using shape_ptr = std::shared_ptr<gabdullina::Shape>;
const double ACCURACY_VALUE = 1e-10;

BOOST_AUTO_TEST_SUITE(compositeShapeTestSuite)

BOOST_AUTO_TEST_CASE(testFigureAfterMovingToPoint)
{
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(2, 3, 5.6, 4.7);
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(3, 3, 4.8);
  gabdullina::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  const double widthBefore = testCompositeShape.getFrameRect().width;
  const double heightBefore = testCompositeShape.getFrameRect().height;
  const double areaShapeBefore = testCompositeShape.getArea();

  testCompositeShape.move({1.4, 1.7});
  const double xCoordinateAfter = testCompositeShape.getPos().x;
  const double yCoordinateAfter = testCompositeShape.getPos().y;
  const double widthAfter = testCompositeShape.getFrameRect().width;
  const double heightAfter = testCompositeShape.getFrameRect().height;
  const double areaShapeAfter = testCompositeShape.getArea();

  BOOST_CHECK_CLOSE(xCoordinateAfter, 1.4, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(yCoordinateAfter, 1.7, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(widthBefore, widthAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(heightBefore, heightAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(areaShapeBefore, areaShapeAfter, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testFigureAfterMovingAlongAxes)
{
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(2, 3, 5.6, 4.7);
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(3, 3, 4.8);
  gabdullina::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  const double xCoordinateBefore = testCompositeShape.getPos().x;
  const double yCoordinateBefore = testCompositeShape.getPos().y;
  const double widthBefore = testCompositeShape.getFrameRect().width;
  const double heightBefore = testCompositeShape.getFrameRect().height;
  const double areaShapeBefore = testCompositeShape.getArea();

  testCompositeShape.move(3.2, 6.1);
  const double xCoordinateAfter = testCompositeShape.getPos().x;
  const double yCoordinateAfter = testCompositeShape.getPos().y;
  const double widthAfter = testCompositeShape.getFrameRect().width;
  const double heightAfter = testCompositeShape.getFrameRect().height;
  const double areaShapeAfter = testCompositeShape.getArea();

  BOOST_CHECK_CLOSE(xCoordinateAfter, xCoordinateBefore + 3.2, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(yCoordinateAfter, yCoordinateBefore + 6.1, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(widthBefore, widthAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(heightBefore, heightAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(areaShapeBefore, areaShapeAfter, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testFigureAfterScaling)
{
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(1, 2, 3.7, 5);
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(4, 3, 1.2);
  gabdullina::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  const double xCoordinateBefore = testCompositeShape.getPos().x;
  const double yCoordinateBefore = testCompositeShape.getPos().y;
  const double areaShapeBefore = testCompositeShape.getArea();

  testCompositeShape.scale(1.25);
  const double xCoordinateAfter = testCompositeShape.getPos().x;
  const double yCoordinateAfter = testCompositeShape.getPos().y;
  const double areaShapeAfter = testCompositeShape.getArea();

  BOOST_CHECK_CLOSE(xCoordinateBefore, xCoordinateAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(yCoordinateBefore, yCoordinateAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(areaShapeAfter, areaShapeBefore * 1.25 * 1.25, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testPartsOfCompositeShapeAfterMoving)
{
  gabdullina::CompositeShape testCompositeShape;
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(1.2, -2.3, 3);
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(3.1, 2.2, 4, 5);
  testCompositeShape.add(testCircle);
  testCompositeShape.add(testRectangle);

  const gabdullina::point_t centerOfCompositeShapeBefore = testCompositeShape.getPos();
  const gabdullina::point_t centerOfCircleBefore = testCompositeShape[0]->getPos();
  const double radiusOfCircleBefore = testCompositeShape[0]->getFrameRect().width/2;
  const gabdullina::point_t centerOfRectangleBefore = testCompositeShape[1]->getPos();
  const double widthOfRectangleBefore = testCompositeShape[1]->getFrameRect().width;
  const double heightOfRectangleBefore = testCompositeShape[1]->getFrameRect().height;

  testCompositeShape.move({1, 2});
  const gabdullina::point_t centerOfCircleAfter = testCompositeShape[0]->getPos();
  const double radiusOfCircleAfter = testCompositeShape[0]->getFrameRect().width/2;
  const gabdullina::point_t centerOfRectangleAfter = testCompositeShape[1]->getPos();
  const double widthOfRectangleAfter = testCompositeShape[1]->getFrameRect().width;
  const double heightOfRectangleAfter = testCompositeShape[1]->getFrameRect().height;
  const double deltaX = 1 - centerOfCompositeShapeBefore.x;
  const double deltaY = 2 - centerOfCompositeShapeBefore.y;

  BOOST_CHECK_CLOSE(centerOfCircleBefore.x + deltaX, centerOfCircleAfter.x, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(centerOfCircleBefore.y + deltaY, centerOfCircleAfter.y, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(radiusOfCircleBefore, radiusOfCircleAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(centerOfRectangleBefore.x + deltaX, centerOfRectangleAfter.x, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(centerOfRectangleBefore.y + deltaY, centerOfRectangleAfter.y, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(widthOfRectangleBefore, widthOfRectangleAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(heightOfRectangleBefore, heightOfRectangleAfter, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testPartsOfCompositeShapeAfterScaling)
{
  gabdullina::CompositeShape testCompositeShape;
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(4.5, 6.4, 2.1, 2.3);
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(4.3, 2.3, 1.7);
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);

  const gabdullina::point_t centerOfCompositeShapeBefore = testCompositeShape.getPos();
  const gabdullina::point_t centerOfCircleBefore = testCompositeShape[0]->getPos();
  const double radiusOfCircleBefore = testCompositeShape[0]->getFrameRect().width/2;
  const gabdullina::point_t centerOfRectangleBefore = testCompositeShape[1]->getPos();
  const double widthOfRectangleBefore = testCompositeShape[1]->getFrameRect().width;
  const double heightOfRectangleBefore = testCompositeShape[1]->getFrameRect().height;

  testCompositeShape.scale(1.25);
  const gabdullina::point_t centerOfCircleAfter = testCompositeShape[0]->getPos();
  const double radiusOfCircleAfter = testCompositeShape[0]->getFrameRect().width/2;
  const gabdullina::point_t centerOfRectangleAfter = testCompositeShape[1]->getPos();
  const double widthOfRectangleAfter = testCompositeShape[1]->getFrameRect().width;
  const double heightOfRectangleAfter = testCompositeShape[1]->getFrameRect().height;
  const double deltaXOfCircle = (centerOfCircleBefore.x - centerOfCompositeShapeBefore.x) * 1.25;
  const double deltaYOfCircle = (centerOfCircleBefore.y - centerOfCompositeShapeBefore.y) * 1.25;
  const double deltaXOfRectangle = (centerOfRectangleBefore.x - centerOfCompositeShapeBefore.x) * 1.25;
  const double deltaYOfRectangle = (centerOfRectangleBefore.y - centerOfCompositeShapeBefore.y) * 1.25;

  BOOST_CHECK_CLOSE(centerOfCompositeShapeBefore.x + deltaXOfCircle, centerOfCircleAfter.x, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(centerOfCompositeShapeBefore.y + deltaYOfCircle, centerOfCircleAfter.y, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(radiusOfCircleBefore * 1.25, radiusOfCircleAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(centerOfCompositeShapeBefore.x + deltaXOfRectangle, centerOfRectangleAfter.x, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(centerOfCompositeShapeBefore.y + deltaYOfRectangle, centerOfRectangleAfter.y, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(widthOfRectangleBefore * 1.25, widthOfRectangleAfter, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(heightOfRectangleBefore * 1.25, heightOfRectangleAfter, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testConstructors)
{
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(1, 2, 4);
  gabdullina::CompositeShape testComposite1;
  testComposite1.add(testCircle);

  gabdullina::CompositeShape testComposite2(testComposite1);

  BOOST_CHECK_CLOSE(testComposite1.getPos().x, testComposite2.getPos().x, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getPos().y, testComposite2.getPos().y, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getFrameRect().height, testComposite2.getFrameRect().height, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getFrameRect().width, testComposite2.getFrameRect().width, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getArea(), testComposite2.getArea(), ACCURACY_VALUE);

  BOOST_CHECK_NO_THROW(gabdullina::CompositeShape testComposite3(testComposite1));
  BOOST_CHECK_NO_THROW(gabdullina::CompositeShape testComposite3(std::move(testComposite1)));
}

BOOST_AUTO_TEST_CASE(testAssignmentOperator)
{
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(2, 4, 5, 6);
  gabdullina::CompositeShape testComposite1;
  testComposite1.add(testRectangle);

  gabdullina::CompositeShape testComposite2;
  testComposite2 = testComposite1;
  gabdullina::CompositeShape testComposite3;

  BOOST_CHECK_CLOSE(testComposite1.getPos().x, testComposite2.getPos().x, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getPos().y, testComposite2.getPos().y, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getFrameRect().height, testComposite2.getFrameRect().height, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getFrameRect().width, testComposite2.getFrameRect().width, ACCURACY_VALUE);
  BOOST_CHECK_CLOSE(testComposite1.getArea(), testComposite2.getArea(), ACCURACY_VALUE);

  BOOST_CHECK_NO_THROW(testComposite3 = testComposite1);
  BOOST_CHECK_NO_THROW(testComposite3 = std::move(testComposite1));
}

BOOST_AUTO_TEST_CASE(testCopyingAndMoving)
{
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(3, -2, 5);
  gabdullina::CompositeShape testCompositeShape0;
  testCompositeShape0.add(testCircle);

  gabdullina::CompositeShape testCompositeShape1;
  testCompositeShape1 = testCompositeShape0;

  gabdullina::CompositeShape testCompositeShape2;
  testCompositeShape2 = testCompositeShape1;

  gabdullina::CompositeShape testCompositeShape3;
  testCompositeShape3 = testCompositeShape1;

  gabdullina::CompositeShape testCompositeShape4;
  testCompositeShape4 = std::move(testCompositeShape1);
  gabdullina::CompositeShape testCompositeShape5(testCompositeShape2);
  gabdullina::CompositeShape testCompositeShape6(std::move(testCompositeShape2));

  BOOST_CHECK(testCompositeShape3 == testCompositeShape0);
  BOOST_CHECK(testCompositeShape4 == testCompositeShape0);
  BOOST_CHECK(testCompositeShape5 == testCompositeShape0);
  BOOST_CHECK(testCompositeShape6 == testCompositeShape0);
}

BOOST_AUTO_TEST_CASE(testMethodGetSizeInMethodAdd)
{
  gabdullina::CompositeShape testCompositeShape;
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(1, 2, 3);
  testCompositeShape.add(testCircle);
  const double sizeBefore = testCompositeShape.getSize();

  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(1, 2, 3, 4);
  testCompositeShape.add(testRectangle);
  const double sizeAfter = testCompositeShape.getSize();

  BOOST_CHECK_CLOSE(sizeBefore + 1, sizeAfter, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testMethodGetSizeInMethodRemove)
{
  gabdullina::CompositeShape testCompositeShape;
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(1, 2, 3, 4);
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(1, 2, 3);
  testCompositeShape.add(testRectangle);
  testCompositeShape.add(testCircle);
  const double sizeBefore = testCompositeShape.getSize();

  testCompositeShape.remove();
  const double sizeAfter = testCompositeShape.getSize();

  BOOST_CHECK_CLOSE(sizeBefore, sizeAfter + 1, ACCURACY_VALUE);
}

BOOST_AUTO_TEST_CASE(testExceptionWithInvalidIndex)
{
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(-1, 1, 3, 4);
  gabdullina::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);

  BOOST_CHECK_THROW(testCompositeShape[200], std::out_of_range);
  BOOST_CHECK_THROW(testCompositeShape[-5], std::out_of_range);
}

BOOST_AUTO_TEST_CASE(testExceptionWithAdd)
{
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(4, 3, 5);
  gabdullina::CompositeShape testCompositeShape;
  testCompositeShape.add(testCircle);

  BOOST_CHECK_THROW(testCompositeShape.add(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testExceptionWithRemove)
{
  shape_ptr testCircle = std::make_shared<gabdullina::Circle>(1, 2, 4);
  gabdullina::CompositeShape testCompositeShape;
  testCompositeShape.add(testCircle);

  testCompositeShape.remove();
  BOOST_CHECK_THROW(testCompositeShape.remove(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(testExceptionWithScale)
{
  shape_ptr testRectangle = std::make_shared<gabdullina::Rectangle>(-2, 1, 6, 3);
  gabdullina::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);

  BOOST_CHECK_THROW(testCompositeShape.scale(-4), std::invalid_argument);
  BOOST_CHECK_THROW(testCompositeShape.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
