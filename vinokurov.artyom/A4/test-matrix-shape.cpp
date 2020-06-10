#include <stdexcept>
#include <memory>

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "composite-shape.hpp"
#include "matrix-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

const double EPSILON = 1e-10;

BOOST_AUTO_TEST_SUITE(MatrixShapeTest)

BOOST_AUTO_TEST_CASE(testMatrixShapeCopyConstructorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape copyCompositeShape;
  copyCompositeShape.add(testRectangle);

  vinokurov::MatrixShape copyMatrix(copyCompositeShape);

  BOOST_CHECK_NO_THROW(vinokurov::MatrixShape testMatrix(copyMatrix));
}

BOOST_AUTO_TEST_CASE(testMatrixShapeMoveConstructorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape compositeShape;
  compositeShape.add(testRectangle);

  vinokurov::MatrixShape matrix(compositeShape);

  BOOST_CHECK_NO_THROW(vinokurov::MatrixShape testMatrix(std::move(matrix)));
}

BOOST_AUTO_TEST_CASE(testMatrixShapeCopyAssignmentOperatorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape copyCompositeShape;
  copyCompositeShape.add(testRectangle);

  vinokurov::MatrixShape copyMatrix(copyCompositeShape);

  BOOST_CHECK_NO_THROW(vinokurov::MatrixShape testMatrix = copyMatrix);
}

BOOST_AUTO_TEST_CASE(testMatrixShapeMoveAssignmentOperatorNoThrow)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape compositeShape;
  compositeShape.add(testRectangle);

  vinokurov::MatrixShape matrix(compositeShape);

  BOOST_CHECK_NO_THROW(vinokurov::MatrixShape testMatrix = std::move(matrix));
}

BOOST_AUTO_TEST_CASE(testMatrixShapeCorrectFragmentation)
{
  vinokurov::CompositeShape::shapePtr part1 = 
    std::make_shared<vinokurov::Rectangle>(6, 4, vinokurov::point_t{3, 1});
  vinokurov::CompositeShape::shapePtr part2 = 
    std::make_shared<vinokurov::Circle>(2, vinokurov::point_t{7, 4});
  vinokurov::CompositeShape::shapePtr part3 = 
    std::make_shared<vinokurov::Rectangle>(4, 2, vinokurov::point_t{2, 5});

  vinokurov::rectangle_t part1Frame = part1->getFrameRect();
  vinokurov::rectangle_t part2Frame = part2->getFrameRect();
  vinokurov::rectangle_t part3Frame = part3->getFrameRect();

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(part1);
  testCompositeShape.add(part2);
  testCompositeShape.add(part3);

  vinokurov::MatrixShape matrix(testCompositeShape);

  BOOST_CHECK_EQUAL(matrix.getCols(), 2);
  BOOST_CHECK_EQUAL(matrix.getRows(), 2);

  BOOST_CHECK_CLOSE(matrix(0, 0)->getFrameRect().pos.x, part1Frame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(matrix(0, 0)->getFrameRect().pos.y, part1Frame.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(matrix(0, 0)->getFrameRect().width, part1Frame.width, EPSILON);
  BOOST_CHECK_CLOSE(matrix(0, 0)->getFrameRect().height, part1Frame.height, EPSILON);

  BOOST_CHECK_CLOSE(matrix(0, 1)->getFrameRect().pos.x, part3Frame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(matrix(0, 1)->getFrameRect().pos.y, part3Frame.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(matrix(0, 1)->getFrameRect().width, part3Frame.width, EPSILON);
  BOOST_CHECK_CLOSE(matrix(0, 1)->getFrameRect().height, part3Frame.height, EPSILON);

  BOOST_CHECK_CLOSE(matrix(1, 0)->getFrameRect().pos.x, part2Frame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(matrix(1, 0)->getFrameRect().pos.y, part2Frame.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(matrix(1, 0)->getFrameRect().width, part2Frame.width, EPSILON);
  BOOST_CHECK_CLOSE(matrix(1, 0)->getFrameRect().height, part2Frame.height, EPSILON);

  BOOST_CHECK_EQUAL(matrix(1, 1), nullptr);
}

BOOST_AUTO_TEST_CASE(testMatrixShapeExceptionAddingEmptyShape)
{
  vinokurov::CompositeShape compositeShape;

  BOOST_CHECK_THROW(vinokurov::MatrixShape matrix(compositeShape), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testMatrixShapeExceptionAddingNullptr)
{
  vinokurov::MatrixShape matrix;

  BOOST_CHECK_THROW(matrix.add(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testMatrixSHapeInvalidIndex)
{
  vinokurov::CompositeShape::shapePtr testRectangle =
    std::make_shared<vinokurov::Rectangle>(5.5, 5.5, vinokurov::point_t{1.1, 1.1});

  vinokurov::CompositeShape testCompositeShape;
  testCompositeShape.add(testRectangle);

  vinokurov::MatrixShape matrix(testCompositeShape);

  BOOST_CHECK_THROW(matrix(5, 5), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
