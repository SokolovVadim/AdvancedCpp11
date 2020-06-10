# All casting considered 2

## Dynamic cast

```
class Dog
{
	public:
		virtual ~Dog()
		{
			std::cout << "Dog destructed!\n";
		}
};

class YellowDog: public Dog
{
	int age;
public:
	void bark()
	{
		std::cout << "Woof!\n";
	}
};

// --------------------------------------------------------------------

int main()
{
	Dog* pd = new Dog();
	YellowDog* py = dynamic_cast<YellowDog*>(pd);
	py->bark();
	std::cout << "Py = " << py << std::endl;
	std::cout << "Pd = " << pd << std::endl;
	return 0;
}
```

There is a bug in this line:  
`YellowDog* py = dynamic_cast<YellowDog*>(pd);`

The output is:  
```
Woof!
Py = 0
Pd = 0x5575ec28ce70
```

This code compiles because compiler threats function YellowDog::bark() as a static function.  
Let's use data member in YellowDog::bark() function

```
	void bark()
	{
		std::cout << "Woof! I am " << age << std::endl;
	}
```

The output is:  
`[1]    6736 segmentation fault (core dumped)  ./build/main`

Let's use `static_cast<>`:  

`YellowDog* py = static_cast<YellowDog*>(pd);`  

The output is:  
```
Woof! I am 0
Py = 0x55d23786de70
Pd = 0x55d23786de70
```

Bug is hidden. That's why using `static_cast<>` is dangerous  

Pointer to `YellowDog` can be checked:  

```
	YellowDog* py = dynamic_cast<YellowDog*>(pd);
	if(py)
		py->bark();
```

The output is:  

```
Py = 0
Pd = 0x5561078c8e70
```

Instead of casting it's better to use Polymorphism:  

```
	Dog* pd = new Dog();
	pd->bark();
```

## Casting could be a handy hack tool

```
class Dog
{
	std::string m_name;
public:
	Dog():
		m_name("Bob") {}
	void bark() const // *this is const
	{
		const_cast<Dog*>(this)->m_name = "Henry";
		// m_name = "Henry";
		std::cout << "My name is " << m_name << std::endl;	
	}

};

// --------------------------------------------------------------------

int main()
{
	Dog* pd = new Dog();
	pd->bark();
	return 0;
}
```
