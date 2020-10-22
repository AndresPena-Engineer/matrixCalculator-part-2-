///////////////////////////////////////////////////////////////
// Description: This is part 2 of the 3 parts of a matrix lab. 
//              This part of the project focuses on getting the 
//              functionality of the matrices to work with one 
//              another. 
//
//////////////////////////////////////////////////////////////

#include<iostream>
#include <algorithm> // provides min()

using namespace std;

#include "matrix.h"

// Creates an empty Matrix of size 0 times 0.
Matrix::Matrix()
{
    width = 0;
    height = 0;
    values = nullptr;
}

// Creates an identity Matrix of size <size> times <size>.
Matrix::Matrix(int size) : Matrix(size, size)
{
    for (int s = 0; s < size; s++)
    {
        values[s][s] = 1;
    }
}

// Creates a Matrix of size <height> times <width> filled with 0s.
Matrix::Matrix(int height, int width) : Matrix()
{
    resize(height, width);
}

// Copy constructor
Matrix::Matrix(const Matrix& mat)
{
	double** tmpValues = new double*[height]; 
	for (int h = 0; h < mat.getHeight(); h++)
	{
		values[h] = new double[mat.getWidth()];
		for (int w = 0; w < min(mat.getWidth(), width); w++)
		{
			values[h][w] = tmpValues[h][w];
		}
	}
	for (int h = 0; h < height; h++)
	{
		delete[] tmpValues[h];
	}
	delete[] tmpValues;

	width = mat.getWidth();
	height = mat.getHeight();
}

// move constructor
Matrix::Matrix(Matrix&& matrix)
{
	this->height = matrix.getHeight();
	this->height = matrix.getWidth();
	this->values = new double* [height];

	for (int i = 0; i < height; i++) {
		values[i] = new double[width];
		for (int j = 0; j < width; j++) {
			values[i][j] = matrix.values[i][j];
		}
	}
}

// Destructor
Matrix::~Matrix()
{
    if (values != nullptr)
    {
        for (int r = 0; r < height; r++)
        {
            delete[] values[r];
        }
        delete[] values;
    }
}

// Get the width of the matrix
int Matrix::getWidth() const
{
    return width;
}

// Get the height of the matrix
int Matrix::getHeight() const
{
    return height;
}

// Resizing of the matrix to convert to
void Matrix::resize(int hei, int wid)
{
    double** tmpValues = values;

    values = new double*[hei];
    for (int h = 0; h < hei; h++)
    {
        values[h] = new double[wid];
        for (int w = 0; w < wid; w++)
        {
            values[h][w] = 0.0;
        }
    }

    for (int h = 0; h < min(hei, height); h++)
    {
        for (int w = 0; w < min(wid, width); w++)
        {
            values[h][w] = tmpValues[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        delete[] tmpValues[h];
    }
    delete[] tmpValues;

    width = wid;
    height = hei;

}

/*
 Changes the matrix to its transposition. Note that it changes the matrix and does not create
 a new Matrix - object.
*/
 void Matrix::transpose() 
{
	 double** transpose = values; 
	 values = new double*[height];
	 for (int h = 0; h < height;h++)
	 {
		 values[h] = new double[width];
		 for (int w = 0; w < width; w++)
		 {
			 values[w][h] = transpose[h][w];
		 }
	 }
	 for (int h = 0; h < height; h++)
	 {
		 delete[] transpose[h];
	 }
	 delete[] transpose;

	 width = this->width;
	 height = this->height;
}


 // Copy assignment
 Matrix& Matrix::operator=(const Matrix& M)
 {
	 // Self-assignment detection
	 if (this == &M)
		 return(*this);

	 // Release any resource we're holding
	 delete[] values;

	 // Copy the resource
	 this->width = M.width;
	 this->height = M.height;

	 // not working on the double 
	 this->values = new double*[width];
	 for (int i = 0; i < width; i++)
	 {
		 this->values[i] = new double[height];
		 for (int j = 0; j<height; j++)
		 {
			 this->values[i][j] = M.values[i][j];
		 }
	 }
	 return(*this);
 }

 // move operator
 Matrix& Matrix::operator=(Matrix&& matrix)
 {
	 this->height = matrix.getHeight();
	 this->height = matrix.getWidth();
	 this->values = new double*[height];

	 for (int i = 0; i < height; i++) {
		 values[i] = new double[width];
		 for (int j = 0; j < width; j++) {
			 values[i][j] = matrix.values[i][j];
		 }
	 }
	 return *this;
 }

 // Returns the value at the specified position in the Matrix.
double& Matrix::operator()(int row, int col)
{
    return values[row][col];
}

// Returns the value at the specified position in the Matrix.
double Matrix::operator()(int row, int col) const
{
    return values[row][col];
}

/*
Determines if two matrices are equal. Two matrices are equal if they have the
same height, the same width, and all corresponding elements are equal in both matrices
*/
bool Matrix::operator==(const Matrix& mat) const {
	if (height != mat.height || width != mat.width)
		return false;
	for (int row = 0; row < height; ++row)
		for (int col = 0; col < width; ++col) 
			if (values[row][col] != mat(row, col)) {
				return false;
			}
	return true;
}
