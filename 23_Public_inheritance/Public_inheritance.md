# Duality of public inheritance

## Duality

1. Inheritance of interface
2. Inheritance of implementation

## Inheritance of interface

```
class Dog
{
public:
	virtual void bark() = 0;
};

class Yellowdog: public Dog{
	public:
		virtual void bark()
		{
			std::cout << "I am a Yellowdog\n";
		}
};

// --------------------------------------------------------------------

int main()
{
	Yellowdog yd;
	yd.bark();
	return 0;
}
```

## Inheritance of implementation and interface

```
class Dog
{
public:
	virtual void bark() = 0;
	void run()
	{
		std::cout << "I'm running\n";
	}
};

class Yellowdog: public Dog{
	public:
		virtual void bark()
		{
			std::cout << "I am a Yellowdog\n";
		}
};

// --------------------------------------------------------------------

int main()
{
	Yellowdog yd;
	yd.bark();
	yd.run();
	return 0;
}
```

```
class Dog
{
public:
	virtual void bark() = 0;
	void run()
	{
		std::cout << "I'm running\n";
	}
	virtual void eat()
	{
		std::cout << "I'm eating\n";
	}
protected:
	void sleep()
	{
		std::cout << "I'm sleeping\n";
	}
};

class Yellowdog: public Dog{
	public:
		virtual void bark()
		{
			std::cout << "I am a Yellowdog\n";
		}
		void Ysleep()
		{
			sleep();
		}
};

// --------------------------------------------------------------------

int main()
{
	Yellowdog yd;
	yd.bark();
	yd.run();
	yd.eat();
	yd.Ysleep();
	return 0;
}
```

## Types of inheritance in C++

1. Pure virtual function -- inherits interface only
2. Non-virtual public function -- inherits both interface and implementation
3. Impure virtual function -- inherits interface and default implementation
4. Protected function -- inherits implementation only

Separate the concepts of inheritance and implementation

## Interface Inheritance

1. Subtyping
2. Polymorphism

`virtual void bark() = 0;`

Pitfalls: 
1. Be careful of interface bloat
2. Interfaces do not reveal implementation

## implementation inheritance

1. Increase code complexity
2. Not encouraged

```
public:
	void run() { ... }
	virtual void eat() { ... }
protected:
	void sleep() { ... }
```

## Guidelines for implementation inheritance

1. Do not use inheritance for code reuse, use composition.
2. Minimize the implementation in base classes. Base classes should be thin.
3. Minimize the level of hierarchies in implementation inheritance.

## Is inheritance evel?

Inheritance is often useful, but more often overused
