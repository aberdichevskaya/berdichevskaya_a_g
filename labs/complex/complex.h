#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <sstream>


struct Complex
{
	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imadginary);
	bool operator==(const Complex& rhs);
	bool operator!=(const Complex& rhs);
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs);
	Complex& operator *=(const double rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };
	static const char separator{ ',' };


};


Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
inline std::istream& operator>>(std::istream& istrm, Complex& rhs);

#endif