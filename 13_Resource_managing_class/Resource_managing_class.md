# Resource managing class

## Shallow copy
```
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

	std::vector<Person> persons;
	persons.push_back(Person("Katya"));
	persons.back().printName();
	return 0;
}
```
1. Kate is constructed
2. A copy of Kate is saved in the vector persons
3. Kate is destroyed

It leads to having an access to deleted object

## Solution 1: Deep Copy

```
	Person(const Person& rhs)
	{
		pName_ = new std::string(*(rhs.pName()));
	}

	Person& operator=(const Person& rhs); // Deep Copy

	std::string* pName() const { return pName_; }
```
## Solution 2: Delete copy constructor and copy assignment operator

```
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
private:
	Person(const Person& rhs);
	Person& operator=(const Person& rhs); // Deep Copy
	std::string* pName_;
};
```

## And define `clone()`

```
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
```