#include <iostream>

class Dog {};

class Dog{
public:
	Dog(const Dog& rhs) { ... }; // Member by member initialization
	Dog & operator=(const Dog& rhs) { ... }; // Member by member copying
	Dog() { ... };  // 1. Call base class's default constructor;
					// 2. Call data member's default constructor.
	~Dog() { ... }; // 1. Call base class's destructor;
					// 2. Call daat member's destructor.
}


// --------------------------------------------------------------------

int main()
{
	

	return 0;
}