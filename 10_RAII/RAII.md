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

## Note 1: smart pointer

```
int function()
{
	std::shared_ptr<Dog> pd(new Dog);
	return 0;
}
```

## Another example

```
class dog;
class Trick;
void train(std::shared_ptr<dog> pd, Trick dogtrick);
Trick getTrick();

int main()
{
	train(std::shared_ptr<dog> pd(new dog()), getTrick());
}
```

Problem: the order of `operator new` and `getTrick()` is up to compiler. If `getTrick` throws an exception, that will cause memory acquisition without assignment.
The solution is to divide operations:

```
int main()
{
	train(std::shared_ptr<dog> pd(new dog());
	train(pd, getTrick());
}
```

## Note 3: Copying of resource management object

```
	Lock my_lock(&mu);
	Lock my_another_lock(my_lock);
```

## Solution 1:

```
Lock(const Lock& lock) = delete;
```

## Solution 2:

Reference count the underlying resource by using `std::shared_ptr`

`template<class Other, class D> shared_ptr(Other* ptr, D deleter);`

The default value for D is `operator delete`

`std::shared_ptr<dog> pd(new dog());`

```
class Lock
{
private:
	std::shared_ptr<std::mutex> p_mutex;
public:
	explicit Lock(std::mutex *pm):
		p_mutex(pm, Mutex_unlock)
	{
		Mutex_lock(pm);
	}
};

Lock L1(&mu);
Lock L2(L1);

```