#include <iostream>
#include <conio.h>

#include "queue.h"

int main() {
	Queue a;
	a.Push(1);
	a.Push(5);
	std ::cout << "Queue a: " << a << std::endl;
	Queue b(a);
	std::cout << "First of a:" << a.Front() << std::endl;
	std::cout << "First of b:" << b.Front() << std::endl;
	b.Pop();
	b.Push(7);
	std::cout << "Queue b: " << b << std::endl;
	std::cout << "Last of a: " << a.Back() << std::endl;
	Queue c;
	for (int i = 0; i < 20; i += 1) {
		c.Push(2);
	}
	try {
		c.Push(5);
	}
	catch (std :: out_of_range exc) {
		std::cout << "Out of range error: " << exc.what() << std::endl;
	}
	Queue s;
	try {
		s.Front();
	}
	catch (std::out_of_range exc) {
		std::cout << "Out of range error: " << exc.what() << std::endl;
	}
	try {
		std::cout << s << std::endl;
	}
	catch (std:: logic_error exc){
		std::cout << "Logic error: " << exc.what() << std::endl;
	}
	_getch();
	return 0;
}
