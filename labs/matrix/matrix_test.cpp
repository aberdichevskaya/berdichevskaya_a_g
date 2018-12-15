#include <iostream>

#include "matrix.h"

int main()
{
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

}
