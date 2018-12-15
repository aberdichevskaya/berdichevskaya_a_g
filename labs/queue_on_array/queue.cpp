#include <iostream>

#include "queue.h"

Queue::Queue(const Queue& data)
	: i_first(data.i_first)
	, i_last(data.i_last) {
	for (int i = 0; i < size_; i += 1) {
		data_[i] = data.data_[i];
	}
}

Queue::~Queue() {
	delete[] data_;
}

bool Queue::operator==(const Queue& rhs) {
	bool answer(true);
	if (*this != rhs) {
		for (int i = 0; i < size_; i += 1) {
			if (data_[i] != rhs.data_[i]) {
				answer = false;
			}
		}
	}
	return answer;
}

bool Queue::operator!=(const Queue& rhs) {
	return !operator==(rhs);
}

Queue& Queue::operator=(const Queue& rhs) {
	if (*this != rhs) {
		i_first = rhs.i_first;
		i_last = rhs.i_last;
		for (int i = 0; i < size_; i += 1) {
			data_[i] = rhs.data_[i];
		}
	}
	else {
		return *this;
	}
}

void Queue::Push(int value) {
	if (i_last-1 != &data_[size_-1]) {
		*i_last = value;
		i_last = i_last + 1;
	}
	else {
		if (i_first != &data_[0]) {
			i_last -= size_;
			*i_last = value;
			i_last += 1;
		}
		else {
			throw std::out_of_range ("Array is full");
		}
	}
}

bool Queue::IsEmpty() {
	return ((i_last - i_first) == 0);
}

void Queue::Pop() {
	if (!IsEmpty()) {
		if (i_first != &data_[size_ - 1]) {
			*i_first = 0;
			i_first += 1;
		}
		else {
			i_first -= size_;
			*i_first = 0;
			i_first += 1;
		}
	}
	else {
		throw std::out_of_range("Queue is empty");
	}
}

int Queue :: Front() {
	if (IsEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	else {
		return *i_first;
	}
}

int Queue::Back() {
	if (IsEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	else {
		return *(i_last - 1);
	}
}

std::ostream& Queue::WriteTo(std::ostream& ostr) const {
	if (i_last == i_first) {
		throw std::logic_error("Queue is empty");
	}
	int* print = i_first;
	while (print < i_last)
	{
		ostr << *print;
		print++;
		if (print == &data_[size_ - 1]) {
			print -= size_;
		}
		if (print < i_last) {
			ostr << ", ";
		}
	}
	return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const Queue& rhs) {
	return rhs.WriteTo(ostr);
}

