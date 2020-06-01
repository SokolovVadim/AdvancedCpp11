#include "singleton.hpp"

Dog* Singleton::pd = nullptr;
Cat* Singleton::pc = nullptr;

Dog* Singleton::getDog()
{
	if(!pd)
		pd = new Dog("Lord"); // Initalize upon first usage idiom
	return pd;
}

Cat* Singleton::getCat()
{
	if(!pc)
		pc = new Cat("Nina");
	return pc;
}

Singleton::~Singleton()
{
	if(pd)
		delete pd;
	if(pc)
		delete pc;
	pd = nullptr;
	pd = nullptr;
}
