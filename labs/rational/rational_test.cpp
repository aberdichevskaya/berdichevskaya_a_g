#include "rational.h"
#include <iostream>
#include<sstream>


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


int main()
{
	using namespace std;

	Rational w;
	w += Rational(1, 1);
	testParse("{5/7}");
	testParse("{5.1/2}");
	testParse("{4/7");
	return 0;
}
