#include<iostream>
#include<sstream>

#include "complex.h"

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{}

Complex::Complex(const double real)
	: Complex(real, 0.0)
{}


bool Complex::operator==(const Complex& rhs) {
	return (((re - rhs.re) <= 10e-6) && ((im - rhs.im) <= 10e-6));
}

bool Complex::operator!=(const Complex& rhs) {
	return !operator==(rhs);
}

Complex& Complex::operator+=(const double rhs) {
	return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const double rhs) {
	return operator-=(Complex(rhs));
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}

Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*=(const double rhs) {
	re *= rhs;
	im *= rhs;
	return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
	char leftBrace(0);
	char rightBrace(0);
	char comma(0);
	double real(0.0);
	double immaginary(0.0);
	istrm >> leftBrace >> real >> comma >> immaginary >> rightBrace;
	if (istrm.good()) {
		if ((leftBrace == Complex::leftBrace) && (rightBrace == Complex::rightBrace) && (comma == Complex::separator)) {
			re = real;
			im = immaginary;
		}
	}
	else {
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}
