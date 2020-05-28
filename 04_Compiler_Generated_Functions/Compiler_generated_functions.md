# Compiler generated functions

This class

`class Dog {};`

is equal to

```
class Dog{
public:
	Dog(const Dog& rhs) { ... }; // Member by member initialization
	Dog & operator=(const Dog& rhs) { ... }; // Member by member copying
	Dog() { ... };  // 1. Call base class's default constructor;
					// 2. Call data member's default constructor.
	~Dog() { ... }; // 1. Call base class's destructor;
					// 2. Call daat member's destructor.
}
```

## Compiler generated functions
1. Public and inline
2. Generated only if they are needed.

## Example

1. Copy constructor - no
2. Copy assignment operator - yes
3. Destructor - no
4. Default constructor - no

```
class Dog{
public:
	std::string m_name;

	Dog(std::string name = "Bob")
	{
		m_name = name;
		std::cout << name << " is born.\n";
	}
	~Dog()
	{
		std::cout << m_name << " is destroyed.\n";
	}
};
```
## Notes

If we suppose in previous example that `m_name` is a reference

`std::string & m_name;`

That won't be compiled because reference is only to be initialized and can't be copied. Thus this kind of class can't be used with stl containers.

## Example 2

This code will not compile

```
class Collar{
public:
	Collar(std::string color) { std::cout << "collar is born\n"; }
};

class Dog{
	Collar m_collar;
};

int main()
{
	Dog dog;
	return 0;
}
```

Removing the parameter in constructor will correct the problem:

`Collar(std::string color) { std::cout << "collar is born\n"; }`

Reference can't be initialized by the default contructor so this code will not compile

```
class Dog{
	Collar        m_collar;
	std::string & m_name;
};
```

## C++ 11 Update of default constructor

```
class Cat{
public:
	Cat() = default;
	Cat(std::string name) { std::cout << name << " is born\n"; }
};

int main()
{
	Dog dog;
	Cat cat;
	Cat catTom("Tom");
	return 0;
}
```

