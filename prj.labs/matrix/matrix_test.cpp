#include <iostream>

#include "matrix.h"

int main() {
	Matrix a(5, 5);
	for (int i = 0; i < a.GetRows(); i += 1) {
		for (int j = 0; j < a.GetCollumns(); j += 1) {
			a.At(i, j) = i * j*1.0;
		}
	}
	Matrix b(a);
	std::cout << "number of rows of b = " << b.GetRows() << std::endl;
	std::cout << "number of collumns of b = " << b.GetCollumns() << std::endl;
	std::cout << "b before changing: \n";
	for (int i = 0; i < b.GetRows(); i += 1) {
		for (int j = 0; j < b.GetCollumns(); j += 1) {
			std::cout << b.At(i, j) << " ";
		}
		std::cout << std::endl;
	}
	b.At(0, 2) = -1.8;
	b.At(0, 4) = -66.9;
	std::cout << "b after changing: \n";
	for (int i = 0; i < b.GetRows(); i += 1) {
		for (int j = 0; j < b.GetCollumns(); j += 1) {
			std::cout << b.At(i, j) << " ";
		}
		std::cout << std::endl;
	}

	try {
		Matrix matrix1();
		Matrix matrix2(-1, 6);
		Matrix matrix3(5, 8);
		Matrix matrix4(matrix3);
		Matrix matrix5(3, 4);
		matrix4 = matrix5 = matrix3;
	}
	catch (std :: invalid_argument& Ex)
	{
		std::cout << Ex.what() << std::endl;
	}
	
	return 0;
}
