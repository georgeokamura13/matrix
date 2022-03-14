#include "../Matrix.h"
#include <gtest/gtest.h>
using namespace std;

double** generateTestArray(double* data, int rows, int cols) {
	double** array;
	array = new double* [rows];
	for (int i = 0; i < rows; i++) {
		array[i] = new double[cols];
	}
	int counter = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			array[i][j] = data[counter];
			counter++;
		}
	}
	return array;
}

///
/// MatrixTest: basic test cases to validate the == operator
///

/// Standard == test case to check arithmatric comparison between two matrices
TEST(MatrixComparisonTest, TestMatrixEmpty) {
	double** array= nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = Matrix<double>(array, 0, 0);
	EXPECT_TRUE(sut == other_matrix);
	delete array;
}

/// Standard == test case to check pointer comparison between two addresses of matrices
TEST(MatrixComparisonTest, TestMatrixAddressEmpty) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = Matrix<double>(array, 0, 0);
	EXPECT_FALSE(&sut == &other_matrix);
	delete array;
}

/// Standard equals() test case to check comparison between two matrices
TEST(MatrixComparisonTest, TestMatrixEmptyEquals) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = Matrix<double>(array, 0, 0);
	EXPECT_TRUE(sut.equals(other_matrix));
	delete array;
}

/// Standard == test case to check arithmatric comparison between two matrices
/// compares populated matrices
TEST(MatrixComparisonTest, TestMatrixEquals) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	Matrix<double> other_matrix = Matrix<double>(array1, rows, cols);
	EXPECT_TRUE(sut == other_matrix);
	delete array1;
}

/// Standard == test case to check arithmatric comparison between two matrices 
/// compares populated matrices that are different sizes
TEST(MatrixComparisonTest, TestMatrixDifferentSize) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	Matrix<double> other_matrix = Matrix<double>(array1, 1, 1);
	EXPECT_FALSE(sut == other_matrix);
	delete array1;
}

/// Standard == test case to check arithmatric comparison between two matrices 
/// compares populated matrices that hold different values
TEST(MatrixComparisonTest, TestMatrixDifferentValue) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	array1[1][1] = 100;
	Matrix<double> other_matrix = Matrix<double>(array1, rows, cols);
	EXPECT_FALSE(sut == other_matrix);
	delete array1;
}

///
/// MatrixNegativeTest: basic negative test cases to validate the != operator
///

/// Standard != test case to check arithmatric comparison between two matrices
TEST(MatrixNegativeComparisonTest, TestMatrixEmpty) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = Matrix<double>(array, 0, 0);
	EXPECT_FALSE(sut != other_matrix);
	delete array;
}

/// Standard != test case to check pointer comparison between two addresses of matrices
TEST(MatrixNegativeComparisonTest, TestMatrixAddressEmpty) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = Matrix<double>(array, 0, 0);
	EXPECT_TRUE(&sut != &other_matrix);
	delete array;
}

/// Standard equals() test case to check comparison between two matrices
TEST(MatrixNegativeComparisonTest, TestMatrixEmptyEquals) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = Matrix<double>(array, 0, 0);
	EXPECT_FALSE(!sut.equals(other_matrix));
	delete array;
}

/// Standard != test case to check arithmatric comparison between two matrices
/// compares populated matrices
TEST(MatrixNegativeComparisonTest, TestMatrixEquals) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	Matrix<double> other_matrix = Matrix<double>(array1, rows, cols);
	EXPECT_FALSE(sut != other_matrix);
	delete array1;
}

/// Standard != test case to check arithmatric comparison between two matrices 
/// compares populated matrices that are different sizes
TEST(MatrixNegativeComparisonTest, TestMatrixDifferentSize) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	Matrix<double> other_matrix = Matrix<double>(array1, 1, 1);
	EXPECT_TRUE(sut != other_matrix);
	delete array1;
}

