#include <iostream>
#include <string>
#include <vector>

class Person
{
public:
	Person(std::string name)
	{
		pName_ = new std::string(name);
	}
	~Person() {
		delete pName_;
	}
	void printName(){
		std::cout << *pName_ << std::endl;
	}
private:
	std::string* pName_;
};


// --------------------------------------------------------------------

int main()
{
	Person kate("Kate");
	kate.printName();

	std::vector<Person*> persons;
	persons.push_back(new Person("Katya"));
	persons.back()->printName();
	return 0;
}