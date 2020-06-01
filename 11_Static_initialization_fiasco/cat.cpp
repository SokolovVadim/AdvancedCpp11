#include "cat.hpp"


void Cat::meow()
{
	std::cout << "I'm cat. My name is " << _name << std::endl;
}
Cat::Cat(const std::string& name):
	_name(name)
{
	std::cout << "Constructing Cat " << name << std::endl;
}