/// Standard != test case to check arithmatric comparison between two matrices 
/// compares populated matrices that hold different values
TEST(MatrixNegativeComparisonTest, TestMatrixDifferentValue) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	array1[1][1] = 100;
	Matrix<double> other_matrix = Matrix<double>(array1, rows, cols);
	EXPECT_TRUE(sut != other_matrix);
	delete array1;
}

/// 
/// Matrix Move Constructor Tests
/// 

/// Move Constructor Test with Empty Matrices
TEST(MatrixMoveTest, TestMatrixMoveEmpty) {
	double** array= nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = std::move(sut);
	EXPECT_TRUE(sut == other_matrix);
}

/// Move Constructor Test with Populated Matrices
TEST(MatrixMoveTest, TestMatrixTwoByTwoMove) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	Matrix<double> other_matrix = std::move(sut);
	EXPECT_TRUE(sut == other_matrix);
}

/// Move Constructor Test with Addresses of Populated Matrices
TEST(MatrixMoveTest, TestMatrixAddressTwoByTwoMove) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	Matrix<double> other_matrix = std::move(sut);
	EXPECT_TRUE(sut == other_matrix);
	delete array;
}

/// 
/// Matrix Copy Constructor Tests
/// 

/// Copy Constructor test case to check arithmatric comparison between two matrices 
TEST(MatrixCopyTest, TestMatrixCopyEmpty) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = sut;
	EXPECT_TRUE(sut == other_matrix);
	delete array;
}

/// Copy Constructor test case to check pointer comparison between two addresses of matrices 
TEST(MatrixCopyTest, TestMatrixAddressCopyEmpty) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = sut;
	EXPECT_TRUE(sut == other_matrix);
	delete array;
}

/// Copy Constructor test case to check comparison between two matrices
TEST(MatrixCopyTest, TestMatrixEmptyCopyEquals) {
	double** array = nullptr;
	Matrix<double> sut = Matrix<double>(array, 0, 0);
	Matrix<double> other_matrix = sut;
	EXPECT_TRUE(sut == other_matrix);
	delete array;
}

/// Copy Constructor test case to check arithmatric comparison between two matrices
/// compares populated matrices
TEST(MatrixCopyTest, TestPopulatedMatrix) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	Matrix<double> other_matrix = sut;
	EXPECT_TRUE(sut == other_matrix);
	delete array1;
}


/// 
/// Matrix Transpose Tests
/// 

/// Transpose test case with an empty matrix 
TEST(MatrixTransposeTest, TestMatrixEmptyTranspose) {
	Matrix<double> sut = Matrix<double>(0, 0);
	Matrix<double> other_matrix = Matrix<double>(0, 0);
	EXPECT_TRUE(sut.transpose() == other_matrix);
}

/// Transpose test case with a one-by-one matrix 
TEST(MatrixTransposeTest, TestMatrixOneByOneTranspose) {
	int rows = 1;
	int cols = 1;
	Matrix<double> sut = Matrix<double>(rows, cols);
	Matrix<double> other_matrix = Matrix<double>(cols, rows);
	EXPECT_TRUE(sut.transpose() == other_matrix);
}

