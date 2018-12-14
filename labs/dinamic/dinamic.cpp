#include <iostream>
#include <sstream>

#include "dinamic.h"

Dinamic_array::Dinamic_array(int size) //size, poryadok
	: size_(size) {
	if (size >= 0)
		for (int i = 0; i < size; ++i)  {
			data_[i] = 0;
		}
	else {
		throw std::invalid_argument("Uncorrect size");
	}
}

Dinamic_array::Dinamic_array(const Dinamic_array& data)
	: size_ (data.size_)
{
	for (int i = 0; i < data.size_; ++i) {
		data_[i] = data[i];
	}
}

Dinamic_array::~Dinamic_array() {
	delete[] data_;
	data_= nullptr;
	size_ = 0;
}

int Dinamic_array::GetSize() const {
	return size_;
}


const double& Dinamic_array::operator[](int i) const {
	if ((i < 0) || (i >= size_)) {
		throw std::invalid_argument("Uncorrect index");
	}
	
		return data_[i];	
}

double& Dinamic_array::operator[](int i) {
	if ((i < 0) || (i >= size_)) {
		throw std::invalid_argument("Uncorrect index");
	}

	return data_[i];
}


bool Dinamic_array::operator==(const Dinamic_array& rhs) {
	bool resalt(nullptr);
	if(*this == rhs) {
		resalt = true;
	}
	else {
		if (size_ != rhs.size_) {
			resalt = false;
		}
		else {
			for (int i = 0; i < rhs.size_; ++i) {
				if (data_[i] != rhs[i]) {
					resalt = false;
				}
			}
		}
		if (resalt != false) {
			resalt = true;
		}
	}
	return resalt;
}

bool Dinamic_array::operator!=(const Dinamic_array& rhs) {
	return !operator==(rhs);
}

Dinamic_array& Dinamic_array::operator=(const Dinamic_array& rhs) {
	if (*this != rhs) {
		delete[] data_;
		size_ = rhs.size_;
		data_ = new double [size_];
		for (int i = 0; i < size_; i+=1) {
			data_[i] = rhs.data_[i];
		}
	}
	return *this;
}
