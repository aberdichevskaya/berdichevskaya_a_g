#include <iostream>
#include <sstream>
#include <conio.h>

#include "complex.h"

bool testParse(const std::string& str) {
	std::istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		std::cout << "Read succes:" << str << "->" << z << std::endl;
	}
	else {
		std::cout << "Read error:" << str << "<-" << z << std::endl;
	}
	return istrm.good();
}

int main() {
	Complex z;
	z += Complex(8.0);

	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");

	Complex a(3.5);
	Complex b(2.1, 7.9);
	double c(4.9);
	std::cout << "a = " << a << ", b = " << b  << ", c = " << c << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "b - a = " << b - a << std::endl;
	b += a;
	std::cout << "b + a = " << b << std::endl;
	a *= c;
	std::cout << "a * c = " << a << std::endl;
	_getch();
	return 0;
}
