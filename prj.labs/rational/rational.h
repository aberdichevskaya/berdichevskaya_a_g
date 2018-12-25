#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>

class Rational {
private:
	int num{ 0 };
	int den{ 1 };
	static const char slash{ '/' };
	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };

public:
	Rational() = default;
	explicit Rational(const int numerator);    
	Rational(const int numerator, const int denominator);
	bool operator==(const Rational& rhs);
	bool operator!=(const Rational& rhs);
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);
	Rational& operator/=(const Rational& rhs);

	std::ostream& WriteTo(std::ostream& ostrm) const;
	std::istream& ReadFrom(std::istream& istrm);

	int gcd(int n, int d);
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);


#endif
