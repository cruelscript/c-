#define BOOST_TEST_MODULE A2_UNIT_TEST

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>
#include <cmath>
#include <stdexcept>

#include "circle.hpp"
#include "rectangle.hpp"

const double EPSILON = 1e-6;

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(TestCircleConstructorWithCorrectArguments)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;

  BOOST_CHECK_NO_THROW(prishchepa::Circle({posX, posY}, radius));
}

BOOST_AUTO_TEST_CASE(TestCircleConstructorWithIncorrectRadius)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double negativeRadius = -5.0;
  const double zeroRadius = 0.0;

  BOOST_CHECK_THROW(prishchepa::Circle({posX, posY}, negativeRadius), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Circle({posX, posY}, zeroRadius), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestCircleGetArea)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;

  const double expectedArea = M_PI * radius * radius;

  prishchepa::Circle circle({posX, posY}, radius);

  BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectedArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestCircleGetFrameRect)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;

  const double expectedFrameRectWidth = radius * 2.0;
  const double expectedFrameRectHeight = radius * 2.0;
  const double expectedFrameRectPosX = posX;
  const double expectedFrameRectPosY = posY;

  prishchepa::Circle circle({posX, posY}, radius);

  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestCircleScaleWithCorrectFactor)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;
  const double scaleFactor = 4.0;

  const double expectedPosX = posX;
  const double expectedPosY = posY;
  const double expectedRadius = radius * scaleFactor;
  const double expectedArea = M_PI * radius * radius * scaleFactor * scaleFactor;
  const double expectedFrameRectWidth = radius * 2.0 * scaleFactor;
  const double expectedFrameRectHeight = radius * 2.0 * scaleFactor;
  const double expectedFrameRectPosX = posX;
  const double expectedFrameRectPosY = posY;

  prishchepa::Circle circle({posX, posY}, radius);
  circle.scale(scaleFactor);

  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().y, expectedPosY, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getRadius(), expectedRadius, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectedArea, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestCircleScaleWithIncorrectFactor)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;
  const double negativeScaleFactor = -4.0;
  const double zeroScaleFactor = 0.0;

  prishchepa::Circle circle({posX, posY}, radius);

  BOOST_CHECK_THROW(circle.scale(negativeScaleFactor), std::invalid_argument);
  BOOST_CHECK_THROW(circle.scale(zeroScaleFactor), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestCircleGetRadius)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;

  const double expectedRadius = radius;

  prishchepa::Circle circle({posX, posY}, radius);

  BOOST_CHECK_CLOSE_FRACTION(circle.getRadius(), expectedRadius, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestCircleMoveToPoint)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;
  const double destinationX = 28.0;
  const double destinationY = 17.0;

  const double expectedPosX = destinationX;
  const double expectedPosY = destinationY;
  const double expectedRadius = radius;
  const double expectedArea = M_PI * radius * radius;
  const double expectedFrameRectWidth = radius * 2.0;
  const double expectedFrameRectHeight = radius * 2.0;
  const double expectedFrameRectPosX = destinationX;
  const double expectedFrameRectPosY = destinationY;

  prishchepa::Circle circle({posX, posY}, radius);
  circle.move({destinationX, destinationY});

  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().y, expectedPosY, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getRadius(), expectedRadius, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectedArea, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestCircleMoveByOffset)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;
  const double deltaX = 28.0;
  const double deltaY = 17.0;

  const double expectedPosX = posX + deltaX;
  const double expectedPosY = posY + deltaY;
  const double expectedRadius = radius;
  const double expectedArea = M_PI * radius * radius;
  const double expectedFrameRectWidth = radius * 2.0;
  const double expectedFrameRectHeight = radius * 2.0;
  const double expectedFrameRectPosX = posX + deltaX;
  const double expectedFrameRectPosY = posY + deltaY;

  prishchepa::Circle circle({posX, posY}, radius);
  circle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().y, expectedPosY, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getRadius(), expectedRadius, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), expectedArea, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestCircleGetPosition)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double radius = 5.0;

  const double expectedPosX = posX;
  const double expectedPosY = posY;

  prishchepa::Circle circle({posX, posY}, radius);

  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(circle.getPosition().y, expectedPosY, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(TestRectangleConstructorWithCorrectArguments)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;

  BOOST_CHECK_NO_THROW(prishchepa::Rectangle({posX, posY}, width, height));
}

