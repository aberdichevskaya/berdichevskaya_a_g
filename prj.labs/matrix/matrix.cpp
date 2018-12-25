#include "matrix.h"

Matrix::Matrix(int col, int row) 
	: collumn(col)
	, row(row) {
	if ((col < 0) || (row < 0)) {
		throw std::invalid_argument("Uncorrect size");
	}
	else {
		data = new int*[col];
		for (int i = 0; i < col; i += 1) {
			data[i] = new int[row];
			for (int j = 0; j < row; j += 1) {
				data[i][j] = 0;
			}
		}
	}
}

Matrix::Matrix(const Matrix& rhs) 
	: collumn(rhs.collumn)
	, row(rhs.row) {
	data = new int*[collumn];
	for (int i = 0; i < collumn; i += 1) {
		data[i] = new int[row];
		for (int j = 0; j < row; j += 1) {
			data[i][j] = rhs.data[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < collumn; i += 1) {
		delete[] data[i];
	}
	delete[] data;
}


bool Matrix::operator==(const Matrix& rhs) const {
	bool rez(true);
		if ((collumn != rhs.collumn) || (row != rhs.row)) {
			rez = false;
		}
		else {
			for (int i = 0; i < collumn; i += 1) {
				for (int j = 0; j < row; j += 1) {
					if (data[i][j] != rhs.data[i][j]) {
						rez = false;
						break;
					}
				}
			}
		}
	return rez;
}


Matrix& Matrix::operator=(const Matrix& rhs) {
	if (!(*this == rhs)) {
		if ((collumn != rhs.collumn) || (row != rhs.row)) {
			for (int i = 0; i < collumn; i += 1) {
				delete[] data[i];
			}
			delete[] data;
			collumn = rhs.collumn;
			row = rhs.row;
			data = new int*[collumn];
			for (int i = 0; i < collumn; i += 1) {
				data[i] = new int[row];
			}
		}
		for (int i = 0; i < collumn; i += 1) {
			for (int j = 0; j < row; j += 1) {
				data[i][j] = rhs.data[i][j];
			}
		}
	}
	return *this;
}

int Matrix::GetCollumn() {
	return collumn;
}

int Matrix::GetRow() {
	return row;
}

int& Matrix::At(int col, int rows) {
	if ((col < 0) || (col >= collumn) || (rows < 0) || (rows >= row)) {
		throw std::out_of_range("Uncorrect index");
	}
	else {
		return data[col][rows];
	}
}


int& Matrix::At(int col, int rows) const {
	if ((col < 0) || (col >= collumn) || (rows < 0) || (rows >= row)) {
		throw std::out_of_range("Uncorrect index");
	}
	else {
		return data[col][rows];
	}
}
