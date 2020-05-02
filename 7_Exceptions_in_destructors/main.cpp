#include <iostream>
#include <string>
#include <memory>

class Dog
{
public:
	~Dog() { std::cout << "Dog destroyed!" << std::endl; }
};

class YellowDog: public Dog{
public:
	~YellowDog() { std::cout << "Yellow dog destroyed!" << std::endl; }
};

class DogFactory{
public:
	static std::shared_ptr<Dog> createYellowDog()
	{
		return std::shared_ptr<YellowDog>(new YellowDog());
	}
	// create other dogs
};

// --------------------------------------------------------------------

int main()
{
	std::shared_ptr<Dog> pd = DogFactory::createYellowDog();
	// Do smth with pd
	return 0;
}