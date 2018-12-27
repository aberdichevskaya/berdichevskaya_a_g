#include<iostream>
#include <sstream>

#include "rational.h"

int Rational::gcd(int n, int d) {
	n = abs(n);
	d = abs(d);
	while ((n != 0) && (d != 0)) {
		if (d >= n) {
			d %= n;
		}
		else {
			n %= d;
		}
	}
	if (n == 0) {
		return d;
	}
	else {
		return n;
	}
}

void Rational::minus() {
	if (den < 0) {
		den = abs(den);
		num *= -1;
	}
}

bool Rational::operator==(const Rational& rhs) {
	return ((num == rhs.num) && (den == rhs.den));
}

bool Rational::operator!=(const Rational& rhs) {
	return !operator==(rhs);
}

Rational& Rational::operator-=(int rhs){
return operator-=(Rational(rhs));
}

Rational& Rational::operator *=(int rhs) {
	return operator*=(Rational(rhs));
}

Rational& Rational::operator+=(const int rhs) {
	return operator+= (Rational(rhs));
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.WriteTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.ReadFrom(istrm);
}

Rational::Rational(const int numerator, const int denominator)
	: num(numerator)
	, den(denominator) {
	if (den == 0) {
		throw std::out_of_range("Division by zero");
	}
	else {
		int nod = gcd(num, den);
		num /= nod;
		den /= nod;
		minus();
	}
}

Rational::Rational(const int numerator)
	: Rational(numerator, 1)
{}

Rational& Rational::operator+=(const Rational& rhs) {
	if (((num != 0) && (den != 0)) || ((rhs.num != 0) && (rhs.den != 0))) {
		num = num * rhs.den + den * rhs.num;
		den = den * rhs.den;
		int nod = gcd(num, den);
		num /= nod;
		den /= nod;
	}
	else if (((num == 0) && (den == 0))) {
		num = rhs.num;
		den = rhs.den;
	}
	minus();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational& Rational::operator-=(const Rational& rhs) {
	num = num * rhs.den - den * rhs.num;
	den = den * rhs.den;
	int nod = gcd(num, den);
	num /= nod;
	den /= nod;
	minus();
	return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational dif(lhs);
	dif -= rhs;
	return dif;
}

Rational& Rational::operator*=(const Rational& rhs) {
	num *= rhs.num;
	den *= rhs.den;
	int nod = gcd(num, den);
	num /= nod;
	den /= nod;
	minus();
	return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational w(lhs);
	w *= rhs;
	return w;
}

Rational& Rational::operator/=(const Rational& rhs) {
	num *= rhs.den;
	den *= rhs.num;
	int nod = gcd(num, den);
	num /= nod;
	den /= nod;
	minus();
	return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational w(lhs);
	w /= rhs;
	return w;
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
		if ((leftBrace == Rational::leftBrace) && (slash == Rational::slash) && (righrBrace == Rational::rightBrace)) {
			if (denominator == 0) {
				throw std::out_of_range("Division by zero");
			}
			else {
				num = numerator;
				den = denominator;
				
				int nod = gcd(num, den);
				num /= nod;
				den /= nod;
				minus();
			}
		}
	}
	else {
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}
