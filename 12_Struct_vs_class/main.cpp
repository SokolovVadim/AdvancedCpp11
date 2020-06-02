#include <iostream>
#include <string>

struct Person_t
{
	std::string name; // public
	unsigned age;
};

class Person
{
	std::string name_; // private
	unsigned age_;
public:
	unsigned age() const { return age_; }      // getter or accessor
	void set_age(unsigned age) { age_ = age; } // settor or mutator
};


// --------------------------------------------------------------------

int main()
{
	Person_t Nina;
	std::cout << Nina.age;

	Person Paul;
	Paul.set_age(21);
	std::cout << Paul.age();
	return 0;
}