#pragma once

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

/// A simple Matrix class 
/// 
/// This class is made to enable users to be able to perform Matrix Multiplication and Transpose of mxn matrices. 
/// m represents the number of rows and n represents the number of columns in the matrix. 
template <typename T> class Matrix
{
public:

	/// Constructor for the Matrix class
	/// 
	/// This constructor will create a rows x columns matrix with 0s populated  
	/// @param rows: The number of rows for the Matrix.
	/// @param cols: The number of columns for the Matrix.
	Matrix(unsigned int rows, unsigned int cols) : rowCount(rows), colCount(cols) {
		allocateArray();
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				data[i][j] = 0;
			}
		}
	}

	/// Constructor for the Matrix class
	/// 
	/// This constructor will create a rows x columns matrix with the data passed in populated.  
	/// @param values: The data to populate the rows x columns matrix.
	/// @param rows: The number of rows for the Matrix.
	/// @param cols: The number of columns for the Matrix.
	Matrix(T** values, unsigned int rows, unsigned int cols) : rowCount(rows), colCount(cols) {
		allocateArray();

		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				data[i][j] = values[i][j];
			}
		}

	}

	/// Destructor for the Matrix class
	/// 
	/// This destructor will delete the unnecesary resources used to store the matrix data.  
	~Matrix() {
		for (int i = 0; i < rowCount; i++) {
			delete[] data[i];
		}
		delete data;
	}

	/// <summary>
	/// Move Constructor for the Matrix class
	/// </summary>
	/// <param name="other"> The source matrix</param>
	Matrix(const Matrix& other) : rowCount(other.rowCount), colCount(other.colCount) {
		allocateArray();
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				data[i][j] = other.data[i][j];
			}
		}
	}

	/// <summary>
	/// Copy Constructor of the Matrix class
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Matrix<T>& operator=(const Matrix& other) {
		if (this == &other) {
			return *this;
		}

		if (rowCount != other.rowCount || colCount != other.colCount) {
			for (int i = 0; i < rowCount; i++) {
				delete[] data[i];
			}
			delete[] data;

			rowCount = other.rowCount;
			colCount = other.colCount;
			allocateArray();
		}

		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				data[i][j] = other.data[i][j];
			}
		}
		return *this;
	}

	/// Returns whether the two matrices are equal in size and values. 
	/// @param other: the other matrix to compare against. 
	/// @returns Whether or not the two matrices are equal.
	bool equals(Matrix other) {
		if (this->rowCount != other.rowCount || this->colCount != other.colCount) {
			return false;
		}

		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				if (this->data[i][j] != other.data[i][j]) {
					return false;
				}
			}
		}

		return true;
	}


	/// Returns the transpose of the matrix. 
	/// 
	/// The transpose of the matrix is simply a flipped version of the original matrix. 
	/// For example, the transpose of {{1, 2}, {3, 4}} would be {{1, 3}, {2, 4}}. 
	/// @returns the transpose copy of the matrix
	Matrix<T> transpose() {
		if (this->rowCount < 1) {
			return *this;
		}

		Matrix* result = new Matrix(this->colCount, this->rowCount);
		for (int i = 0; i < this->rowCount; i++)
		{
			for (int j = 0; j < this->colCount; j++)
			{
				result->data[j][i] = this->data[i][j];
			}
		}
		return *result;
	}

	/// Returns whether the two matrices are equal in size and values. 
	/// @param other: the other matrix to compare against. 
	/// @returns Whether or not the two matrices are equal.
	bool operator==(const Matrix& other) {
		return this->equals(other);
	}

	/// Returns whether the two matrices are not equal in size and values. 
	/// @param other: the other matrix to compare against. 
	/// @returns Whether or not the two matrices are not equal.
	bool operator!=(const Matrix& other) {
		return !this->equals(other);
	}

	/// Returns the product result from mxn matrices with the * operator
	/// 
	/// Matrix Multiplication is only valid when the number of columns of the first matrix equals the number 
	/// of rows in the second matrix. If these are not equal, then this method will throw an invalid_argument
	/// exception. 
	/// @param other: The other matrix to compare against. 
	/// @throws invalid_argument: 
	/// Matrix Multiplication is only valid when the number of columns of the first matrix equals the number 
	/// of rows in the second matrix. If these are not equal, then this method will throw an invalid_argument
	/// exception.
	/// @returns The matrix result from multiplying the two matrices.
	Matrix<T> operator*(const Matrix<T>& other) {
		int rows1 = this->rowCount;
		int rows2 = other.rowCount;
		int cols2 = other.colCount;
		Matrix<T> result = Matrix<T>(rows1, cols2);

		validate_for_multiply(other);

		for (int i = 0; i < rows1; i++) {
			for (int j = 0; j < cols2; j++) {
				for (int k = 0; k < rows2; k++) {
					result.data[i][j] += this->data[i][k] * other.data[k][j];
				}
			}
		}

		return result;
	}

	/// Returns the product result from mxn matrices with the *= operator
	/// 
	/// Matrix Multiplication is only valid when the number of columns of the first matrix equals the number 
	/// of rows in the second matrix. If these are not equal, then this method will throw an invalid_argument
	/// exception. 
	/// @param other: The other matrix to compare against. 
	/// @throws invalid_argument: 
	/// Matrix Multiplication is only valid when the number of columns of the first matrix equals the number 
	/// of rows in the second matrix. If these are not equal, then this method will throw an invalid_argument
	/// exception.
	/// @returns The matrix result from multiplying the two matrices.
	Matrix<T> operator*=(const Matrix<T>& other) {
		Matrix<T> result = (*this) * other;
		*this = result;
		return *this;
	}

	/// Access a specific element in the matrix
	/// @returns the value of the specified index of the matrix
	T& operator()(const unsigned int& row, const unsigned int& column) const {
		return this->data[row][column];
	}


	/// Returns the number of rows
	/// @returns the number of rows in the Matrix
	unsigned int rows() const {
		return this->rowCount;
	}

	/// Returns the number of columns
	/// @returns the number of columns in the Matrix
	unsigned int cols() const {
		return this->colCount;
	}

private:
	void allocateArray() {
		data = new T * [this->rowCount];
		for (int i = 0; i < this->rowCount; i++) {
			data[i] = new T[this->colCount];
		}
	}
	bool validate_for_multiply(Matrix<T> other) {
		if (this->colCount != other.rowCount) {
			throw invalid_argument("In order to perform Matrix Multiplication successfully, the number of columns in the first matrix must match the number of rows in the second matrix. ");
		}
		return true;
	}

	T** data;
	unsigned int rowCount;
	unsigned int colCount;
};

/// Provides a printed representation of the Matrix. 
/// @param matrix: the matrix to print the representation of 
template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
	if (matrix.rows() == 0 || matrix.cols() == 0) {
		os << "(empty)" << endl;
	}

	for (int i = 0; i < matrix.rows(); i++) {
		os << "[";
		os << matrix(i, 0);
		for (int j = 1; j < matrix.cols(); j++) {
			os << " " << matrix(i, j);
		}
		os << "]" << endl;
	}
	return os;
}

#endif