/// Transpose test case with a two-by-two matrix 
TEST(MatrixTransposeTest, TestMatrixTwoByTwoTranspose) {
	const int rows = 2;
	const int cols = 2;
	double data1[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr1 = data1;
	double** array1 = generateTestArray(dataptr1, rows, cols);
	double data2[rows * cols] = { 1, 3, 2, 4 };
	double* dataptr2 = data2;
	double** array2 = generateTestArray(dataptr2, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	Matrix<double> other_matrix = Matrix<double>(array2, cols, rows);
	EXPECT_TRUE(sut.transpose() == other_matrix);
	delete array1;
	delete array2;
}

/// Transpose test case with a one-by-four matrix 
TEST(MatrixTransposeTest, TestMatrixOneByFourTranspose) {
	const int rows1 = 1;
	const int cols1 = 4;
	double data1[rows1 * cols1] = { 1, 2, 3, 4 };
	double* dataptr1 = data1;
	double** array1 = generateTestArray(dataptr1, rows1, cols1);
	const int rows2 = 4;
	const int cols2 = 1;
	double data2[rows2 * cols2] = { 1, 2, 3, 4 };
	double* dataptr2 = data2;
	double** array2 = generateTestArray(dataptr2, rows2, cols2);
	Matrix<double> sut = Matrix<double>(array1, rows1, cols1);
	Matrix<double> other_matrix = Matrix<double>(array2, rows2, cols2);
	EXPECT_TRUE(sut.transpose() == other_matrix);
	delete array1;
	delete array2;
}

/// Transpose test case with a four-by-one matrix 
TEST(MatrixTransposeTest, TestMatrixFourByOneTranspose) {
	const int rows1 = 4;
	const int cols1 = 1;
	double data1[rows1 * cols1] = { 1, 2, 3, 4 };
	double* dataptr1 = data1;
	double** array1 = generateTestArray(dataptr1, rows1, cols1);
	const int rows2 = 1;
	const int cols2 = 4;
	double data2[rows2 * cols2] = { 1, 2, 3, 4 };
	double* dataptr2 = data2;
	double** array2 = generateTestArray(dataptr2, rows2, cols2);
	Matrix<double> sut = Matrix<double>(array1, rows1, cols1);
	Matrix<double> other_matrix = Matrix<double>(array2, rows2, cols2);
	EXPECT_TRUE(sut.transpose() == other_matrix);
	delete array1;
	delete array2;
}

/// 
/// Matrix Multiplication Tests
/// 

/// Matrix Multiplication test case with an empty matrix 
TEST(MatrixMultiplyTest, TestMatrixEmptyMultiply) {
	int rows = 0;
	int cols = 0;
	Matrix<double> sut = Matrix<double>(rows, cols);
	Matrix<double> other_matrix = Matrix<double>(cols, rows);
	Matrix<double> actual = sut * other_matrix;
	EXPECT_TRUE(actual == other_matrix);
}

/// Matrix Multiplication test case with one-by-one matrices
TEST(MatrixMultiplyTest, TestMatrixOneByOneMultiply) {
	int rows = 1;
	int cols = 1;
	Matrix<double> sut = Matrix<double>(rows, cols);
	Matrix<double> other_matrix = Matrix<double>(cols, rows);
	Matrix<double> actual = sut * other_matrix;
	EXPECT_TRUE(actual == other_matrix);
}

/// Matrix Multiplication test case with a two-by-two matrices
TEST(MatrixMultiplyTest, TestMatrixTwoByTwoMultiply) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array1 = generateTestArray(dataptr, rows, cols);
	double** array2 = generateTestArray(dataptr, rows, cols);
	double resultData[rows * cols] = { 7, 10, 15, 22 };
	double* resultDataptr = resultData;
	double** product = generateTestArray(resultDataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array1, rows, cols);
	Matrix<double> other_matrix = Matrix<double>(array2, rows, cols);
	Matrix<double> expected = Matrix<double>(product, rows, cols);
	Matrix<double> actual = sut * other_matrix;
	EXPECT_TRUE(actual == expected);
	delete array1;
	delete array2;
	delete product;
}

/// Matrix Multiplication test case with a different size matrices (but valid)
TEST(MatrixMultiplyTest, TestMatrixDifferentSizesMultiply) {
	const int rows1 = 3;
	const int cols1 = 2;
	double data1[rows1 * cols1] = { 1, 2, 3, 4, 5, 6 };
	double* dataptr1 = data1;
	double** array1 = generateTestArray(dataptr1, rows1, cols1);
	const int rows2 = 2;
	const int cols2 = 1;
	double data2[rows2 * cols2] = { 1, 2 };
	double* dataptr2 = data2;
	double** array2 = generateTestArray(dataptr2, rows2, cols2);
	double resultData[rows1 * cols2] = { 5, 11, 17 };
	double* resultDataptr = resultData;
	double** product = generateTestArray(resultDataptr, rows1, cols2);
	Matrix<double> sut = Matrix<double>(array1, rows1, cols1);
	Matrix<double> other_matrix = Matrix<double>(array2, rows2, cols2);
	Matrix<double> expected = Matrix<double>(product, rows1, cols2);
	Matrix<double> actual = sut * other_matrix;
	EXPECT_TRUE(actual == expected);
	delete array1;
	delete array2;
	delete product;
}

/// Matrix Multiplication test case with a itself and a transposed form
TEST(MatrixMultiplyTest, TestMatrixWithTransposeMultiply) {
	const int rows = 3;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4, 5, 6 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	double resultData[rows * rows] = { 5, 11, 17, 11, 25, 39, 17, 39, 61 };
	double* resultDataptr = resultData;
	double** product = generateTestArray(resultDataptr, rows, rows);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	Matrix<double> transposed = sut.transpose();
	Matrix<double> expected = Matrix<double>(product, rows, rows);
	Matrix<double> actual = sut * transposed;
	EXPECT_TRUE(actual == expected);
	delete array;
	delete product;
}

/// Matrix Multiplication test case with a incompatible size matrices
TEST(MatrixMultiplyTest, TestMatrixInvalidSizesMultiply) {
	const int rows = 3;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4, 5, 6 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	Matrix<double> other_matrix = Matrix<double>(array, rows, cols);
	EXPECT_THROW(sut * other_matrix, invalid_argument);
	delete array;
}

/// Matrix Multiplication test case with the *= operator
TEST(MatrixMultiplyTest, TestMatrixMultiplyEqualsOperator) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	double resultData[rows * cols] = { 7, 10, 15, 22 };
	double* resultDataptr = resultData;
	double** product = generateTestArray(resultDataptr, rows, cols);
	Matrix<double> expected = Matrix<double>(product, rows, cols);
	Matrix<double> sut2 = sut; 
	sut *= sut2;
	EXPECT_TRUE(sut == expected);
	delete array;
	delete product;
}

