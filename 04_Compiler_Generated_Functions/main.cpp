#include <iostream>
#include <string>

class Collar{
public:
	Collar() { std::cout << "collar is born\n"; }
};

class Dog{
	Collar      m_collar;
	std::string m_name;
};

class Cat{
public:
	Cat() = default;
	Cat(std::string name) { std::cout << name << " is born\n"; }
};

// --------------------------------------------------------------------

int main()
{
	Dog dog;
	Cat cat;
	Cat catTom("Tom");
	return 0;
}