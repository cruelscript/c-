#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include <stdexcept>
#include <cmath>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

BOOST_AUTO_TEST_SUITE(RecatangleTests)

  BOOST_AUTO_TEST_CASE(TestInvalidArgumentRectangle)
  {
    BOOST_CHECK_THROW(kubov::Rectangle rectangle({0.0, 0.0}, -3.0, 5.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovePointSideRectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({5.5, 7.4});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 5.5, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 7.4, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 2.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, 0.001);
  }


  BOOST_AUTO_TEST_CASE(TestMovePointAreaRectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 5.5);
    rectangle.move({6.4, 4.5});

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, 6.4, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, 4.5, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 11.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaSideRectangle)
  {
    const kubov::point_t center = {5.0, 7.0};
    kubov::Rectangle rectangle(center, 2.0, 5.5);

    double deltaX = 7.5;
    double deltaY = 2.8;
    rectangle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().width, 2.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getFrameRect().height, 5.5, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaAreaRectangle)
  {
    const kubov::point_t center = {5.0, 7.0};
    kubov::Rectangle rectangle(center, 2.0, 5.5);

    double deltaX = 4.4;
    double deltaY = 6.4;
    rectangle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(rectangle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 11.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestScaleAreaRectangle)
  {
    kubov::Rectangle rectangle({0.0, 0.0}, 2.0, 4.2);
    rectangle.scale(2.0);
    BOOST_CHECK_CLOSE_FRACTION(rectangle.getArea(), 4.0 * 8.4, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CircleTests)

  BOOST_AUTO_TEST_CASE(TestInvalidArgumentCircle)
  {
    BOOST_CHECK_THROW(kubov::Circle circle({0.0, 0.0}, -3.0), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMovePointRadiusCircle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move({5.5, 7.4});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, 5.5, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, 7.4, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMovePointAreaCircle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.move({6.4, 4.5});

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, 6.4, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, 4.5, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaRadiusCircle)
  {
    const kubov::point_t center = {5.0, 7.0};
    kubov::Circle circle(center, 2.0);

    double deltaX = 7.5;
    double deltaY = 2.8;
    circle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().width, 4.0, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(circle.getFrameRect().height, 4.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaAreaCircle)
  {
    const kubov::point_t center = {5.0, 7.0};
    kubov::Circle circle(center, 2.0);

    double deltaX = 4.4;
    double deltaY = 6.4;
    circle.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(circle.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), M_PI * 2.0 * 2.0, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestScaleAreaCircle)
  {
    kubov::Circle circle({0.0, 0.0}, 2.0);
    circle.scale(2.0);
    BOOST_CHECK_CLOSE_FRACTION(circle.getArea(), 4.0 * M_PI * 2.0 * 2.0, 0.001);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestCompositeShape)

  BOOST_AUTO_TEST_CASE(TestInvalidArgumentScale)
  {
    std::shared_ptr<kubov::Shape> circle = std::make_shared<kubov::Circle>(kubov::Circle({0, 0}, 10));
    kubov::CompositeShape compositeShape(circle);
    BOOST_CHECK_THROW(compositeShape.scale(-1), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestOutOfRangeDeleteElement)
  {
    std::shared_ptr<kubov::Shape> circle = std::make_shared<kubov::Circle>(kubov::Circle({0, 0}, 10));
    kubov::CompositeShape compositeShape(circle);
    BOOST_CHECK_THROW(compositeShape.deleteElement(2), std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(TestInsertNullPointer)
  {
    std::shared_ptr<kubov::Shape> circle00 = nullptr;
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 5));
    kubov::CompositeShape compositeShape(circle01);

    BOOST_CHECK_THROW(compositeShape.addElement(circle00), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(TestMoveCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({5, 5}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({-15, 15}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({-10.0, 10.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    compositeShape.move({15, 10});

    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenter().x, 15, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenter().y, 10, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestMoveDeltaCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({5, 5}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({-15, 15}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({-10.0, 10.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    const kubov::point_t center = compositeShape.getCenter();

    double deltaX = 4.4;
    double deltaY = 6.4;
    compositeShape.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenter().x, center.x + deltaX, 0.001);
    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getCenter().y, center.y + deltaY, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestAreaCompositeShape)
  {
    double allArea = 0;

    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({5, 5}, 25, 20));
    allArea += rectangle00->getArea();
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({-15, 15}, 20, 25));
    allArea += rectangle01->getArea();
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    allArea += circle00->getArea();
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({-10.0, 10.0}, 5));
    allArea += circle01->getArea();
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));
    allArea += circle02->getArea();

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getArea(), allArea, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestAreaMoveCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({5, 5}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({-15, 15}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({-10.0, 10.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    const kubov::point_t center = compositeShape.getCenter();
    double area = compositeShape.getArea();

    double deltaX = 4.4;
    double deltaY = 6.4;
    compositeShape.move(deltaX, deltaY);

    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.x, center.x + deltaX, 0.001);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getFrameRect().pos.y, center.y + deltaY, 0.001);

    BOOST_CHECK_CLOSE_FRACTION(compositeShape.getArea(), area, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestInsertCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({5, 5}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({-15, 15}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({-10.0, 10.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    BOOST_CHECK_EQUAL(compositeShape.getSize(), 9);
  }

  BOOST_AUTO_TEST_CASE(TestFrameRectangleCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().pos.x, 0);
    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().pos.y, 0);
    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().width, 50);
    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().height, 50);
  }

  BOOST_AUTO_TEST_CASE(TestAreaScaleCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({5, 5}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({-15, 15}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({-10.0, 10.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    double area =compositeShape.getArea();

    compositeShape.scale(4);

    BOOST_REQUIRE_EQUAL(compositeShape.getArea(), area * 16);
  }

  BOOST_AUTO_TEST_CASE(TestFrameRectScaleCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    compositeShape.scale(4);

    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().pos.x, 0);
    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().pos.y, 0);
    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().width, 50 * 4);
    BOOST_REQUIRE_EQUAL(compositeShape.getFrameRect().height, 50 * 4);
  }

  BOOST_AUTO_TEST_CASE(TestDeleteElementCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    BOOST_REQUIRE_EQUAL(compositeShape.getSize(), 5);

    double area = compositeShape.getArea();
    double deletedArea = compositeShape[0]->getArea();
    compositeShape.deleteElement(0);

    BOOST_REQUIRE_EQUAL(compositeShape.getSize(), 4);
    BOOST_REQUIRE_CLOSE_FRACTION(compositeShape.getArea(), area - deletedArea, 0.001);
  }

  BOOST_AUTO_TEST_CASE(TestClearCompositeShape)
  {
    std::shared_ptr<kubov::Shape> rectangle00 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 25, 20));
    std::shared_ptr<kubov::Shape> rectangle01 = std::make_shared<kubov::Rectangle>(kubov::Rectangle({0.0, 0.0}, 20, 25));
    std::shared_ptr<kubov::Shape> circle00 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 10));
    std::shared_ptr<kubov::Shape> circle01 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 5));
    std::shared_ptr<kubov::Shape> circle02 = std::make_shared<kubov::Circle>(kubov::Circle({0.0, 0.0}, 25));

    kubov::CompositeShape compositeShape(rectangle00);
    compositeShape.addElement(rectangle01);
    compositeShape.addElement(circle00);
    compositeShape.addElement(circle01);
    compositeShape.addElement(circle02);

    compositeShape.clear();

    BOOST_REQUIRE_EQUAL(compositeShape.getSize(), 0);
  }

BOOST_AUTO_TEST_SUITE_END()
