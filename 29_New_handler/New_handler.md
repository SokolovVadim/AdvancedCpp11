# New handler

## What is new handler?

New handler is a function invoked when oparator new failed to allocate memory. It's purpose is to help memory allocation to succeed.  
`set_new handler()` installs a new handler and returns current new handler

```
void* operator new(std::size_t size) throw(std::bad_alloc)
{
	while(true)
	{
		void * pMem = malloc(size);    // Allocate memory
		if(pMem)
			return pMem;               // Return the memory if successful
		std::new_handler Handler = std::set_new_handler(0);   // Get new handler
		std::set_new_handler(Handler);

		if(Handler)
			(*Handler)();              // Invoke new handler
		else
			throw std::bad_alloc();    // If new handler is Null throw an exception
	}
}

```

## New handler must do one of the following things

1. Make more memory available
2. Install a different new handler
3. Uninstall the new handler (passing a null ptr)
4. Throw an exception bad_alloc
5. Terminate the program

```
int main()
{
	int* pGiant = new int[10000000000000L];
	delete[] pGiant;
	return 0;
}
```

The output is:

```
terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc
[1]    18139 abort (core dumped)  ./build/main
```

Setting new handler:

```
void NoMoreMem()
{
	std::cerr << "Unable to allocate memory, bro\n";
	abort();
}

// --------------------------------------------------------------------

int main()
{
	std::set_new_handler(NoMoreMem);
	int* pGiant = new int[10000000000000L];
	delete[] pGiant;
	return 0;
}
```

The output is:

```
Unable to allocate memory, bro
[1]    18237 abort (core dumped)  ./build/main

```

## Class specific new handler

```
class Dog
{
	int hair[10000000000000L];
	std::new_handler origHandler;
public:
	void NoMoreMemForDog()
	{
		std::cerr << "Unable to allocate memory for Dog\n";
		std::set_new_handler(origHandler);
		throw std::bad_alloc();
	}
	void* operator new(std::size_t size)
	{
		origHandler = std::set_new_handler(NoMoreMemForDog);
		void* pV = ::operator new(size);   // Call global operator new
		std::set_new_handler(origHandler); // Restore old handler
		return pV;
	}

};

// --------------------------------------------------------------------

int main()
{
	std::shared_ptr<Dog> pd(new Dog());
	return 0;
}
```