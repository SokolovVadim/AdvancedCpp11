#include <iostream>

class Dog
{
public:
	virtual void bark() = 0;
	void run()
	{
		std::cout << "I'm running\n";
	}
	virtual void eat()
	{
		std::cout << "I'm eating\n";
	}
protected:
	void sleep()
	{
		std::cout << "I'm sleeping\n";
	}
};

class Yellowdog: public Dog{
	public:
		virtual void bark()
		{
			std::cout << "I am a Yellowdog\n";
		}
		void Ysleep()
		{
			sleep();
		}
};

// --------------------------------------------------------------------

int main()
{
	Yellowdog yd;
	yd.bark();
	yd.run();
	yd.eat();
	yd.Ysleep();
	return 0;
}