#include <iostream>
#include <sstream>


struct Complex
{
	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imadginary);
	bool operator==(const Complex& rhs)
		{
		return (re == rhs.re) && (im == rhs.im);
		}
	bool operator!=(const Complex& rhs)
	{
		return !operator==(rhs);
	}
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs)
	{
		return operator+=(Complex(rhs));
	}
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs)
	{
		return operator-=(Complex(rhs));
	}
	//Complex& operator *=(const Complex& rhs);
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

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read succes:" << str << "->" << z << endl;
	}
	else
	{
		cout << "Read error:" << str << "<-" << z << endl;
	}
	return istrm.good();
}

int main()
{
	using namespace std;

	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	return 0;
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{}

Complex ::Complex(const double real)
	: Complex(real, 0.0)
{}


Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)  // why don't need &?
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}
 

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs)  // why don't need &?
{
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	char rightBrace(0);
	char comma(0);
	double real(0.0);
	double immaginary(0.0);
	istrm >> leftBrace >> real >> comma >> immaginary >> rightBrace;
	if (istrm.good())
	{
		if ((leftBrace == Complex::leftBrace) && (rightBrace == Complex::rightBrace) && (comma == Complex ::separator))
		{
			re = real;
			im = immaginary;
		}
	}
	else
	{
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}
