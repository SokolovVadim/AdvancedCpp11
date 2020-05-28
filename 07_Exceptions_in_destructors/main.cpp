#include <iostream>
#include <string>


class Dog
{
public:
	std::string m_name;
	Dog(std::string name)
	{
		m_name = name;
		std::cout << name << " is born" << std::endl;
	}
	~Dog()
	{
		std::cout << m_name << " is destroyed" << std::endl;
	}
	void prepareToDestr()
	{
		std::cout << "Preparation ..." << std::endl;
		throw 10;
	}
	void bark()
	{
		std::cout << "bark!" << std::endl;
	}
};


// --------------------------------------------------------------------

int main()
{
	try{
		Dog henry("Henry");
		Dog bob("Bob");
		
		henry.bark();
		bob.bark();
		henry.prepareToDestr();
		bob.prepareToDestr();
	} catch(int e){
		std::cout << e << " is caught" << std::endl;
	}
	return 0;
}