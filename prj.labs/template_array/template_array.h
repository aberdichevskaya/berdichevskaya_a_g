#pragma once

#ifndef TEMPLATE_ARRAY_H
#define TEMPLATE_ARRAY_H

template <typename T>
class TemplateDinamicArray {
private:
	int size{ 0 };
	T* data{ nullptr };
public:
	TemplateDinamicArray() = default;
	TemplateDinamicArray(const int size);
	TemplateDinamicArray(const TemplateDinamicArray& rhs);
	~TemplateDinamicArray();
	TemplateDinamicArray& operator=(const TemplateDinamicArray& rhs);
	bool operator==(const TemplateDinamicArray& rhs);
	bool operator !=(const TemplateDinamicArray& rhs);
	T& operator[](int index);
	const T& operator [](int index) const;
	int GetSize() const;
	void resize(int newSize);
};

template <typename T>
TemplateDinamicArray<T>::TemplateDinamicArray(const int size)
	: size(size) {
	if (size >= 0) {
		data = new T[size];
		for (int i = 0; i < size; i += 1) {
			data[i] = NULL;
		}
	}
	else {
		throw std::logic_error("Wrong size of array");
	}
}


template<typename T>
TemplateDinamicArray<T>::TemplateDinamicArray(const TemplateDinamicArray& rhs)
	: size(rhs.size) {
	data = new T[size];
	for (int i = 0; i < size; i += 1) {
		data[i] = rhs.data[i];
	}
}

template<typename T>
TemplateDinamicArray<T>::~TemplateDinamicArray() {
	delete[] data;
	data = nullptr;
	size = 0;
}

template <typename T>
bool TemplateDinamicArray<T>::operator==(const TemplateDinamicArray& rhs) {
	bool rez(true);
	if (this != &rhs) {
		if (size != rhs.size) {
			rez = false;
		}
		else {
			for (int i = 0; i < size; i += 1) {
				if (data[i] != rhs.data[i]) {
					rez = false;
					break;
				}
			}
		}
	}
	return rez;
}

template<typename T>
bool TemplateDinamicArray<T>::operator!=(const TemplateDinamicArray& rhs) {
	return !(operator==(rhs));
}

template<typename T>
T& TemplateDinamicArray<T>::operator[](int index) {
	if (index >= size && index < 0) {
		throw std::out_of_range("Unncorect index");
	}
	return data[index];
}

template <typename T>
const T& TemplateDinamicArray<T>::operator[](int index) const {
	if (index >= size && index < 0) {
		throw std::out_of_range("Unncorect index");
	}
	return data[index];
}

template<typename T>
TemplateDinamicArray<T>& TemplateDinamicArray<T>::operator=(const TemplateDinamicArray& rhs) {
	if (*this != rhs) {
		if (size != rhs.size) {
			delete[]data;
			size = rhs.size;
			data = new T[size];
		}
		for (int i = 0; i < size; i += 1) {
			data[i] = rhs.data[i];
		}
	}
	return *this;
}

template <typename T>
int TemplateDinamicArray<T>::GetSize() const {
	return size;
}


template <typename T>
void TemplateDinamicArray<T>::resize(int newSize) {
	T* res = new T[size];
	for (int i = 0; i < size; i += 1) {
		res[i] = data[i];
	}
	delete[] data;
	data = new T[newSize];
	for (int i = 0; i < size; i += 1) {
		data[i] = res[i];
	}
	delete[] res;
	size = newSize;
}
#endif // !TEMPLATE_ARRAY_H

