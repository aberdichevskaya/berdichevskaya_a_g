#include <iostream>

#include "stack.h"

StackOnList::StackOnList(const StackOnList& rhs) {
	Node* copy = rhs.data_;
	data_ = new Node;
	Node* p = data_;
	while (copy != nullptr) {
		p->data = copy->data;
		copy = copy->next;
		if (copy != nullptr) {
			p->next = new Node;
			p = p->next;
		}
	}
	data_ = p;
}

StackOnList::~StackOnList() {
	Clear();
}

void StackOnList::Push(const int value) {
	data_ = new Node(data_, value);
}

void StackOnList::Pop() noexcept {
	Node* deleted(data_);
	data_ = data_ -> next;
	delete deleted;
}

bool StackOnList::IsEmpty() {
	return (data_);
}

void StackOnList :: Clear() noexcept {
	while (!IsEmpty()) {
		Pop();
	}
}

int StackOnList::Top() {
	if (IsEmpty()) {
		throw std::logic_error("Try to get top from empty stack");
	}
	return data_->data;
}

bool StackOnList::operator==(const StackOnList& obj) {
	bool answer(true);
	Node* comparing1(this->data_);
	Node* comparing2(obj.data_);
	while (comparing1 && comparing2 && answer) {
		if (comparing1->data != comparing2->data) {
			answer = false;
		}
		comparing1 = comparing1->next;
		comparing2 = comparing2->next;
	}
	return answer;
}

bool StackOnList::operator!=(const StackOnList& obj) {
	return !(operator==(obj));
}

StackOnList& StackOnList::operator=(StackOnList& obj) {
	if (*this != obj) {
		this->Clear();
		StackOnList first;
		while (!obj.IsEmpty()) {
			first.Push(obj.Top());
			obj.Pop();
		}
		StackOnList answer;
		while (!first.IsEmpty()) {
			answer.Push(first.Top());
			first.Pop();
		}
		return answer;
	}
	else {
		return *this;
	}
}

std::ostream& StackOnList::WriteTo(std::ostream&ostr) const {
	Node* printed(data_);
	while (printed) {
		ostr << printed->data;
		printed = printed->next;
		if (printed) {
			ostr << ", ";
		}
	}
	return ostr;
}


std::ostream& operator <<(std::ostream& ostr, const StackOnList& rhs) {
	return rhs.WriteTo(ostr);
}
