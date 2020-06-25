#include <iostream>

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

void std_test()
{
	std::cout << "Hello!\n";
	std::operator<<(std::cout, "Hello!\n");
}

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

// --------------------------------------------------------------------

int main()
{
	Student::Person Alex;
	study(Alex);
	// study();

	std_test();

	return 0;
}