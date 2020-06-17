# Public inheritance

## "Is-a" relationship

```
class Bird {
public:
	void fly()
	{
		
	}
};

class Penguin: public Bird {};

// --------------------------------------------------------------------

int main()
{
	Penguin p;
	p.fly();
	return 0;
}
```

The error occured because penguins can't fly. To solve this error we should define a new class `FlyableBird`.

```
class Bird {};

class FlyableBird: public Bird {
	public:
	void fly()
	{

	}
};

class Penguin: public Bird {};

// --------------------------------------------------------------------

int main()
{
	Penguin p;
	return 0;
}
```

## Virtual functions

```
class Dog{
public:
	void bark()
	{
		std::cout << "I'm just a dog\n";
	}
};

class YellowDog: public Dog
{
public:
	void bark()
	{
		std::cout << "I'm a YellowDog\n";
	}
};


// --------------------------------------------------------------------

int main()
{
	YellowDog* py = new YellowDog();
	py->bark();
	Dog* pd = py;
	pd->bark();
	return 0;
}
```

The output is:

```
I'm a YellowDog
I'm just a dog
```

Function `bark()` should be a virtual function here.

## Another example with virtual functions

```
class Dog{
public:
	virtual void bark(std::string msg = "just a")
	{
		std::cout << "I'm " << msg << " dog\n";
	}
};

class YellowDog: public Dog
{
public:
	virtual void bark(std::string msg = "a YellowDog")
	{
		std::cout << "I'm " << msg << " dog\n";
	}
};


// --------------------------------------------------------------------

int main()
{
	YellowDog* py = new YellowDog();
	py->bark();
	Dog* pd = py;
	pd->bark();
	return 0;
}
```

The output is completely the same:

```
I'm a YellowDog dog
I'm just a dog
```

Never overwrite the default parameter value for virtual functions.

## Non-virtual function in base class

```
class Dog{
public:
	void bark(int age)
	{
		std::cout << "I'm " << age << " years old\n";
	}
	virtual void bark(std::string msg = "just a")
	{
		std::cout << "I'm " << msg << " dog\n";
	}
};

class YellowDog: public Dog
{
public:
	virtual void bark(std::string msg = "a YellowDog")
	{
		std::cout << "I'm " << msg << " dog\n";
	}
};


// --------------------------------------------------------------------

int main()
{
	YellowDog* py = new YellowDog();
	py->bark(5);
	return 0;
}
```

This code won't even compile. Compiler can't find `bark()` function with integer parameter. That's why compilation fails.

The solution is to declare `using` interface.

```
class YellowDog: public Dog
{
public:
	using Dog::bark;
	virtual void bark(std::string msg = "a YellowDog")
	{
		std::cout << "I'm " << msg << " dog\n";
	}
};
```

And this code works fine:

`I'm 5 years old`

## Summary

1. Precise definition of classes;
2. Don't override non-virtual functions;
3. Don't override default parameter values for virtual functions;
4. Force inheritance of shadowed functions.