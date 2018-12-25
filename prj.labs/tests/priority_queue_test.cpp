#include <conio.h>

#include "priority_queue.h"


int main() {
	Priority_queue a;
	a.push(5, 2);
	Priority_queue b(a);
	b.push(1, 10);
	std::cout << "Queue b: " << b << std::endl;
	std::cout << "First of b:" << b.front() << std::endl;
	b.pop();
	b.push(7, 98);
	std::cout << "Queue b: " << b << std::endl;
	std::cout << "Last of a: " << a.back() << std::endl;
	Priority_queue c;
	for (int i = 0; i < 10; i += 1) {
		c.push(2, 3);
	}
	try {
		c.push(5, 56);
	}
	catch (std::out_of_range exc) {
		std::cout << "Out of range error: " << exc.what() << std::endl;
	}
	Priority_queue s;
	try {
		s.front();
	}
	catch (std::out_of_range exc) {
		std::cout << "Out of range error: " << exc.what() << std::endl;
	}
	try {
		std::cout << s << std::endl;
	}
	catch (std::logic_error exc) {
		std::cout << "Logic error: " << exc.what() << std::endl;
	}
	return 0;
}
