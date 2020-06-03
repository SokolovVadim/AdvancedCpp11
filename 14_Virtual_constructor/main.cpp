#include <iostream>
#include <string>
#include <vector>

class Dog{
public:
	// co-variant return type
	virtual Dog* clone()
	{
		return (new Dog(*this));
	}
};

class Yellowdog: public Dog{
	Yellowdog* clone() override
	{
		return (new Yellowdog(*this));
	}
};

void function(Dog* dog) // dog is a Yellowdog
{
	// clone is a Dog
	// Dog* clone = new Dog(*dog); // copy-constructed
	Dog* clone = dog->clone(); // clone is a Yellowdog
	std::cout << "Playing with dog ..." << std::endl;
}

// --------------------------------------------------------------------

int main()
{
	Yellowdog dog;
	function(&dog);
	return 0;
}