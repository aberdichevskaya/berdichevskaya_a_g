#include <iostream>
#include <conio.h>

#include "dinamic.h"

int main() {
	double data(3.5);
	Dinamic_array arr1(7);
	Dinamic_array arr2(3);
	Dinamic_array arr3(arr2);
	for (int i = 0; i < arr2.GetSize(); ++i)
		arr2[i] = data + i*1.0;
	arr1 = arr2;
	arr1 = arr1;
	std::cout << "arr1 before changing: \n";
	for (int i = 0; i < arr1.GetSize(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "arr1 after changing: \n";
	arr1[2] = 10.2;
	for (int i = 0; i < arr1.GetSize(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	arr1 = arr2 = arr3;
	std::cout << "arr1 after new changing: \n";
	for (int i = 0; i < arr1.GetSize(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	try {
		Dinamic_array arr5(-2);
	}
	catch (std::invalid_argument exc) {
		std::cout << exc.what() << std::endl;
	}

	try {
		int f = arr2[8];
	}
	catch (std::invalid_argument exc) {
		std::cout << exc.what() << std::endl;
	}
	_getch();
	return 0;
}
