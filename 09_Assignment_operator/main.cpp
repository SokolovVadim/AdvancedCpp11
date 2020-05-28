#include <iostream>
#include <string>

class Collar
{
	std::string name;
};

class Dog
{
	Collar* pcollar;
public:
	Dog()
	{
		pcollar = new Collar;
	}
	Dog& operator=(const Dog& rhs)
	{
		*pcollar = * rhs.pcollar;
		return * this;
	}
};

// --------------------------------------------------------------------

int main()
{
	Dog Ruby;
	Dog Lord;
	Ruby = Ruby;
	return 0;
}