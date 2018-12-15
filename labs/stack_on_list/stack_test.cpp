#include <iostream>

#include "stack.h"

int main() {
	StackOnList a;
	for (int i = 0; i < 10; i += 1) {
		a.Push(i*i);
	}
	std::cout << "Stack a: " << a << std::endl;
	StackOnList b(a);
	std::cout << "Top of b: " << b.Top() << std::endl;
	b.Pop();
	std::cout << "Top of b: " << b.Top() << std::endl;
	std::cout << "Stack b: " << b << std::endl;
	b.Clear();
	if (b.IsEmpty()) {
		std::cout << "b is clear";
	}
	try {
		b.Pop();
	}
	catch (std::logic_error exc) {
		std::cout << "Logic error: " << exc.what() << std:: endl;
	}
	return 0;
}
