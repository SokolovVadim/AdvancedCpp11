# Namespace and keyword "using"

1. using directive:  
to bring all namespace members into current scope.  
Example:

`using namespace std;`

2. using declaration  
a. Bring one specific namespace member to current scope
b. Bring a member from base class to current class' scope  
Example:

```
using std::cout;
cout << "Hello!\n";
```

```
using namespace std; // case 1, global scope
using std::cout;     // case 2.a, global scope

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

	using std::cout; // illegal
	using namespace std; // illegal
};

using B::f; // illegal

// --------------------------------------------------------------------

int main()
{
	B base;
	base.f(1);
	D derived;
	derived.g();
	derived.h();
	derived.my_f();
	return 0;
}
```

1. Using declaration and using directive, when working with namescope, can be used in global or local scope
2. Using declaration can be used class scope, when used on class members

## Shadowing

```
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

// --------------------------------------------------------------------

int main()
{
	YellowDog yd;
	yd.walk();
	yd.walk(10);
	return 0;
}
```

## Anonymous namespace

```
namespace{
	void work()
	{
		std::cout << "just work\n";
	}
}
```
It is almost equal to global static function, but has additional benefits

```
static void h()
{
	...
}
```

Inside namespace function `live()` will call local function `work()` and the output is: "just work".

```
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

int main()
{
	live();
	return 0;
}
```
