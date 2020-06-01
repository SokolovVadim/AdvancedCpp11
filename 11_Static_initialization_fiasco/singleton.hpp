#include "dog.hpp"
#include "cat.hpp"
class Singleton
{
	static Dog* pd;
	static Cat* pc;
public:
	~Singleton();

	static Dog* getDog();
	static Cat* getCat();
};