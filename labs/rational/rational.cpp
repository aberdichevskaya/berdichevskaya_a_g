#include "rational.h"
#include<iostream>
#include <sstream>

Rational& Rational::operator-=(int rhs) {
return operator-=(Rational(rhs));
}

Rational& Rational::operator *=(int rhs) {
	return operator*=(Rational(rhs));
}

Rational& Rational::operator+=(const int rhs) {
	return operator+= (Rational(rhs));
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.WriteTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.ReadFrom(istrm);
}

Rational::Rational(const int numerator, const int denominator)
	: num(numerator)
	, den(denominator)
{}

Rational::Rational(const int numerator)
	: Rational(numerator, 1)
{}
Rational& Rational::operator+=(const Rational& rhs) {
	num = num * rhs.den + den * rhs.num;
	den = den * rhs.den;
	return *this;
}

Rational operator+(const Rational lhs, const Rational rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational& Rational::operator-=(const Rational& rhs) {
	num = num * rhs.den - den * rhs.num;
	den = den * rhs.den;
	return *this;
}

Rational operator-(const Rational lhs, const Rational rhs) {
	Rational dif(lhs);
	dif -= rhs;
	return dif;
}

Rational& Rational::operator*=(const Rational& rhs) {
	num *= rhs.num;
	den *= rhs.den;
	return *this;
}



Rational& Rational::operator/=(const Rational& rhs) {
	num *= rhs.den;
	den *= rhs.num;
	return *this;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
	ostrm << leftBrace << num << slash << den << rightBrace;
	return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
	char leftBrace(0);
	char slash(0);
	char righrBrace(0);
	int numerator(0);
	int denominator(0);

	istrm >> leftBrace >> numerator >> slash >> denominator >> righrBrace;
	if (istrm.good()) {
		if ((leftBrace == Rational::leftBrace) && (slash == Rational::slash) && (righrBrace == Rational::rightBrace) && (denominator != 0)) {
			num = numerator;
			den = denominator;
		}
	}
	else {
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}
