# Virtual destructor

## Factory pattern

```
class Dog
{
public:
	~Dog() { std::cout << "Dog destroyed!" << std::endl; }
};

class YellowDog: public Dog{
public:
	~YellowDog() { std::cout << "Yellow dog destroyed!" << std::endl; }
};

class DogFactory{
public:
	static Dog* createYellowDog()
	{
		return (new YellowDog());
	}
	// create other dogs
};

// --------------------------------------------------------------------

int main()
{
	Dog* pd = DogFactory::createYellowDog();
	// Do smth with pd
	delete pd;
	return 0;
}
```

The output is supposed to be `Dog destroyed!`

## Virtual destructor

`virtual ~Dog() { std::cout << "Dog destroyed!" << std::endl; }`

The output is 

```
Yellow dog destroyed!
Dog destroyed!
```

## Shared pointer

```
class Dog
{
public:
	~Dog() { std::cout << "Dog destroyed!" << std::endl; }
};

class YellowDog: public Dog{
public:
	~YellowDog() { std::cout << "Yellow dog destroyed!" << std::endl; }
};

class DogFactory{
public:
	static std::shared_ptr<Dog> createYellowDog()
	{
		return std::shared_ptr<YellowDog>(new YellowDog());
	}
	// create other dogs
};

// --------------------------------------------------------------------

int main()
{
	std::shared_ptr<Dog> pd = DogFactory::createYellowDog();
	// Do smth with pd
	return 0;
}
```

The output is 

```
Yellow dog destroyed!
Dog destroyed!
```
