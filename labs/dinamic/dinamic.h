#ifndef  DINAMIC_H
#define DINAMIC_H

class Dinamic_array {
private:
	int size_{ 0 };
	double* data_{ nullptr };
public:
	Dinamic_array() = default;
	Dinamic_array(const Dinamic_array& data);
	Dinamic_array(const int size);
	Dinamic_array& operator =(const Dinamic_array& rhs);
	~Dinamic_array();
	int GetSize() const;
	const double& operator[] (int i) const;
	double& operator[](int i);
	bool operator==(const Dinamic_array& rhs);
	bool operator!=(const Dinamic_array& rhs);
};

#endif 
