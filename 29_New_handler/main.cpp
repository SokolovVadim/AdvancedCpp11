#include <iostream>
#include <memory>

void* operator new(std::size_t size)
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

void NoMoreMem()
{
	std::cerr << "Unable to allocate memory, bro\n";
	abort();
}

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
