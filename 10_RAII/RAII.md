# Resource acquisition is initialization

## Problem

```
Mutex_t mu = MUTEX_INIT;

void lock()
{
	Mutex_lock(&mu);

	// do a bunch of things

	Mutex_unlock(&mu); // this line doesn't have to be executed
}

```

## Solution

```

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

```