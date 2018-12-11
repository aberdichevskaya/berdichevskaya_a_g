#include <iostream>

#include "dinamic.h"

int main()
{
	double data(3.5);
	Dinamic_array arr1(7);
	Dinamic_array arr2(3);
	Dinamic_array arr3(arr2);
	for (int i = 0; i < arr2.GetSize(); ++i)
		arr2[i] = data + i;
	arr1 = arr2;
	arr1 = arr1;
	for (int i = 0; i < arr1.GetSize(); ++i)
	{
		std::cout << arr1[i] << " ";
	}
}