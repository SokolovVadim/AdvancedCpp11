# Koenig lookup - Argument dependent lookup

## Example1: namespace's scope

```
namespace Uni
{
	struct Student {};
	void study(Student)
	{
		std::cout << "calling Uni::study()\n";
	}
}

// --------------------------------------------------------------------

int main()
{
	Uni::Student Mike;
	Uni::study(Mike);
	return 0;
}
```

However this code will also work fine

```
	Uni::Student Mike;
	study(Mike);
	return 0;
```

It works because compiler searches function also in the scope where the parameter type was defined

```
namespace Uni
{
	struct Student {};
	void study(Student)
	{
		std::cout << "calling Uni::study()\n";
	}
}

void study(Uni::Student)
{

}

// --------------------------------------------------------------------

int main()
{
	Uni::Student Mike;
	study(Mike);
	return 0;
}
```

Function with the same prorotype in a global scope will cause a compilation error

## Example 2: Class' scope

```
class School
{
public:
	struct Teacher {};
	static void teach(Teacher)
	{
		std::cout << "calling School::teach()\n";
	}
};

// --------------------------------------------------------------------

int main()
{
	School::Teacher Missis_Smith;
	School::teach(Missis_Smith);
	return 0;
}
```

Koenig Lookup does not work in class scope! So this code will cause an error.

```

	School::Teacher Missis_Smith;
	teach(Missis_Smith);
	return 0;
```

## Example 3:

```
namespace Uni
{
	struct Student {};
	void study(Student)
	{
		std::cout << "calling Uni::study()\n";
	}
}

namespace School
{
	void study(Uni::Student)
	{
		std::cout << "calling School::study()\n";
	}
	void work()
	{
		Uni::Student Max;
		study(Max);
	}
}

int main()
{
	School::work();
	return 0;
}
```

This code will not compile due to Koenig lookup.

```
class School
{
public:
	void study(Uni::Student)
	{
		std::cout << "calling School::study()\n";
	}
	void work()
	{
		Uni::Student Max;
		study(Max);
	}
};

int main()
{
	School school;
	school.work();
	return 0;
}
```

This code will compile because Koenig lookup does not work in class scope.

```
class Lesson{
public:
	void study(Uni::Student)
	{
		std::cout << "calling Lesson::study()\n";
	}
};

class School: public Lesson
{
public:
	void work()
	{
		Uni::Student Max;
		study(Max);
	}
};
```

The output is:
`calling Lesson::study()`

## Name hiding for namespaces

```
namespace Game
{
	void play(int )
	{
		std::cout << "calling Game::play()\n";
	}
	namespace Football
	{
		void play()
		{
			std::cout << "calling Game::Football::play()\n";
		}
		void kick()
		{
			play(1);
		}
	}
}

// --------------------------------------------------------------------

int main()
{
	School school;
	school.work();

	Game::Football::kick();
	return 0;
}
```

This code will note compile. We can use `using` declaration:

```
void kick()
{
	using Game::play;
	play(1);
}
```

The output is:

`calling Game::play()`

This code will compile also

```
namespace Game
{
	struct Player {};
	void play(Player )
	{
		std::cout << "calling Game::play()\n";
	}
	namespace Football
	{
		void play()
		{
			std::cout << "calling Game::Football::play()\n";
		}
		void kick()
		{
			Player Mikita;
			play(Mikita);
		}
	}
}
```

## Name lookup sequence

With namespaces  
current scope => next enclosed scope => ... => global scope  
To override the sequence:  
1. Qualifier or using declaration
2. Koenig lookup  

With classes:  
current class scope => parent scope => ... => global scope  
To override the sequence:  
- Qualifier or using declaration

Name hiding
