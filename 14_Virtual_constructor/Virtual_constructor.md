# Virtual constructor

## Copy constructing problem

```
class Dog{
};

class Yellowdog: public Dog{
};

void function(Dog* dog) // dog is a Yellowdog
{
	// clone is a Dog
	Dog* clone = new Dog(*dog); // copy-constructed
	std::cout << "Playing with dog ..." << std::endl;
}

// --------------------------------------------------------------------

int main()
{
	Yellowdog dog;
	function(&dog);
	return 0;
}
```

## Solution: virtual clone and co-variant return type

```
class Dog{
public:
	virtual Dog* clone()
	{
		return (new Dog(*this));
	}
};

class Yellowdog: public Dog{
	Yellowdog* clone() override
	{
		return (new Yellowdog(*this));
	}
};

void function(Dog* dog) // dog is a Yellowdog
{
	Dog* clone = dog->clone(); // clone is a Yellowdog
	std::cout << "Playing with dog ..." << std::endl;
}
```