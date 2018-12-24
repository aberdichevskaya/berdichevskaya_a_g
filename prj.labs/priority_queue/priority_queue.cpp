#include "priority_queue.h"


bool Priority_queue::Node::operator==(const Node& rhs) {
	return ((key == rhs.key) && (value == rhs.value));
}

bool Priority_queue::Node::operator<(const Node& rhs) {
	return (key < rhs.key);
}

bool Priority_queue::Node::operator>(const Node& rhs) {
	return (key > rhs.key);
}

Priority_queue::Node Priority_queue::Node::operator=(const Node& rhs) {
	key = rhs.key;
	value = rhs.value;
	return *this;
}

Priority_queue::Priority_queue(const Priority_queue& rhs) 
	: i_first(rhs.i_first)
	, i_last(rhs.i_last) {
	for (int i = 0; i < size; i += 1) {
		data[i] = rhs.data[i];
	}
}

Priority_queue::~Priority_queue() {
	delete[] data;
	i_last = 0;
	i_first = 0;
	size = NULL;
}

bool Priority_queue::IsEmpty() {
	return  (i_first == i_last);
}

bool Priority_queue::operator==(const Priority_queue& rhs) {
	bool rez(true);
	if (*this != rhs) {
		if ((i_last != rhs.i_last) || (i_first != rhs.i_first)) {
			rez = false;
		}
		else {
			for (int i = 0; i < size; i += 1) {
				if (data[i] == rhs.data[i]) {
					rez = false;
					break;
				}
			}
		}
	}
	return rez;
}


bool Priority_queue::operator!=(const Priority_queue& rhs) {
	return !operator==(rhs);
}

Priority_queue& Priority_queue::operator=(const Priority_queue& rhs) {
	if (*this != rhs) {
		i_last = rhs.i_last;
		i_first = rhs.i_first;
		for (int i = 0; i < size; i += 1) {
			data[i] = rhs.data[i];
		}
	}
	return *this;
}

void Priority_queue::order() {
	Node swaped(0,0);
	for (int i = i_first; i < i_last; i++) {
		for (int j = i_first; j < i_last - i; j++) {
			if (data[j] > data[j + 1]) {
				swaped = data[j];
				data[j] = data[j + 1];
				data[j + 1] = swaped;
			}
		}
	}
}

void Priority_queue::push(int key, int value) {
	if (i_last < size) {
		Node pushed(key, value);
		data[i_last] = pushed;
		i_last += 1;
		order();
	}
	else {
		throw std::out_of_range("Array is full");
	}
}

void Priority_queue::pop() {
	if (!IsEmpty()) {
			data[i_first].key = 0;
			data[i_first].value = 0;
			i_first += 1;
	}
	else {
		throw std::out_of_range("Queue is empty");
	}
}


int Priority_queue::front() {
	if (!IsEmpty()) {
		return data[i_first].value;
	}
	else {
		throw std::out_of_range("Queue is empty");
	}
}

int Priority_queue::back() {
	if (!IsEmpty()) {
		return data[i_last].value;
	}
	else {
		throw std::out_of_range("Queue is empty");
	}
}

std::ostream& Priority_queue::WriteTo(std::ostream& ostr) const {
	if (i_last == i_first) {
		throw std::logic_error("Queue is empty");
	}
	int printed = i_first;
	while (printed < i_last) {
		ostr << data[printed].value;
		printed++;
		if (printed < i_last) {
			ostr << ", ";
		}
	}
	return ostr;
}


std::ostream& operator<<(std::ostream& ostr, const Priority_queue& rhs) {
	return rhs.WriteTo(ostr);
}
