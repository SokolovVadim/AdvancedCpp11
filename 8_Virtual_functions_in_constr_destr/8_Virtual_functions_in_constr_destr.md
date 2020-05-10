# Virtual function in constructor or destructor

```
class Dog
{
public:
	Dog()
	{
		std::cout << "Dog born" << std::endl;
	}
	void bark()
	{
		std::cout << "I'm just a dog" << std::endl;
	}
	void seeCat()
	{
		bark();
	}
};

class YellowDod: public Dog
{
public:
	YellowDod()
	{
		std::cout << "YellowDod born" << std::endl;
	}
	void bark()
	{
		std::cout << "I'm a YellowDod" << std::endl;
	}

};


// --------------------------------------------------------------------

int main()
{
	YellowDod d;
	d.seeCat();
	return 0;
}
```

The dog barks "I'm just a dog", but this dog is yellow ...
To solve this problem it's suitable to use `virtual` keyword

`virtual void bark()`

