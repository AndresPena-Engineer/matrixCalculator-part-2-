#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

using namespace std;

void printSize(const Matrix &m)
{
	cout << "width: " << m.getWidth()
		<< "  |  height: " << m.getHeight()
		<< endl;
}

void printMatrix(const Matrix &m)
{
	for (int h = 0; h < m.getHeight(); h++)
	{
		for (int w = 0; w < m.getWidth(); w++)
		{
			cout << m(h, w) << " ";
		}
		cout << endl;
	}
}

Matrix& getRndMatrix(int height, int width)
{
	Matrix& m = *(new Matrix(height, width));
	for (int h = 0; h < m.getHeight(); h++)
	{
		for (int w = 0; w < m.getWidth(); w++)
		{
			m(h, w) = rand() % 10;
		}
	}
	return m;
}

int main()
{
	srand(time(NULL));

	// Empty Matrix
	{
		cout << "------------\n";
		cout << "Empty Matrix: Matrix()\n";

		Matrix m;
		printSize(m);

	}

	// Identity Matrix
	{
		int size = rand() % 10 + 1;
		cout << "---------------\n";
		cout << "Identity Matrix: Matrix(" << size << ")\n";

		Matrix m(size);

		printSize(m);
		printMatrix(m);
	}

	// Zero Matrix
	{
		int height = rand() % 10 + 1;
		int width = rand() % 10 + 1;
		cout << "---------------\n";
		cout << "Zero Matrix: Matrix(" << height << ", " << width << ")\n";

		Matrix m(height, width);

		printSize(m);
		printMatrix(m);
	}

	// Copy and Move
	{
		cout << "---------------\n";
		cout << "Copy + Move\n";

		// Constructor
		Matrix m = getRndMatrix(3, 4);
		Matrix m2 = m;

		printMatrix(m);
		cout << "- - - -\n";
		printMatrix(m2);
		cout << "- - - -\n";


		// Assignment
		m = getRndMatrix(3, 4);
		m2 = m;

		printMatrix(m);
		cout << "- - - -\n";
		printMatrix(m2);
	}

	// Resize
	{
		int height1 = rand() % 10 + 1;
		int width1 = rand() % 10 + 1;

		int height2 = rand() % 10 + 1;
		int width2 = rand() % 10 + 1;
		cout << "---------------\n";
		cout << "Resize: "
			<< "(" << height1 << ", " << width1 << ") to "
			<< "(" << height2 << ", " << width2 << ")\n";

		Matrix m = getRndMatrix(height1, width1);
		printMatrix(m);
		cout << "- - - -\n";
		m.resize(height2, width2);
		printMatrix(m);
	}

	// Transpose
	{
		cout << "---------------\n";
		cout << "Transpose\n";

		Matrix m = getRndMatrix(2, 4);
		printMatrix(m);
		cout << "- - - -\n";
		m.transpose();
		printMatrix(m);
	}

	system("pause");
	return 0;
}