BOOST_AUTO_TEST_CASE(TestRectangleConstructorWithIncorrectSize)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double correctWidth = 15.0;
  const double correctHeight = 25.0;
  const double negativeWidth = -15.0;
  const double negativeHeight = -25.0;
  const double zeroWidth = 0.0;
  const double zeroHeight = 0.0;

  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, correctWidth, negativeHeight), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, correctWidth, zeroHeight), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, negativeWidth, correctHeight), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, negativeWidth, negativeHeight), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, negativeWidth, zeroHeight), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, zeroWidth, correctHeight), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, zeroWidth, negativeHeight), std::invalid_argument);
  BOOST_CHECK_THROW(prishchepa::Rectangle({posX, posY}, zeroWidth, zeroHeight), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestRectangleGetArea)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;

  const double expectedArea = width * height;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectedArea, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestRectangleGetFrameRect)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;

  const double expectedFrameRectWidth = width;
  const double expectedFrameRectHeight = height;
  const double expectedFrameRectPosX = posX;
  const double expectedFrameRectPosY = posY;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestRectangleScaleWithCorrectFactor)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;
  const double scaleFactor = 4.0;

  const double expectedPosX = posX;
  const double expectedPosY = posY;
  const double expectedWidth = width * scaleFactor;
  const double expectedHeight = height * scaleFactor;
  const double expectedArea = width * height * scaleFactor * scaleFactor;
  const double expectedFrameRectWidth = width * scaleFactor;
  const double expectedFrameRectHeight = height * scaleFactor;
  const double expectedFrameRectPosX = posX;
  const double expectedFrameRectPosY = posY;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);
  rectangle.scale(scaleFactor);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().y, expectedPosY, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getWidth(), expectedWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getHeight(), expectedHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectedArea, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestRectangleScaleWithIncorrectFactor)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;
  const double negativeScaleFactor = -4.0;
  const double zeroScaleFactor = 0.0;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);

  BOOST_CHECK_THROW(rectangle.scale(negativeScaleFactor), std::invalid_argument);
  BOOST_CHECK_THROW(rectangle.scale(zeroScaleFactor), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestRectangleGetWidthAndGetHeight)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;

  const double expectedWidth = width;
  const double expectedHeight = height;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getWidth(), expectedWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getHeight(), expectedHeight, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestRectangleMoveToPoint)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;
  const double destinationX = 34.0;
  const double destinationY = 28.0;

  const double expectedPosX = destinationX;
  const double expectedPosY = destinationY;
  const double expectedWidth = width;
  const double expectedHeight = height;
  const double expectedArea = width * height;
  const double expectedFrameRectWidth = width;
  const double expectedFrameRectHeight = height;
  const double expectedFrameRectPosX = destinationX;
  const double expectedFrameRectPosY = destinationY;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);
  rectangle.move({destinationX, destinationY});

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().y, expectedPosY, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getWidth(), expectedWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getHeight(), expectedHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectedArea, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestRectangleMoveByOffset)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;
  const double deltaX = 34.0;
  const double deltaY = 28.0;

  const double expectedPosX = posX + deltaX;
  const double expectedPosY = posY + deltaY;
  const double expectedWidth = width;
  const double expectedHeight = height;
  const double expectedArea = width * height;
  const double expectedFrameRectWidth = width;
  const double expectedFrameRectHeight = height;
  const double expectedFrameRectPosX = posX + deltaX;
  const double expectedFrameRectPosY = posY + deltaY;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);
  rectangle.move(deltaX, deltaY);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().y, expectedPosY, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getWidth(), expectedWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getHeight(), expectedHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), expectedArea, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, expectedFrameRectWidth, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, expectedFrameRectHeight, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, expectedFrameRectPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, expectedFrameRectPosY, EPSILON);
}

BOOST_AUTO_TEST_CASE(TestRectangleGetPosition)
{
  const double posX = 10.0;
  const double posY = 10.0;
  const double width = 15.0;
  const double height = 25.0;

  const double expectedPosX = posX;
  const double expectedPosY = posY;

  prishchepa::Rectangle rectangle({posX, posY}, width, height);

  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().x, expectedPosX, EPSILON);
  BOOST_CHECK_CLOSE_FRACTION(rectangle.getPosition().y, expectedPosY, EPSILON);
}


BOOST_AUTO_TEST_SUITE_END()
