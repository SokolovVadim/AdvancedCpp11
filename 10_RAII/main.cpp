#include <iostream>
#include <string>
#include <mutex>

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
};


// --------------------------------------------------------------------

int main()
{
	std::mutex mu;
	Lock my_lock(&mu);
	// Do a bunch of things

	return 0;
}