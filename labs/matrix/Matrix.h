#ifndef MATRIX_H
#define MATRIX_H

class Matrix //private
{

public:
	Matrix() = default;
	Matrix(const int rows, const int collumns);
	Matrix(const Matrix& data);
	Matrix& operator=(const Matrix& rhs);
	bool operator==(const Matrix& rhs);
	bool operator !=(const Matrix& rhs);
	~Matrix();
	int GetRows();
	int GetCollumns();
	double& At(const int row, const int collumn) const;//const
	double& At(int row, int collumn);

private:
	double** _data{ nullptr };
	int rows_{ 0 };
	int collumns_{ 0 };

};


#endif 

