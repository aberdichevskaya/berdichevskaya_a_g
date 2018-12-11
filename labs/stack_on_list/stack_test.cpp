#include <iostream>

#include "stack.h"

int main()
{
	StackOnList a;
	for (int i = 0; i < 10; i += 1) {
		a.Push(i*i);
	}
	std::cout << "Stack a: \n" << a << std::endl;
	StackOnList b(a);
	b.Pop();
	int h = b.Top();
	std::cout << h << std::endl;
	std::cout << "Stack b: \n" << b << std::endl;
	b.Clear();
	if (b.IsEmpty()) {
		std::cout << "b is clear";
	}
}