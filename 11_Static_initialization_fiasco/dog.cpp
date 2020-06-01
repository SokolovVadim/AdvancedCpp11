#include "dog.hpp"

void Dog::bark()
{
	std::cout << "I'm Dog. My name is " << _name << std::endl;
}

Dog::Dog(const std::string& name):
	_name(name)
{
	std::cout << "Constructing Dog " << name << std::endl;
}