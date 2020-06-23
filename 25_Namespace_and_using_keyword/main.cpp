#include <iostream>

class B
{
public:
	void f(int a)
	{
		std::cout << "F\n";
	}
};

class D: private B
{
public:
	void g()
	{
		using namespace std; // case 1, local scope
		cout << "From D\n";
	}
	void h()
	{
		using std::cout; // case 2.a, local scope
		cout << "From D\n";
	}
	using B::f; // case 2.b, class scope
	void my_f()
	{
		f(1);
	}
};

class Dog
{
public:
	void walk(int time)
	{
		std::cout << "Walking with dog for " << time << " minutes\n";
	}
};

class YellowDog: public Dog
{
public:
	using Dog::walk;
	void walk()
	{
		std::cout << "Walking with YellowDog\n";
	}
};

void work()
{

}

namespace{
	void work()
	{
		std::cout << "just work\n";
	}
	void live()
	{
		work();
	}
}

// --------------------------------------------------------------------

int main()
{
	B base;
	base.f(1);
	D derived;
	derived.g();
	derived.h();
	derived.my_f();

	YellowDog yd;
	yd.walk();
	yd.walk(10);

	live();
	return 0;
}