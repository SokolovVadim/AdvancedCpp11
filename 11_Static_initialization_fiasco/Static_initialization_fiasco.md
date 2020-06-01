# Static initialization fiasco

## main.cpp

```
	dog.bark();
```

## dog.cpp

```
void Dog::bark()
{
	std::cout << "I'm Dog. My name is " << _name << std::endl;
}

Cat cat("Tom");

Dog::Dog(const std::string& name):
	_name(name)
{
	cat.meow();
	std::cout << "Constructing Dog " << name << std::endl;
}
```

## cat.cpp

```
void Cat::meow()
{
	std::cout << "I'm cat. My name is " << _name << std::endl;
}
Cat::Cat(const std::string& name):
	_name(name)
{
	std::cout << "Constructing Cat " << name << std::endl;
}
```

## Undefined behaviour

Shell output:

```
I'm cat. My name is 
Constructing Dog Pablo
Constructing Cat Tom
I'm Dog. My name is Pablo
```

## Solution: Singleton design pattern

```
class Singleton
{
	static Dog* pd;
	static Cat* pc;
public:
	~Singleton();

	static Dog* getDog();
	static Cat* getCat();
};

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


int main()
{
	Singleton instance;
	Singleton::getCat()->meow();

	return 0;
}

```