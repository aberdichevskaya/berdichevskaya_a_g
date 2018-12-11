#include <iostream>

#include "Matrix.h"

Matrix::~Matrix()
{
	for (int i = 0; i < rows_; i += 1)
	{
		delete[] _data[i];
	}
	delete[] _data;
}


Matrix::Matrix(const int rows, const int collumns)
{
	if ((rows < 0) || (collumns < 0))
		throw std::invalid_argument("Wrong size");
	else
	{
		rows_ = rows;
		collumns_ = collumns;
	}
	for (int i = 0; i < rows; i += 1){
		for (int j = 0; j < collumns; j +=1){
			_data[i][j] = 0;
		}
	}
}

bool Matrix::operator==(const Matrix& rhs)
{
	bool resalt(true);
	if ((rows_ != rhs.rows_) || (collumns_ != rhs.collumns_))
	{
		resalt = false;
	}
	else
	{
		for (int i = 0; i < rhs.rows_; i += 1)
		{
			for (int j = 0; j < rhs.collumns_; j += 1)
			{
				if (_data[i][j] != rhs._data[i][j]) {
					resalt = false;
				}
			}
		}
	}
	return resalt;
}

bool Matrix::operator!=(const Matrix& rhs)
{
	return !(operator==(rhs));
}

Matrix& Matrix::operator=(const Matrix& rhs) //?
{
	if (&rhs == this) {
		return *this;
	}
	else if ((rows_ != rhs.rows_) || (collumns_ != rhs.collumns_) ){
		_data = new double*[rhs.rows_];
		for (int i = 0; i < rows_; i += 1) {
			_data[i] = new double[rhs.collumns_];
		}
	}
	for (int i = 0; i < rows_; i+=1)
	{
		for (int j = 0; j < collumns_; j+=1) {
			_data[i][j] = rhs._data[i][j];
		}
	}
	return *this;
}


Matrix::Matrix(const Matrix& data) //?
	:rows_ (data.rows_)
	,collumns_(data.collumns_)
{
	_data = new double*[rows_];
	for (int i = 0; i < rows_; i += 1) {
		_data[i] = new double[collumns_];
	}
	for (int i = 0; i < rows_; i += 1) {
		for (int j = 0; j < collumns_; j += 1) {
			_data[i][j] = data._data[i][j];
		}
	}
}

int Matrix::GetRows()
{
	return rows_;
}

int Matrix::GetCollumns()
{
	return collumns_;
}

double& Matrix::At(const int row, const int collumn) const
{
	if ((row < 0) || (row >= this->rows_) || (collumn < 0) || (collumn >= this->collumns_)) {
		throw std::invalid_argument("Wrong index");
	}
	else {
		return _data[row][collumn];
	}

}

double& Matrix::At(int row, int collumn)
{
	if ((row < 0) || (row >= this->rows_) || (collumn < 0) || (collumn >= this->collumns_)) {
		throw std::invalid_argument("Wrong index");
	}
	else {
		return _data[row][collumn];
	}
}