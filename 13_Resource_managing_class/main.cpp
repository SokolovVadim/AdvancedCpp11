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
	std::string* pName() const { return pName_; }
	Person* clone(){
		return (new Person(*(pName_)));
	}
private:
	Person(const Person& rhs);
	Person& operator=(const Person& rhs); // Deep Copy
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