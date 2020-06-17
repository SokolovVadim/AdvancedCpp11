#include <iostream>
#include <string>

class Dog{
public:
	void bark(int age)
	{
		std::cout << "I'm " << age << " years old\n";
	}
	virtual void bark(std::string msg = "just a")
	{
		std::cout << "I'm " << msg << " dog\n";
	}
};

class YellowDog: public Dog
{
public:
	using Dog::bark;
	virtual void bark(std::string msg = "a YellowDog")
	{
		std::cout << "I'm " << msg << " dog\n";
	}
};


// --------------------------------------------------------------------

int main()
{
	YellowDog* py = new YellowDog();
	py->bark(5);
	return 0;
}