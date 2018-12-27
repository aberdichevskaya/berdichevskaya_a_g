#include <iostream>
#include<sstream>
#include <conio.h>

#include "rational.h"

bool testParse(const std::string str) {
	std::istringstream strm(str);
	Rational w;
	strm >> w;
	if (strm.good()) {
		std::cout << "Read succes:" << "<-" << w << std::endl;
	}
	else {
		std::cout << "Read error:" << "<-" << w << std::endl;
	}
	return strm.good();
}


int main() {
	testParse("{5/7}");
	testParse("{5.1/2}");
	testParse("{4/7");

	Rational w;
	Rational k(1, 1);
	w += k;
	Rational a(1, 2);
	Rational b(-2, 4);
	Rational c(3, 5);
	std::cout << "1/2 - 2/4 = " << a + b << std::endl;
	std::cout << "1/2 + 2/4 = " << a - b << std::endl;
	std::cout << "1/2 * (-2/4) = " << a * b << std::endl;
	std::cout << "1/2 / (-2/4) = " << a / b << std::endl;
	try {
		Rational d(5, 0);
	}
	catch (std::out_of_range exc) {
		std::cout << exc.what() << std::endl;
	}

	try {
		std::string a("{6/0}");
		testParse(a);
	}
	catch (std::out_of_range exc) {
		std::cout << exc.what() << std::endl;
	}
	_getch();
	return 0;
}
