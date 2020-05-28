#include <iostream>
#include <string>
#include <mutex>
#include <memory>

class Lock
{
private:
	std::mutex * m_pm;
public:
	explicit Lock(std::mutex* pm)
	{
		pm->lock();
		m_pm = pm;
		std::cout << "constructed!\n";
	}
	~Lock()
	{
		m_pm->unlock();
		std::cout << "destructed!\n";
	}
	// Lock(const Lock& lock) = delete;
};

class Dog
{
public:
	Dog()
	{
		std::cout << "Hello! I'm dog!\n";
	}

};

int function()
{
	std::shared_ptr<Dog> pd(new Dog);
	return 0;
}


// --------------------------------------------------------------------

int main()
{
	std::mutex mu;
	Lock my_lock(&mu);
	Lock my_another_lock(my_lock);
	// Do a bunch of things

	function();

	return 0;
}