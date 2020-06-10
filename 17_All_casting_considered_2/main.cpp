#include <iostream>
#include <string>

class Dog
{
	std::string m_name;
public:
	Dog():
		m_name("Bob") {}
	void bark() const
	{
		const_cast<Dog*>(this)->m_name = "Henry";
		std::cout << "My name is " << m_name << std::endl;	
	}

};

// --------------------------------------------------------------------

int main()
{
	Dog* pd = new Dog();
	pd->bark();
	return 0;
}