#include <iostream>
#include <string>

class OpenFile
{
public:
	OpenFile(std::string filename)
	{
		std::cout << "Open a file " << filename << std::endl;
	}
	void destroyMe() { delete this; }
private:
	~OpenFile() { std::cout << "File destructed!" << std::endl; };
};

// --------------------------------------------------------------------

int main()
{
	OpenFile* f = new OpenFile(std::string("Vadim_file"));
	f->destroyMe();
	return 0;
}