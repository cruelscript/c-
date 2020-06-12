#include <stdexcept>
#include <memory>

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "layer.hpp"
#include "shape.hpp"
#include "rectangle.hpp"

const double EPSILON = 1e-10;

BOOST_AUTO_TEST_SUITE(LayerTest)

BOOST_AUTO_TEST_CASE(testLayerCopyConstructorNoThrow)
{
  vinokurov::Layer::shapePtr shape = 
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer copyLayer(array, 1);

  BOOST_CHECK_NO_THROW(vinokurov::Layer testLayer(copyLayer));
}

BOOST_AUTO_TEST_CASE(testLayerCopyConstructorCopying)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer copyLayer(array, 1);
  vinokurov::rectangle_t copyFrame = copyLayer[0]->getFrameRect();

  vinokurov::Layer testLayer(copyLayer);

  vinokurov::rectangle_t testFrame = testLayer[0]->getFrameRect();

  BOOST_CHECK_EQUAL(copyLayer.size(), testLayer.size());

  BOOST_CHECK_CLOSE(copyFrame.height, testFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(copyFrame.width, testFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(copyFrame.pos.x, testFrame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(copyFrame.pos.y, testFrame.pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(testLayerMoveConstructorNoThrow)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer layer(array, 1);

  BOOST_CHECK_NO_THROW(vinokurov::Layer testLayer(std::move(layer)));
}

BOOST_AUTO_TEST_CASE(testLayerMoveConstructorMoving)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer layer(array, 1);
  vinokurov::rectangle_t moveFrame = layer[0]->getFrameRect();

  vinokurov::Layer testLayer(std::move(layer));

  vinokurov::rectangle_t testFrame = testLayer[0]->getFrameRect();

  BOOST_CHECK_CLOSE(moveFrame.height, testFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(moveFrame.width, testFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(moveFrame.pos.x, testFrame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(moveFrame.pos.y, testFrame.pos.y, EPSILON);

  BOOST_CHECK_EQUAL(layer.size(), 0);
}

BOOST_AUTO_TEST_CASE(testLayerCopyAssignmentOperatorNoThrow)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer copyLayer(array, 1);

  BOOST_CHECK_NO_THROW(vinokurov::Layer testLayer = copyLayer);
}

BOOST_AUTO_TEST_CASE(testLayerCopyAssignmentOperatorCopying)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer copyLayer(array, 1);
  vinokurov::rectangle_t copyFrame = copyLayer[0]->getFrameRect();

  vinokurov::Layer testLayer = copyLayer;

  vinokurov::rectangle_t testFrame = testLayer[0]->getFrameRect();

  BOOST_CHECK_EQUAL(copyLayer.size(), testLayer.size());

  BOOST_CHECK_CLOSE(copyFrame.height, testFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(copyFrame.width, testFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(copyFrame.pos.x, testFrame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(copyFrame.pos.y, testFrame.pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(testLayerMoveAssignmentOperatorNoThrow)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer layer(array, 1);

  BOOST_CHECK_NO_THROW(vinokurov::Layer testLayer = std::move(layer));
}

BOOST_AUTO_TEST_CASE(testLayerMoveAssignmentOperatorMoving)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer layer(array, 1);
  vinokurov::rectangle_t moveFrame = layer[0]->getFrameRect();

  vinokurov::Layer testLayer = std::move(layer);

  vinokurov::rectangle_t testFrame = testLayer[0]->getFrameRect();

  BOOST_CHECK_CLOSE(moveFrame.height, testFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(moveFrame.width, testFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(moveFrame.pos.x, testFrame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(moveFrame.pos.y, testFrame.pos.y, EPSILON);

  BOOST_CHECK_EQUAL(layer.size(), 0);
}

BOOST_AUTO_TEST_CASE(testLayerExceptionInvalidIndex)
{
  vinokurov::Layer::shapePtr shape =
    std::make_shared<vinokurov::Rectangle>(5.5, 7.7, vinokurov::point_t{1.1, 1.1});
  vinokurov::Layer::shapeArray array(std::make_unique<vinokurov::Layer::shapePtr[]>(1));
  array[0] = shape;

  vinokurov::Layer layer(array, 1);

  BOOST_CHECK_THROW(layer[5], std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
