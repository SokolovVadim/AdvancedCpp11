#include <iostream>

namespace Uni
{
	struct Student {};
	void study(Student)
	{
		std::cout << "calling Uni::study()\n";
	}
}

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

// --------------------------------------------------------------------

int main()
{
	School school;
	school.work();

	Game::Football::kick();
	return 0;
}