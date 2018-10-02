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
	Rational& operator+=(const int rhs)
	{
		return operator+= (Rational(rhs));
	}

	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs)
	{
		return operator-=(Rational(rhs)); //unarnyi minus vnutry ili snaryzshi pisat'?
	}
	
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs)
	{
		return operator*=(Rational(rhs));
	}

	Rational& operator/=(const Rational& rhs);


	std::ostream& WriteTo(std::ostream& ostrm) const;
	std::istream& ReadFrom(std::istream& istrm);




};
Rational operator+(const Rational lhs, const Rational rhs);
Rational operator-(const Rational lhs, const Rational rhs);


inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) 
{
	return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.ReadFrom(istrm);
}

bool testParse(const std::string str)
{
	using namespace std;
	istringstream strm(str);
	Rational w;
	strm >> w;
	if (strm.good())
	{
		cout << "Read succes:" << "<-" << w << endl;
	}
	else
	{
		cout << "Read error:" << "<-" << w << endl;
	}
	return strm.good();
}

//
//int main()
//{
//	using namespace std;
//
//	Rational w;
//	w += Rational(1,1);
//	testParse("{5/7}");
//	testParse("{5.1/2}");
//	testParse("{4/7");
//	return 0;
//}

Rational::Rational(const int numerator, const int denominator)
	:num (numerator)
	, den (denominator)
{}

Rational::Rational(const int numerator)
	: Rational(numerator, 1)
{}
Rational& Rational::operator+=(const Rational& rhs)
{
	num = num * rhs.den + den * rhs.num;
	den = den * rhs.den;
	return *this;
}

Rational operator+(const Rational lhs, const Rational rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num = num * rhs.den - den * rhs.num;
	den = den * rhs.den;
	return *this;
}

Rational operator-(const Rational lhs, const Rational rhs)
{
	Rational dif(lhs);
	dif -= rhs;
	return dif;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	den *= rhs.den;
	return *this;
}



Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.den;
	den *= rhs.num;
	return *this;
}

std::ostream& Rational::WriteTo(std:: ostream& ostrm) const
{
	ostrm << leftBrace << num << slash << den << rightBrace;
	return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm)
{
	char leftBrace(0);
	char slash(0);
	char righrBrace(0);
	int numerator(0);
	int denominator(0);

	istrm >> leftBrace >> numerator >> slash >> denominator >> righrBrace;
	if (istrm.good())
	{
		if ((leftBrace == Rational::leftBrace) && (slash == Rational::slash) && (righrBrace == Rational::rightBrace) && (denominator != 0))
		{
			num = numerator;
			den = denominator;
		}
	}
	else
	{
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}



