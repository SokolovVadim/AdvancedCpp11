#include <iostream>
#include <string>
#include <vector>

class Rational
{
public:
	Rational(int numerator =  0, int denominator = 1):
		num(numerator),
		den(denominator)
	{}
/*	const Rational operator*(const Rational& rhs)
	{
		return Rational(num * rhs.num, den * rhs.den);
	}
	operator int() const { return num / den; }*/
	friend const Rational operator*(const Rational& rhs, const Rational& lhs);
	int getNum() const { return num; }
	int getDen() const { return den; }
private:
	int num;
	int den;
};

const Rational operator*( const Rational& rhs, const Rational& lhs)
{
	return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

// --------------------------------------------------------------------

int main()
{
	Rational r1 = 20;
	Rational r2 = r1 * 5;
	Rational r3 = 3 * r2;
	std::cout << r3.getNum() << " / " << r3.getDen() << std::endl;
	return 0;
}