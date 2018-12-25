#include <conio.h>

#include "matrix.h"

int main() {
	Matrix a;
	Matrix b(3, 5);
	b.At(1, 2) = 6;
	Matrix c(b);
	if (c == b) {
		std::cout << "c equals b \n";
		std::cout << "element (1, 2) of c and b: " << c.At(1, 2) << std::endl;
	}
	std::cout << "c's rows: " << c.GetRow() << " c's collumns: " << c.GetCollumn() << std::endl;
	c = c;
	a = b = c;
	if (a == c) {
		std::cout << "now a equals b \n";
	}
	try {
		a.At(56, 89) = 9;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	try {
		Matrix o(-1, -6);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	_getch();
	return 0;
}
