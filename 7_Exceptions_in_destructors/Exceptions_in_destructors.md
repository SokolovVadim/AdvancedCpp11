# Exceptions in destructor

## Exceptions in `main()`

```
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
		throw 20;
		henry.bark();
		bob.bark();

	} catch(int e){
		std::cout << e << " is caught" << std::endl;
	}
	return 0;
}
```

## Exception in destructor

```
	~Dog()
	{
		std::cout << m_name << " is destroyed" << std::endl;
		throw 10;
	}
```

## Problem

It will result in terminate call

`terminate called after throwing an instance of 'int'`

Two exceptions pending at the same time

## Solution 1: Destructor swallow the exception

```
	~Dog()
	{
		try{
			std::cout << m_name << " is destroyed" << std::endl;
			throw 10;
		} catch (MYEXCEPTION & e){
			std::cout << e << " is caught" << std::endl;
		} catch (...) {
			// ...
		}

	}
```

## Solution 2: Move the exception-prone code to a different function

```
	void prepareToDestr()
	{
		std::cout << "Preparation ..." << std::endl;
		throw 10;
	}
```

```
	Dog henry("Henry");
	Dog bob("Bob");
	
	henry.bark();
	bob.bark();
	henry.prepareToDestr();
	bob.prepareToDestr();
```

## Handling the exception

 - Dog: 1
 - Dog's client: 2
