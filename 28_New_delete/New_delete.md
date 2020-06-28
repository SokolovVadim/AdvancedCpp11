# New and delete

## What happens when folowwing code is executed?

`Dog* pd = new Dog();`

1. Operator new is called to allocate memory
2. Dog's constructor is called to create Dog
3. If step 2 throws an exception, call operator delete to free the memoey allocated in step 1

`delete pd;`

1. Dog's destructor is called
2. Operator delete is called to free the memory

New handler is a function invoked when operator new failed to allocate memory.  
`set_new_handler()` installs a new handler and returns current new handler.

## Global operator new

```
void* operator new(std::size_t size)/* throw(std::bad_alloc)*/
{
	while(true)
	{
		void* pMem = malloc(size);                          // allocate memory
		if(pMem)
			return pMem;                                    // return memory

		std::new_handler Handler = std::set_new_handler(0); // get new handler
		std::set_new_handler(Handler);

		if(Handler)
			(*Handler)();                                   // Invoke new handler
		else
			throw std::bad_alloc();
	}
}

// --------------------------------------------------------------------

int main()
{
	int* ptr = (int*)operator new(10);
	delete ptr;
	return 0;
}
```

## Member operator new

```
class Dog
{
	...
	public:
	static void* operator new(std::size_t size) throw(std::bad_alloc)
	{
		customNewForDog(size);
	}
	...
};

class YellowDog: public Dog
{
	int age;
};

int main()
{
	YellowDog* py = new YellowDog();
	return 0;
}
```

In `main()` function Dog's operator new will be called.

First solution: default operator new;

```
	static void* operator new(std::size_t size) throw(std::bad_alloc)
	{
		if(size == sizeof(dog))
			customNewForDog(size);
		else
			::operator new(size);
	}
```

Second solution: define operator new for YellowDog too

```
class YellowDog: public Dog
{
	int age;
	public:
	static void* operator new(std::size_t size) throw(std::bad_alloc)
	{
		... 
	}
};
```

## Operator delete

```
class Dog
{
	static void customDeleteForDog()
	{}
public:
	static void operator delete(void* pMemory) throw()
	{
		std::cout << "I'm deleting a dog\n";
		customDeleteForDog();
		free(pMemory);
	}
};

class YellowDog: public Dog
{
	static void customDeleteForYellowDog()
	{}
public:
	static void operator delete(void* pMemory) throw()
	{
		std::cout << "I'm deleting a YellowDog\n";
		customDeleteForYellowDog();
		free(pMemory);
	}
};


// --------------------------------------------------------------------

int main()
{
/*	int* ptr = (int*)operator new(10);
	delete ptr;*/

	Dog* pd = new Dog();
	delete pd;
	YellowDog* yd = new YellowDog();
	delete yd;
	return 0;
}
```

This code will cause an error:

```
	Dog* pd1 = new YellowDog();
	delete pd1;
```

`virtual` keyword can not be used with static specificator. Because of that it is crucial to define `virtual destructor` for Dog class:

```
class Dog
{
	static void customDeleteForDog()
	{}
public:
	static void operator delete(void* pMemory) throw()
	{
		std::cout << "I'm deleting a dog\n";
		customDeleteForDog();
		free(pMemory);
	}
	virtual ~Dog();
};
```

## Why do we want to customize new / delete?

1. Usage error detection:
- Memory leak detection / garbage collection
- Array index overrun / underrun
2. Improve efficiency:
- Clustering related objects to reduce page fault
- Fixed size allocation (good for application with many small objects)
- Align similar size objects to same places to reduce fragmentation
3. Perform additional tasks:
- Fill the deallocated memory with zeros -- security
- Collect usage statistics

## Writing a good memory manager is hard

Before writing own version of new / delete, consider:

1. Tweak your compiler toward your needs
2. Search for memory management library, e.g. Pool library from Boost