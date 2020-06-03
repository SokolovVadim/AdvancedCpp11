# Implicit type conversion

## Implicit standart type conversion

```
	char c = 'A';
	int i = c; // Integral promotion
	char* pc = 0; // Null pointer initialization

	void f(int i);
	f(c);

	dog* pd = new yellowdog(); // pointer conversion
```

## Implicit user defined type conversion

### Methods

1. Use constructor that can accept a single parameter -- convert other types of object into your class
2. Use the type conversion function -- convert an object of your class into other types

```
class Dog
{
public:
	Dog(const std::string& name) // no explicit 
	{
		name_ = name;
	}
	// std::string getName() { return name_; }
	operator std::string () const { return name_; }
private:
	std::string name_;
};

// --------------------------------------------------------------------

int main()
{
	Dog dog("Bob");
	std::string dogname = dog;
	std::cout << dogname << std::endl;
	return 0;
}

int main()
{
	std::string dogname = "Bob";
	Dog dog = dogname;
	std::cout << "My name is " << dogname << std::endl;
	return 0;
}
```

## Principles

1. Avoid defining seemingly unexpected conversion
2. Avoid defining two-way implicit conversion

## Implicit type conversion with operators

```
class Rational
{
public:
	Rational(int numerator =  0, int denominator = 1):
		num(numerator),
		den(denominator)
	{}
	const Rational operator*(const Rational& rhs)
	{
		return Rational(num * rhs.num, den * rhs.den);
	}
	operator int() const { return num / den; }
private:
	int num;
	int den;
};
// --------------------------------------------------------------------

int main()
{
	Rational r1 = 20;
	Rational r2 = r1 * 5;
	Rational r3 = 3 * r2;

	return 0;
}
```

This code doesn't work correctly

## Solution:

```
class Rational
{
public:
	Rational(int numerator =  0, int denominator = 1):
		num(numerator),
		den(denominator)
	{}
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
```