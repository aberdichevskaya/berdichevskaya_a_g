#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>

struct Rational
{
	Rational() = default;
	explicit Rational(const int numerator);    //denominator,numerator
	Rational(const int numerator, const int denominator);

	int num{ 0 };
	int den{ 0 };
	static const char slash{ '/' };
	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };
	bool operator==(const Rational& rhs)
	{
		return ((double)num / den == (double)rhs.num / rhs.den);
	}
	bool operator!=(const Rational& rhs)
	{
		return !operator==(rhs);
	}
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);
	Rational& operator/=(const Rational& rhs);

	std::ostream& WriteTo(std::ostream& ostrm) const;
	std::istream& ReadFrom(std::istream& istrm);

};

Rational operator+(const Rational lhs, const Rational rhs);
Rational operator-(const Rational lhs, const Rational rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
inline std::istream& operator>>(std::istream& istrm, Rational& rhs);
#endif