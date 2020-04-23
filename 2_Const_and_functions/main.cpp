#include <iostream>

class Dog
{
	int age;
	std::string name;
public:
	Dog() { age = 3; name = "dummy"; }
	void setAge(const int& a) { age = a; }
	const std::string & getName() { return name; }
	void printDogName() const { std::cout << name << " const" << std::endl; }
	void printDogName() { std::cout << getName() << " non-const" << std::endl; }
};

// --------------------------------------------------------------------

int main()
{
	Dog dog;
	dog.printDogName();

	const Dog doggy;
	doggy.printDogName();

	return 0;
}