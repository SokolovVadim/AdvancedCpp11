# Koenig lookup and namespace design

## Example 1: Why Koenig?

```
namespace Student
{
	struct Person {};
	void study(Person )
	{
		std::cout << "calling Person::study(Person)\n";
	}
	void study()
	{
		std::cout << "calling Person::study()\n";
	}
}


// --------------------------------------------------------------------

int main()
{
	Student::Person Alex;
	study(Alex); // Koenig
	study();     // Error!

	return 0;
}
```

## Practical reason

```
void std_test()
{
	std::cout << "Hello!\n"; 
	std::operator<<(std::cout, "Hello!\n");
}
```
Koenig lookup also works here! It makes code cleaner

## Theoretical reason

What is the interface of class?

```
namespace Uni
{
	class Student
	{
	public:
		void study()
		{}
		void sleep()
		{}
	};

	void work(Student);
	std::ostream& operator<<(std::ostream&, const Student&);
}

void work(Uni::Student)
{}
```

`work()` function is supposed to be user-defined function

#### Definition of class:

A class descrives a set of data, along with the functions that operate on that data.

So `Uni::work()` and `operator<<` are parts of Student interface

## Engineering principle

1. Functions that operate on class C and in a same namespace with C are part of C's interface
2. Functions that are part of C's interface should be in the same namespace as C.

```
A::C c;
c.f();
h(c);
```

## Name hiding

```
namespace A
{
	class C {};
}

int operator+(A::C, int n)
{
	return n + 1;
}

int main()
{
	A::C arr[3];
	std::accumulate(arr, arr + 3, 0); // return 3;
}
```

Defined in C++ standart library `<numeric>`

```
namespace std
{
	template <class InputIterator, class T>
	T accumulate(InputIterator first, InputIterator last, T init)
	{
		while(first != last)
			init = init + *first++;
		return init;
	}
}
```

`operator+()` will be hidden by the `std::operator+()`. Solution:  

```
namespace A
{
	class C {};
	int operator+(A::C, int n)
	{
		return n + 1;
	}
}
```

