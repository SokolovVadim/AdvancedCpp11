#include <iostream>
#include <vector>

class BigArray{
	std::vector<int> v; // huge array
	int accessCounter;
	int* another_v;
public:
	int getItem(int index) const{
		const_cast<BigArray*>(this)->accessCounter++;
		return v[index];
	}

	void setAnotherVItem(int index, int x)
	{
		*(another_v + index) = x;
	}
	const int* const fun (const int* const & p) const;
};

// --------------------------------------------------------------------

int main()
{
	BigArray array;

	return 0;
}