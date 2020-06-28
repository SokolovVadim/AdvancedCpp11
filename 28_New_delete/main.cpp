#include <iostream>

void* operator new(std::size_t size)/* throw(std::bad_alloc)*/
{
	while(true)
	{
		void* pMem = malloc(size);
		if(pMem)
			return pMem;

		std::new_handler Handler = std::set_new_handler(0); // get new handler
		std::set_new_handler(Handler);

		if(Handler)
			(*Handler)(); // Invoke new handler
		else
			throw std::bad_alloc();
	}
}

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
	virtual ~Dog() {}
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

	Dog* pd1 = new YellowDog();
	delete pd1;
	return 0;
}
