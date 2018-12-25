#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
	Matrix() = default;
	Matrix(int col, int row);
	Matrix(const Matrix& rhs);
	~Matrix();
	bool operator==(const Matrix& rhs) const;
	Matrix& operator=(const Matrix& rhs);
	int GetCollumn();
	int GetRow();
	int& At(int col, int rows);
	int& At(int col, int rows) const;

private:
	int** data{ nullptr };
	int collumn{ 0 };
	int row{ 0 };

};


#endif // !MATRIX_KR_H




#endif 

