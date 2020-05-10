#include <iostream>
#include <string>


class Dog
{
public:
	Dog()
	{
		std::cout << "Dog born" << std::endl;
		bark();
	}
	virtual void bark()
	{
		std::cout << "I'm just a dog" << std::endl;
	}
	void seeCat()
	{
		bark();
	}
};

class YellowDod: public Dog
{
public:
	YellowDod()
	{
		std::cout << "YellowDod born" << std::endl;
	}
	virtual void bark()
	{
		std::cout << "I'm a YellowDod" << std::endl;
	}

};


// --------------------------------------------------------------------

int main()
{
	YellowDod d;
	d.seeCat();
	return 0;
}