/// 
/// Matrix Access Tests
/// 

/// Retrieves the specific element in the 1x1 matrix
TEST(MatrixAccessTest, TestMatrixOneByOne) {
	const int rows = 1;
	const int cols = 1;
	Matrix<double> sut = Matrix<double>(rows, cols);
	EXPECT_TRUE(sut(0, 0) == 0);
}

/// Retrieves the specific element in the non-1x1 matrix
TEST(MatrixAccessTest, TestMatrixTwoByTwo) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	EXPECT_TRUE(sut(1, 1) == 4);
	delete array;
}

/// 
/// Matrix Row and Column Count Tests
/// 

/// Retrieve the number of rows of an empty matrix
TEST(MatrixRowCountTest, TestMatrixEmpty) {
	const int rows = 0;
	const int cols = 0;
	Matrix<double> sut = Matrix<double>(rows, cols);
	EXPECT_TRUE(rows == sut.rows());
}

/// Retrieve the number of rows of an non-empty matrix
TEST(MatrixRowCountTest, TestMatrixTwoByTwo) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	EXPECT_TRUE(rows == sut.rows());
	delete array;
}

/// Retrieve the number of columns of an empty matrix
TEST(MatrixColumnCountTest, TestMatrixEmpty) {
	const int rows = 0;
	const int cols = 0;
	Matrix<double> sut = Matrix<double>(rows, cols);
	EXPECT_TRUE(cols == sut.cols());
}

/// Retrieve the number of columns of an non-empty matrix
TEST(MatrixColumnCountTest, TestMatrixTwoByTwo) {
	const int rows = 2;
	const int cols = 2;
	double data[rows * cols] = { 1, 2, 3, 4 };
	double* dataptr = data;
	double** array = generateTestArray(dataptr, rows, cols);
	Matrix<double> sut = Matrix<double>(array, rows, cols);
	EXPECT_TRUE(cols == sut.cols());
	delete array;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
