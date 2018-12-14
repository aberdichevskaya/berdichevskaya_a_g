#include <iostream>

#include "queue.h"

Queue::Queue(const Queue& data)
	:i_first(data.i_first)
	,i_last(data.i_last)
{
	for (int i = 0; i < size_; i += 1) {
		data_[i] = data.data_[i];
	}
}

Queue::~Queue() {
	delete[] data_;
}

bool Queue::operator==(const Queue& rhs) {
	bool answer(true);
	for (int i = 0; i < size_; i += 1) {
		if (data_[i] != rhs.data_[i]) {
			answer = false;
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
	if (*i_last < size_) {
		*i_last = value;
		i_last = i_last + 1;
	}
	else {
		if (i_first > 0) {
			*i_last %= size_;
			*i_last = value;
			i_last += 1;
		}
		else {
			throw std::out_of_range ("Array is full");
		}
	}
}

void Queue::Pop() noexcept {
	if (*i_first < size_) {
		*i_first = 0;
		i_first += 1;
	}
	else {
		*i_first %= size_;
		*i_first = 0;
		i_first += 1;
	}
}

int Queue :: Front() {
	int ans(0);
	if (*i_first < size_) {
		ans = *i_first;
	}
	else {
		*i_first %= size_;
		ans = *i_first;
	}
	return ans;
}

int Queue::Back() {
	int ans(0);
	if (*i_last <= size_) {
		ans = *(i_last - 1);
	}
	else {
		*i_last %= size_;
		ans = *(i_last - 1);
	}
	return ans;
}

bool Queue :: IsEmpty() {
	return ((i_last - i_first) == 0);
}





