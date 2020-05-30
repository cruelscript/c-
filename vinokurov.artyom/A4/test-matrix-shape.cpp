#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "composite-shape.hpp"
#include "matrix-shape.hpp"
#include "rectangle.hpp"

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

BOOST_AUTO_TEST_SUITE_END()
