#include <iostream>
#include <string>
/*#include "cat.hpp"
#include "dog.hpp"*/
#include "singleton.hpp"

// --------------------------------------------------------------------


int main()
{
	Singleton instance;
	Singleton::getCat()->meow();

	return 0;
}