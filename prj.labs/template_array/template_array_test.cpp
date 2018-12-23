#include <iostream>

#include "template_array.h"

int main() {
	TemplateDinamicArray<int> a;
	a.resize(5);
	a[3] = 6;
	std::cout << "a[3] = " << a[3] << std::endl;
	TemplateDinamicArray<int> b(a);
	std::cout << "b[3] = " << b[3] << std::endl;
	b[3] = 7;
	std::cout << "And now b[3] = " << b[3] << std::endl;
	TemplateDinamicArray<int> c(8);
	std::cout << "Size of c: " << c.GetSize() << std::endl;
	c = b;
	std::cout << "And now size of c: " << c.GetSize() << std::endl;
	if (c == b) {
		std::cout << "c equals b" << std::endl;
	}
	c = a;
	if (c != b) {
		std::cout << "Now c doesn't equals b" << std::endl;
	}

	try {
		int p = a[8];
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
}